/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "dowonkang.h"
#include "muse.h"

enum {
    // clang-format off
    LEFT_THUMB_LEFT,
    RIGHT_THUMB_RIGHT
    // clang-format on
};

void ltl_finished(qk_tap_dance_state_t *state, void *user_data);
void ltl_reset(qk_tap_dance_state_t *state, void *user_data);
void rtr_finished(qk_tap_dance_state_t *state, void *user_data);
void rtr_reset(qk_tap_dance_state_t *state, void *user_data);

// Aliases
#define LTH LOW
#define LTL TD(LEFT_THUMB_LEFT)
#define LTR CTL_TAB
#define RTH RSE
#define RTL CTL_SPC
#define RTR TD(RIGHT_THUMB_RIGHT)

// clang-format off
#define ______ADJUST_RIGHT_1________ XXXXXXX, MUV_IN , XXXXXXX, XXXXXXX, XXXXXXX
#define ______ADJUST_RIGHT_2________ MU_ON  , MU_MOD , AU_ON  , MI_ON  , XXXXXXX
#define ______ADJUST_RIGHT_3________ MU_OFF , MUV_DE , AU_OFF , MI_OFF , XXXXXXX
// clang-format on

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        MUTE, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______BASE_LEFT_1___________, XXXX, XXXX, ______BASE_RIGHT_1__________,
        ______BASE_LEFT_2___________, XXXX, XXXX, ______BASE_RIGHT_2__________,
        ______BASE_LEFT_3___________, XXXX, XXXX, ______BASE_RIGHT_3__________,
        XXXX, XXXX, LTL , LTH , LTR ,    XXXX,    RTL , RTH , RTR , XXXX, XXXX
    ),

    [_LOWER] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______LOWER_LEFT_1__________, XXXX, XXXX, ______LOWER_RIGHT_1_________,
        ______LOWER_LEFT_2__________, XXXX, XXXX, ______LOWER_RIGHT_2_________,
        ______LOWER_LEFT_3__________, XXXX, XXXX, ______LOWER_RIGHT_3_________,
        XXXX, XXXX, XXXX, ____, XXXX,    XXXX,    ____, ____, BSPC, XXXX, XXXX
    ),

    [_RAISE] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______RAISE_LEFT_1__________, XXXX, XXXX, ______RAISE_RIGHT_1_________,
        ______RAISE_LEFT_2__________, XXXX, XXXX, ______RAISE_RIGHT_2_________,
        ______RAISE_LEFT_3__________, XXXX, XXXX, ______RAISE_RIGHT_3_________,
        XXXX, XXXX, ____, ____, ____,    XXXX,    XXXX, ____, XXXX, XXXX, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______NUMPAD_LEFT_1_________, XXXX, XXXX, ______NUMPAD_RIGHT_1________,
        ______NUMPAD_LEFT_2_________, XXXX, XXXX, ______NUMPAD_RIGHT_2________,
        ______NUMPAD_LEFT_3_________, XXXX, XXXX, ______NUMPAD_RIGHT_3________,
        XXXX, XXXX, ____, ____, XXXX,    XXXX,    SPC , P0  , PDOT, XXXX, XXXX
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______FN_LEFT_1_____________, XXXX, XXXX, ______FN_RIGHT_1____________,
        ______FN_LEFT_2_____________, XXXX, XXXX, ______FN_RIGHT_2____________,
        ______FN_LEFT_3_____________, XXXX, XXXX, ______FN_RIGHT_3____________,
        XXXX, XXXX, ____, ____, ____,    XXXX,    XXXX, XXXX, ____, XXXX, XXXX
    ),

    [_MOUSE] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______MOUSE_WHEEL_1_________, XXXX, XXXX, ______MOUSE_CURSOR_1________,
        ______MOUSE_WHEEL_2_________, XXXX, XXXX, ______MOUSE_CURSOR_2________,
        SFTL, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, XXXX, ACL0, ACL1, ACL2, XXXX,
        XXXX, XXXX, ALT , GUI , CTRL,    XXXX,    BTN3, BTN1, BTN2, XXXX, XXXX
    ),

    [_ADJUST] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______FN_LEFT_1_____________, XXXX, XXXX, ______ADJUST_RIGHT_1________,
        ______FN_LEFT_2_____________, XXXX, XXXX, ______ADJUST_RIGHT_2________,
        ______FN_LEFT_3_____________, XXXX, XXXX, ______ADJUST_RIGHT_3________,
        XXXX, XXXX, XXXX, ____, XXXX,    XXXX,    XXXX, ____, XXXX, XXXX, XXXX
    ),
    // clang-format on
};

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RSE:
        case LOW:
            return false;
        default:
            return true;
    }
}

// Let's DANCE!
static tap ltl_tap_state = {.is_press_action = true, .state = 0};

void ltl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ltl_tap_state.state = cur_dance(state);
    switch (ltl_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code(KC_ESCAPE);
            break;
        case DOUBLE_HOLD:
            layer_on(_NUMPAD);
            break;
        default:
            break;
    }
}

void ltl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ltl_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_ESCAPE);
            break;
        case DOUBLE_HOLD:
            layer_off(_NUMPAD);
            break;
        default:
            break;
    }
    ltl_tap_state.state = 0;
}

static tap rtr_tap_state = {.is_press_action = true, .state = 0};

void rtr_finished(qk_tap_dance_state_t *state, void *user_data) {
    rtr_tap_state.state = cur_dance(state);
    switch (rtr_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code(KC_BSPACE);
            break;
        case DOUBLE_HOLD:
            layer_on(_FUNCTION);
            break;
        default:
            break;
    }
}

void rtr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (rtr_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_BSPACE);
            break;
        case DOUBLE_HOLD:
            layer_off(_FUNCTION);
            break;
        default:
            break;
    }
    rtr_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // clang-format off
    [LEFT_THUMB_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ltl_finished, ltl_reset),
    [RIGHT_THUMB_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rtr_finished, rtr_reset)
    // clang-format on
};
