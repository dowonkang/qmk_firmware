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

#define UTAB LT(_FN_ONEHAND, KC_TAB)
#define UESC LT(_NUMPAD, KC_ESCAPE)
#define FN2 LT_MENU

// clang-format off
#define ______ADJUST_RIGHT_1________ XXXXXXX, MUV_IN , XXXXXXX, XXXXXXX, XXXXXXX
#define ______ADJUST_RIGHT_2________ MU_ON  , MU_MOD , AU_ON  , MI_ON  , XXXXXXX
#define ______ADJUST_RIGHT_3________ MU_OFF , MUV_DE , AU_OFF , MI_OFF , XXXXXXX
// clang-format on

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        MUTE, ______NUMBER_12345__________, ______NUMBER_67890__________, DEL ,
        UTAB, ______BASE_LEFT_1___________, ______BASE_RIGHT_1__________, BSPC,
        UESC, ______BASE_LEFT_2___________, ______BASE_RIGHT_2__________, ENT ,
        SFTL, ______BASE_LEFT_3___________, ______BASE_RIGHT_3__________, SFTR,
        CTRL, FN  , GUI , ALT , LOW ,    SPC ,    RSE , ALT , GUIR, FN2 , CTLR
    ),

    [_LOWER] = LAYOUT_wrapper(
        ____, ______SHIFTED_12345_________, ______SHIFTED_67890_________, INS ,
        GRV , ______LOWER_LEFT_1__________, ______LOWER_RIGHT_1_________, DEL ,
        ESC , ______LOWER_LEFT_2__________, ______LOWER_RIGHT_2_________, ____,
        ____, ______LOWER_LEFT_3__________, ______LOWER_RIGHT_3_________, ____,
        ____, ____, ____, ____, ____,    ____,    ____, ____, ____, ____, ____
    ),

    [_RAISE] = LAYOUT_wrapper(
        ____, ______SHIFTED_12345_________, ______SHIFTED_67890_________, INS ,
        GRV , ______RAISE_LEFT_1__________, ______RAISE_RIGHT_1_________, DEL ,
        ESC , ______RAISE_LEFT_2__________, ______RAISE_RIGHT_2_________, ____,
        ____, ______RAISE_LEFT_3__________, ______RAISE_RIGHT_3_________, ____,
        ____, ____, ____, ____, ____,    ____,    ____, ____, ____, ____, ____
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ____, ____________________________, ____________________________, ____,
        ______F_123456____________________, ______F_789101112_________________,
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX, INS , HOME, PGUP, XXXX, ____,
        ____, XXXX, PSCR, SLCK, PAUS, XXXX, XXXX, DEL , END , PGDN, XXXX, ____,
        ____, ____, ____, ____, ____,    ____,    ____, ____, ____, ____, ____
    ),

    [_FN_ONEHAND] = LAYOUT_wrapper(
        ____, ____________________________, ____________________________, ____,
        ____, ______FN_LEFT_1_____________, ______FN_RIGHT_1____________, DEL ,
        ____, ______FN_LEFT_2_____________, ______FN_RIGHT_2____________, ____,
        ____, ______FN_LEFT_3_____________, ______FN_RIGHT_3____________, ____,
        ____, ____, ____, ____, ____,    ____,    ____, ____, ____, ____, ____
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ____, ______F_12345_______________, ______F_678910______________, ____,
        TAB , ______NUMPAD_LEFT_1_________, ______NUMPAD_RIGHT_1________, ____,
        ____, ______NUMPAD_LEFT_2_________, ______NUMPAD_RIGHT_2________, ____,
        ____, ______NUMPAD_LEFT_3_________, ______NUMPAD_RIGHT_3________, ____,
        ____, ____, ____, ____, ____,    ____,    P0  , P0  , PDOT, ____, ____
    ),

    [_MOUSE] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, ____,
        TAB , ______MOUSE_WHEEL_1_________, ______MOUSE_CURSOR_1________, ____,
        ESC , ______MOUSE_WHEEL_2_________, ______MOUSE_CURSOR_2________, ____,
        ____, XXXX, ACL0, ACL1, ACL2, XXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, ____,
        ____, ____, ____, ____, ____,    ____,    BTN1, BTN2, BTN3, XXXX, XXXX
    ),

    [_ADJUST] = LAYOUT_wrapper(
        RSET, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        XXXX, ______FN_LEFT_1_____________, ______ADJUST_RIGHT_1________, XXXX,
        CAPS, ______FN_LEFT_2_____________, ______ADJUST_RIGHT_2________, XXXX,
        XXXX, ______FN_LEFT_3_____________, ______ADJUST_RIGHT_3________, XXXX,
        ____, ____, ____, ____, ____,    ____,    ____, ____, ____, ____, ____
    ),
    // clang-format on
};

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
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
    return true;
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
