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

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
    // clang-format off
    _QWERTY,
    _ARROWS,
    _LOWER,
    _RAISE,
    _NUMPAD,
    _MOUSE,
    _ADJUST
    // clang-format on
};

enum preonic_keycodes {
    // clang-format off
    DEFAULT = SAFE_RANGE,
    LOW_ENT,
    RSE_SPC
    // clang-format on
};

// Let's dance
typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD = 2, DOUBLE_TAP = 3, DOUBLE_HOLD = 4 };

enum { MV = 0, RALT };

int cur_dance(qk_tap_dance_state_t *state);

void mv_finished(qk_tap_dance_state_t *state, void *user_data);
void mv_reset(qk_tap_dance_state_t *state, void *user_data);

void ralt_finished(qk_tap_dance_state_t *state, void *user_data);
void ralt_reset(qk_tap_dance_state_t *state, void *user_data);

#define ESCTRL LCTL_T(KC_ESCAPE)
#define ENT_SFT KC_SFTENT
#define MEN_ALT LALT_T(KC_APPLICATION)
#define TD_MV TD(MV)
#define TD_RALT TD(RALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    /* Qwerty
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │   `   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │  BKSP │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Tab   │   Q   │   W   │   E   │   R   │   T   │   Y   │   U   │   I   │   O   │   P   │   \   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ ESCtrl│   A   │   S   │   D   │   F   │   G   │   H   │   J   │   K   │   L   │   ;   │   '   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Shift │   Z   │   X   │   C   │   V   │   B   │   N   │   M   │   ,   │   .   │   /   │ENT/SFT│
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │ MV    │ Ctrl  │  GUI  │  Alt  │  Enter/Lower  │  Raise/Space  │Mn/Alt │ Left  │ Down  │ Right │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_QWERTY] = LAYOUT_preonic_2x2u(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
        ESCTRL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT, \
        TD_MV,   KC_LCTL, KC_LGUI, KC_LALT,          LOW_ENT, RSE_SPC,          TD_RALT, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    /* Arrows
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │Default│       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │  Up   │       │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │       │ Left  │ Down  │ Right │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_ARROWS] = LAYOUT_preonic_2x2u(
        DEFAULT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, \
        _______, _______, _______, _______,          _______, _______,          _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Lower
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │   ~   │   !   │   @   │   #   │   $   │   %   │   ^   │   &   │   *   │   (   │   )   │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │   -   │   =   │   [   │   ]   │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │ Left  │ Down  │  Up   │ Right │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │ Home  │  Up   │  End  │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │       │ Left  │ Down  │ Right │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_LOWER] = LAYOUT_preonic_2x2u(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END, \
        _______, _______, _______, _______,          _______, _______,          _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Raise
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │ ESC   │  F1   │  F2   │  F3   │  F4   │       │       │ PrtSc │ ScrLk │ Pause │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │  F5   │  F6   │  F7   │  F8   │       │       │  Ins  │ Home  │ PgUp  │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Caps  │  F9   │  F10  │  F11  │  F12  │       │       │  Del  │  End  │ PgDn  │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │ Prev  │ Play  │ Stop  │ Next  │       │ NumLk │ Mute  │ Vol - │ Vol + │       │       │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_RAISE] = LAYOUT_preonic_2x2u(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, \
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______, _______, \
        KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______, \
        _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, KC_NLCK, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, \
        _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
    ),

    /* Numpad
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │DEFAULT│       │       │       │       │       │       │       │ NumLk │   /   │   *   │  BKSP │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │   7   │   8   │   9   │   -   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │   4   │   5   │   6   │   +   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │   1   │   2   │   3   │ Enter │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │   0   │       │  Del  │       │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_NUMPAD] = LAYOUT_preonic_2x2u(
        DEFAULT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,          TD_RALT, XXXXXXX, KC_PDOT, XXXXXXX
    ),

    /* Mouse
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │DEFAULT│       │       │       │       │       │       │       │       │ ACL 0 │ ACL 1 │ ACL 2 │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │ WH UP │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │ WH DN │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │ BTN 3 │       │       │ WH L  │  UP   │ WH R  │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │   Button 1    │    Button 2   │       │ LEFT  │ DOWN  │ RIGHT │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_MOUSE] = LAYOUT_preonic_2x2u(
        DEFAULT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX,          KC_BTN1, KC_BTN2,          XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R
    ),

    /* Adjust (Lower + Raise)
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │ Reset │ Debug │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │ Audio │       │       │       │       │       │ M Mode│       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │Voice -│Voice +│       │       │       │       │ Music │ MIDI  │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_ADJUST] = LAYOUT_preonic_2x2u(
        _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, AU_TOG,  _______, _______, _______, _______, _______, MU_MOD,  _______, _______, _______, _______, \
        _______, MUV_DE,  MUV_IN,  _______, _______, _______, _______, MU_TOG,  MI_TOG,  _______, _______, _______, \
        _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
    )
    // clang-format on
};

static uint16_t sc_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DEFAULT:
            if (record->event.pressed) {
                layer_move(_QWERTY);
            }
            return false;
            break;
        case LOW_ENT:
            if (record->event.pressed) {
                sc_timer = timer_read();
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);

                if (timer_elapsed(sc_timer) < TAPPING_TERM) {
                    register_code(KC_ENTER);
                    unregister_code(KC_ENTER);
                }
            }
            return false;
            break;
        case RSE_SPC:
            if (record->event.pressed) {
                sc_timer = timer_read();
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);

                if (timer_elapsed(sc_timer) < TAPPING_TERM) {
                    register_code(KC_SPACE);
                    unregister_code(KC_SPACE);
                }
            }
            return false;
            break;
    }
    return true;
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
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
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
        case RSE_SPC:
        case LOW_ENT:
            return false;
        default:
            return true;
    }
}

// Track NumLock state

bool numlock_is_on = false;

void matrix_init_user(void) {
    if (host_keyboard_leds() & (1 << USB_LED_NUM_LOCK)) {
        numlock_is_on = true;
    } else {
        numlock_is_on = false;
    }
}

void led_set_keymap(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
        numlock_is_on = true;
    } else {
        numlock_is_on = false;
    }
}

// This is how we dance

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            return DOUBLE_TAP;
        } else {
            return DOUBLE_HOLD;
        }
    }
    return 5;
}

static tap mv_state = {.is_press_action = true, .state = 0};

void mv_finished(qk_tap_dance_state_t *state, void *user_data) {
    mv_state.state = cur_dance(state);
    switch (mv_state.state) {
        case SINGLE_TAP:
            if (layer_state_is(_ARROWS)) {
                layer_off(_ARROWS);
            } else {
                layer_on(_ARROWS);
            }
            break;
        case SINGLE_HOLD:
            layer_on(_ARROWS);
            break;
        case DOUBLE_TAP:
            if (layer_state_is(_MOUSE)) {
                layer_off(_MOUSE);
            } else {
                layer_move(_MOUSE);
            }
            break;
        case DOUBLE_HOLD:
            layer_on(_MOUSE);
            break;
    }
}

void mv_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (mv_state.state) {
        case SINGLE_TAP:
            break;
        case SINGLE_HOLD:
            layer_off(_ARROWS);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_off(_MOUSE);
            break;
    }
    mv_state.state = 0;
}

static tap ralt_state      = {.is_press_action = true, .state = 0};
bool       kp0_registered  = false;
bool       menu_registered = false;

void ralt_finished(qk_tap_dance_state_t *state, void *user_data) {
    ralt_state.state = cur_dance(state);
    switch (ralt_state.state) {
        case SINGLE_TAP:
            if (layer_state_is(_NUMPAD)) {
                register_code(KC_KP_0);
                kp0_registered = true;
            } else {
                register_code(KC_APPLICATION);
                menu_registered = true;
            }
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            if (layer_state_is(_NUMPAD)) {
                if (numlock_is_on) {
                    tap_code(KC_NUMLOCK);
                }
                layer_off(_NUMPAD);
            } else {
                if (!numlock_is_on) {
                    tap_code(KC_NUMLOCK);
                }
                layer_move(_NUMPAD);
            }
            break;
        case DOUBLE_HOLD:
            if (!numlock_is_on) {
                tap_code(KC_NUMLOCK);
            }
            layer_on(_NUMPAD);
            break;
    }
}

void ralt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ralt_state.state) {
        case SINGLE_TAP:
            if (kp0_registered) {
                unregister_code(KC_KP_0);
            }
            if (menu_registered) {
                unregister_code(KC_APPLICATION);
            }
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            if (numlock_is_on) {
                tap_code(KC_NUMLOCK);
            }
            layer_off(_NUMPAD);
            break;
    }
    ralt_state.state = 0;
    kp0_registered   = false;
    menu_registered  = false;
}

qk_tap_dance_action_t tap_dance_actions[] = {[MV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mv_finished, mv_reset), [RALT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ralt_finished, ralt_reset)};
