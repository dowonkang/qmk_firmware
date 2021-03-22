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
#define LTAB FN_TAB
#define LESC NUM_ESC
#define LTH  LOW
#define LTL  NUM_TAB
#define RTH  RSE
#define RTR  MS_DEL
#define CSPC CTL_SPC
// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        LTAB, ______BASE_LEFT_1___________,       ______BASE_RIGHT_1__________, BSPC,
        LESC, ______BASE_LEFT_2___________,       ______BASE_RIGHT_2__________, ENT ,
        SFTL, ______BASE_LEFT_3___________,       ______BASE_RIGHT_3__________, SFTR,
                                LTL , LTH , CSPC, RTH , RTR
    ),

    [_LOWER] = LAYOUT_wrapper(
        TAB , ______LOWER_LEFT_1__________,       ______LOWER_RIGHT_1_________, DEL ,
        ESC , ______LOWER_LEFT_2__________,       ______LOWER_RIGHT_2_________, ____,
        ____, ______LOWER_LEFT_3__________,       ______LOWER_RIGHT_3_________, ____,
                                XXXX, ____, SPC , ____, ____
    ),

    [_RAISE] = LAYOUT_wrapper(
        TAB , ______RAISE_LEFT_1__________,       ______RAISE_RIGHT_1_________, DEL ,
        ESC , ______RAISE_LEFT_2__________,       ______RAISE_RIGHT_2_________, ____,
        ____, ______RAISE_LEFT_3__________,       ______RAISE_RIGHT_3_________, ____,
                                ____, ____, SPC , ____, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ____, ______NUMPAD_LEFT_1_________,       ______NUMPAD_RIGHT_1________, ____,
        ____, ______NUMPAD_LEFT_2_________,       ______NUMPAD_RIGHT_2________, ____,
        ____, ______NUMPAD_LEFT_3_________,       ______NUMPAD_RIGHT_3________, ____,
                                ____, ____, SPC , P0  , PDOT
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ____, ______FN_LEFT_1_____________,       ______FN_RIGHT_1____________, ____,
        ____, ______FN_LEFT_2_____________,       ______FN_RIGHT_2____________, ____,
        ____, ______FN_LEFT_3_____________,       ______FN_RIGHT_3____________, ____,
                                ____, ____, SPC , ____, ____
    ),

    [_MOUSE] = LAYOUT_wrapper(
        XXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX,       XXXX, ACL0, ACL1, ACL2, XXXX, ____,
        XXXX, ______MOD_LEFT_2____________,       ______MOUSE_VI_ROW_2________, ____,
        ____, ______MOD_LEFT_3____________,       ______MOUSE_VI_ROW_3________, ____,
                                XXXX, XXXX, BTN2, BTN1, BTN3
    ),
    // clang-format on
};
