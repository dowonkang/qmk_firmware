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

#define LTH LOW
#define LTR NUM_ESC
#define RTH RSE
#define RTL FN_SPC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        MUTE, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______BASE_LEFT_1___________, XXXX, XXXX, ______BASE_RIGHT_1__________,
        ______BASE_LEFT_2___________, XXXX, XXXX, ______BASE_RIGHT_2__________,
        ______BASE_LEFT_3___________, XXXX, XXXX, ______BASE_RIGHT_3__________,
        XXXX, XXXX, XXXX, LTH , LTR ,    XXXX,    RTL , RTH , XXXX, XXXX, XXXX
    ),

    [_LOWER] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______LOWER_LEFT_1__________, XXXX, XXXX, ______LOWER_RIGHT_1_________,
        ______LOWER_LEFT_2__________, XXXX, XXXX, ______LOWER_RIGHT_2_________,
        ______LOWER_LEFT_3__________, XXXX, XXXX, ______LOWER_RIGHT_3_________,
        XXXX, XXXX, XXXX, ____, XXXX,    XXXX,    SPC , ____, XXXX, XXXX, XXXX
    ),

    [_RAISE] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______RAISE_LEFT_1__________, XXXX, XXXX, ______RAISE_RIGHT_1_________,
        ______RAISE_LEFT_2__________, XXXX, XXXX, ______RAISE_RIGHT_2_________,
        ______RAISE_LEFT_3__________, XXXX, XXXX, ______RAISE_RIGHT_3_________,
        XXXX, XXXX, XXXX, ____, ESC ,    XXXX,    XXXX, ____, XXXX, XXXX, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______NUMPAD_LEFT_1_________, XXXX, XXXX, ______NUMPAD_RIGHT_1________,
        ______NUMPAD_LEFT_2_________, XXXX, XXXX, ______NUMPAD_RIGHT_2________,
        ______NUMPAD_LEFT_3_________, XXXX, XXXX, ______NUMPAD_RIGHT_3________,
        XXXX, XXXX, XXXX, ____, ____,    XXXX,    P0  , PDOT, XXXX, XXXX, XXXX
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______FN_LEFT_1_____________, XXXX, XXXX, ______FN_RIGHT_1____________,
        ______FN_LEFT_2_____________, XXXX, XXXX, ______FN_RIGHT_2____________,
        ______FN_LEFT_3_____________, XXXX, XXXX, ______FN_RIGHT_3____________,
        XXXX, XXXX, XXXX, XXXX, XXXX,    XXXX,    ____, XXXX, XXXX, XXXX, XXXX
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
