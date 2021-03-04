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

#define FN MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_preonic_1x2uC(
        // clang-format off
        KC_MUTE, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        FN_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        U_ESC  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_LCTL, FN     , KC_LGUI, KC_LALT, LOWER  ,     KC_SPC,       RAISE  , KC_RALT, KC_RGUI, KC_APP , KC_RCTL
        // clang-format on
        ),

    [_LOWER] = LAYOUT_preonic_1x2uC(
        // clang-format off
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_ESC , CTL_A  , CTL_S  , CTL_D  , CTL_F  , CTL_G  , KC_QUOT, KC_MINS, KC_LBRC, KC_RBRC, _______, _______,
        _______, CTL_Z  , CTL_X  , CTL_C  , CTL_V  , CTL_B  , KC_BSLS, KC_EQL , _______, _______, _______, _______,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
        // clang-format on
        ),

    [_RAISE] = LAYOUT_preonic_1x2uC(
        // clang-format off
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_ESC , CTL_A  , CTL_S  , CTL_D  , CTL_F  , CTL_G  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______,
        _______, CTL_Z  , CTL_X  , CTL_C  , CTL_V  , CTL_B  , KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, _______,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
        // clang-format on
        ),

    [_FUNCTION] = LAYOUT_preonic_1x2uC(
        // clang-format off
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, _______,
        _______, KC_WBAK, KC_HOME, KC_WFWD, KC_WREF, KC_VOLU, KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_INS ,
        KC_ESC , XXXXXXX, KC_END , KC_WSCH, KC_WSTP, KC_VOLD, KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_WHOM, KC_MUTE, KC_PAUS, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
        // clang-format on
        ),

    [_NUMPAD] = LAYOUT_preonic_1x2uC(
        // clang-format off
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, XXXXXXX, _______,
        _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_TAB , KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PENT,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, _______,
        _______, _______, _______, _______, _______,     _______,      KC_P0  , XXXXXXX, KC_PDOT, XXXXXXX, _______
        // clang-format on
        ),

    [_ADJUST] = LAYOUT_preonic_1x2uC(
        // clang-format off
        RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DEBUG  ,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TERM_ON, TERM_OFF,XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, MU_MOD , AU_ON  , AU_OFF,  AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, MUV_DE , MUV_IN , MU_ON  , MU_OFF,  MI_ON  , MI_OFF , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        // clang-format on
        )
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

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
