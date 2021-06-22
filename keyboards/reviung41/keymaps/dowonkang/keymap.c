/* Copyright 2020 gtips
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

// clang-format off
#define UTAB LT(_FUNCTION, KC_TAB)
#define UESC LT(_NUMPAD, KC_ESCAPE)
#define LTH  LOW
#define LTL  KC_LALT
#define RTH  RSE
#define RTR  KC_LGUI
#define CSPC MT_SPC
// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        UTAB, ______BASE_LEFT_1___________,       ______BASE_RIGHT_1__________, BSPC,
        UESC, ______BASE_LEFT_2___________,       ______BASE_RIGHT_2__________, ENT ,
        SFTL, ______BASE_LEFT_3___________,       ______BASE_RIGHT_3__________, SFTR,
                                LTL , LTH , CSPC, RTH , RTR
    ),

    [_LOWER] = LAYOUT_wrapper(
        GRV , ______LOWER_LEFT_1__________,       ______LOWER_RIGHT_1_________, DEL ,
        ESC , ______LOWER_LEFT_2__________,       ______LOWER_RIGHT_2_________, ____,
        ____, ______LOWER_LEFT_3__________,       ______LOWER_RIGHT_3_________, ____,
                                XXXX, ____, SPC , ____, ____
    ),

    [_RAISE] = LAYOUT_wrapper(
        GRV , ______RAISE_LEFT_1__________,       ______RAISE_RIGHT_1_________, DEL ,
        ESC , ______RAISE_LEFT_2__________,       ______RAISE_RIGHT_2_________, ____,
        ____, ______RAISE_LEFT_3__________,       ______RAISE_RIGHT_3_________, ____,
                                ____, ____, SPC , ____, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ____, ______NUMPAD_LEFT_1_________,       ______NUMPAD_RIGHT_1________, ____,
        ____, ______NUMPAD_LEFT_2_________,       ______NUMPAD_RIGHT_2________, ____,
        ____, ______NUMPAD_LEFT_3_________,       ______NUMPAD_RIGHT_3________, ____,
                                ____, ____, CSPC, P0  , PDOT
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ____, ______FN_LEFT_1_____________,       ______FN_RIGHT_1____________, ____,
        ____, ______FN_LEFT_2_____________,       ______FN_RIGHT_2____________, ____,
        ____, ______FN_LEFT_3_____________,       ______FN_RIGHT_3____________, ____,
                                ____, ____, SPC , ____, ____
    ),

    [_MOUSE] = LAYOUT_wrapper(
        XXXX, ______MOUSE_WHEEL_1_________,       ______MOUSE_CURSOR_1________, ____,
        XXXX, ______MOUSE_WHEEL_2_________,       ______MOUSE_CURSOR_2________, ____,
        ____, SFTL, XXXX, XXXX, XXXX, XXXX,       XXXX, ACL0, ACL1, ACL2, XXXX, ____,
                                XXXX, XXXX, BTN3, BTN1, BTN2
    ),

    [_ADJUST] = LAYOUT_wrapper(
        RSET, ______FN_LEFT_1_____________,       ______RGB_CONTROL_1_________, ____,
        ____, ______FN_LEFT_2_____________,       ______RGB_CONTROL_2_________, ____,
        ____, ______FN_LEFT_3_____________,       ______RGB_CONTROL_3_________, ____,
                                XXXX, ____, XXXX, ____, XXXX
    ),
    // clang-format on
};
