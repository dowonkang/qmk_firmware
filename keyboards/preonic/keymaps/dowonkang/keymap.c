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

#define LTH LOW_ESC
#define LTL NUM_TAB
#define LTR CTL_BSP
#define RTH RSE_SPC
#define RTL SFT_ENT
#define RTR FN_DEL

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        MUTE, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______QWERTY_LEFT1__________, XXXX, XXXX, ______QWERTY_RIGHT1_________,
        ______HOME_MOD_LEFT2________, XXXX, XXXX, ______HOME_MOD_RIGHT2_______,
        ______HOME_MOD_LEFT3________, XXXX, XXXX, ______HOME_MOD_RIGHT3_______,
        XXXX, XXXX, LTL , LTH , LTR ,    XXXX,    RTL , RTH , RTR , XXXX, XXXX
    ),

    [_LOWER] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______NUMBER_12345__________, XXXX, XXXX, ______NUMBER_67890__________,
        ______MOD_LEFT_2_GRAVE______, XXXX, XXXX, ______SYMBOL_2_MOD__________,
        ______MOD_LEFT_3____________, XXXX, XXXX, ______SYMBOL_3______________,
        XXXX, XXXX, XXXX, XXXX, XXXX,    XXXX,    ENT , SPC , DEL , XXXX, XXXX
    ),

    [_RAISE] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        ______NUMBER_12345__________, XXXX, XXXX, ______NUMBER_67890__________,
        ______MOD_LEFT_2_GRAVE______, XXXX, XXXX, ______VI_NAV_ROW_2__________,
        ______MOD_LEFT_3____________, XXXX, XXXX, ______VI_NAV_ROW_3__________,
        XXXX, XXXX, TAB , ESC , BSPC,    XXXX,    XXXX, XXXX, XXXX, XXXX, XXXX
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        RSET, ______MEDIA_____, VOLU, XXXX, XXXX, ______FN_RIGHT_1____________,
        ______MOD_LEFT_2______, VOLD, XXXX, XXXX, ______FN_RIGHT_2____________,
        MENU, ALTG, XXXX, XXXX, MUTE, XXXX, XXXX, ______FN_RIGHT_3____________,
        XXXX, XXXX, ADJ , MOUS, XXXX,    XXXX,    XXXX, XXXX, XXXX, XXXX, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        TAB , WBCK, _UP_, WFWD, HOME, XXXX, XXXX, ______NUMPAD_RIGHT_1________,
        ESC , LEFT, _DN_, RGHT, END , XXXX, XXXX, ______NUMPAD_RIGHT_2________,
        XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX, XXXX, ______NUMPAD_RIGHT_3________,
        XXXX, XXXX, XXXX, XXXX, XXXX,    XXXX,    PENT, P0  , PDOT, XXXX, XXXX
    ),

    [_MOUSE] = LAYOUT_wrapper(
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX, XXXX, XXXX, ACL0, ACL1, ACL2, XXXX,
        ______MOD_LEFT_2____________, XXXX, XXXX, ______MOUSE_VI_ROW_2________,
        ______MOD_LEFT_3____________, XXXX, XXXX, ______MOUSE_VI_ROW_3________,
        XXXX, XXXX, XXXX, XXXX, XXXX,    XXXX,    BTN2, BTN1, BTN3, XXXX, XXXX
    ),

    [_ADJUST] = LAYOUT_wrapper(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG  ,
        RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TERM_ON, TERM_OFF,XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, MU_MOD , AU_ON  , AU_OFF,  AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, MUV_DE , MUV_IN , MU_ON  , MU_OFF,  MI_ON  , MI_OFF , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
    // clang-format on
};

bool muse_mode = false;
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
