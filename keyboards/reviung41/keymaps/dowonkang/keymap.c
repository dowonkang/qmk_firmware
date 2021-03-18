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

#define LTH LOW_ESC
#define LTL NUM_TAB
#define RTH RSE
#define RTR MS_DEL
#define CSPC CTL_SPC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        LTAB, ______QWERTY_LEFT1__________,       ______QWERTY_RIGHT1_________, BSPC,
        LESC, ______HOME_MOD_LEFT2________,       ______HOME_MOD_RIGHT2_______, ENT ,
        SFTL, ______HOME_MOD_LEFT3________,       ______HOME_MOD_RIGHT3_______, SFTR,
                                LTL , LTH , CSPC, RTH , RTR
    ),

    [_LOWER] = LAYOUT_wrapper(
        TAB , ______NUMBER_12345__________,       ______NUMBER_67890__________, DEL ,
        ESC , ______MOD_LEFT_2_GRAVE______,       ______SYMBOL_2_MOD__________, ____,
        ____, ______MOD_LEFT_3____________,       ______SYMBOL_3______________, ____,
                                XXXX, XXXX, SPC , ____, ____
    ),

    [_RAISE] = LAYOUT_wrapper(
        TAB , ______NUMBER_12345__________,       ______NUMBER_67890__________, DEL ,
        ESC , ______MOD_LEFT_2_GRAVE______,       ______VI_NAV_ROW_2__________, ____,
        ____, ______MOD_LEFT_3____________,       ______VI_NAV_ROW_3__________, ____,
                                TAB , ESC , SPC , XXXX, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ____, TAB , WBCK, _UP_, WFWD, HOME,       ______NUMPAD_RIGHT_1________, ____,
        ____, ESC , LEFT, _DN_, RGHT, END ,       ______NUMPAD_RIGHT_2________, ____,
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX,       ______NUMPAD_RIGHT_3________, ____,
                                XXXX, XXXX, SPC , P0  , PDOT
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        RSET, XXXX, ______MEDIA_____, VOLU,       ______FN_RIGHT_1____________, INS ,
        ____, ______MOD_LEFT_2______, VOLD,       ______FN_RIGHT_2____________, ____,
        ____, MENU, ALTG, XXXX, XXXX, MUTE,       ______FN_RIGHT_3____________, ____,
                                TAB , ESC , SPC , XXXX, XXXX
    ),

    [_MOUSE] = LAYOUT_wrapper(
        XXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX,       XXXX, ACL0, ACL1, ACL2, XXXX, ____,
        XXXX, ______MOD_LEFT_2____________,       ______MOUSE_VI_ROW_2________, ____,
        ____, ______MOD_LEFT_3____________,       ______MOUSE_VI_ROW_3________, ____,
                                XXXX, XXXX, BTN2, BTN1, BTN3
    ),
    // clang-format on
};
