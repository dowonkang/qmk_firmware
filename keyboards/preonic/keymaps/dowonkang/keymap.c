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

// Tap dance
typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD
};

enum {
    LOWER,
    RAISE
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

void lower_finished(qk_tap_dance_state_t *state, void *user_data);
void lower_reset(qk_tap_dance_state_t *state, void *user_data);
void raise_finished(qk_tap_dance_state_t *state, void *user_data);
void raise_reset(qk_tap_dance_state_t *state, void *user_data);

// Aliases
#define LTH TD(LOWER)
#define LTL ALT_ESC
#define LTR CTL_TAB
#define RTH TD(RAISE)
#define RTL CTL_SPC
#define RTR FN_BSPC

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
    // clang-format on
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

uint8_t cur_dance(qk_tap_dance_state_t *state) {
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
    return 8;
}

static tap lower_tap_state = {
    .is_press_action = true,
    .state = 0
};

void lower_finished(qk_tap_dance_state_t *state, void *user_data) {
    lower_tap_state.state = cur_dance(state);
    switch (lower_tap_state.state) {
        case SINGLE_TAP:
            break;
        case SINGLE_HOLD:
            layer_on(_LOWER);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_on(_NUMPAD);
            break;
        default:
            break;
    }
}

void lower_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (lower_tap_state.state) {
        case SINGLE_TAP:
            break;
        case SINGLE_HOLD:
            layer_off(_LOWER);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_off(_NUMPAD);
            break;
        default:
            break;
    }
    lower_tap_state.state = 0;
}

static tap raise_tap_state = {
    .is_press_action = true,
    .state = 0
};

void raise_finished(qk_tap_dance_state_t *state, void *user_data) {
    raise_tap_state.state = cur_dance(state);
    switch (raise_tap_state.state) {
        case SINGLE_TAP:
            break;
        case SINGLE_HOLD:
            layer_on(_RAISE);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_on(_FUNCTION);
            break;
        default:
            break;
    }
}

void raise_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (raise_tap_state.state) {
        case SINGLE_TAP:
            break;
        case SINGLE_HOLD:
            layer_off(_RAISE);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_off(_FUNCTION);
            break;
        default:
            break;
    }
    raise_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [LOWER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lower_finished, lower_reset),
    [RAISE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, raise_finished, raise_reset)
};
