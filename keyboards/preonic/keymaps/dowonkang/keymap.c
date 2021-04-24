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

    [_ADJUST] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______FN_LEFT_1_____________, XXXX, XXXX, ______FN_RIGHT_1____________,
        ______FN_LEFT_2_____________, XXXX, XXXX, ______MOUSE_VI_CURSOR_______,
        ______FN_LEFT_3_____________, XXXX, XXXX, ______MOUSE_VI_WHEEL________,
        XXXX, XXXX, XXXX, ____, XXXX,    XXXX,    XXXX, ____, XXXX, XXXX, XXXX
    ),
    // clang-format on
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
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
