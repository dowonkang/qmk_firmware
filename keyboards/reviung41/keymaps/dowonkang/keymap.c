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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_reviung41(
        FN_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,          KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        U_ESC  , HOME_A , HOME_S , HOME_D , HOME_F , KC_G   ,          KC_H   , HOME_J , HOME_K , HOME_L , HOME_SC, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,          KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                   KC_LALT, LOWER  ,          KC_SPC ,          RAISE  , KC_LGUI
    ),

    [_LOWER] = LAYOUT_reviung41(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,          KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_ESC , KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, CTL_G  ,          KC_QUOT, LOW_J  , LOW_K  , LOW_L  , _______, _______,
        _______, CTL_Z  , CTL_X  , CTL_C  , CTL_V  , CTL_B  ,          KC_BSLS, KC_EQL , _______, _______, _______, _______,
                                   _______, _______,          _______,          _______, _______
    ),

    [_RAISE] = LAYOUT_reviung41(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,          KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_ESC , KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, CTL_G  ,          KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______,
        _______, CTL_Z  , CTL_X  , CTL_C  , CTL_V  , CTL_B  ,          KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, _______,
                                   _______, _______,          _______,          _______, KC_APP
    ),

    [_FUNCTION] = LAYOUT_reviung41(
        _______, KC_WBAK, KC_HOME, KC_WFWD, KC_WREF, KC_VOLU,          KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_INS ,
        KC_ESC , XXXXXXX, KC_END , KC_WSCH, KC_WSTP, KC_VOLD,          KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_WHOM, KC_MUTE,          KC_PAUS, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
                                   _______, _______,          _______,          _______, _______
    ),

    [_NUMPAD] = LAYOUT_reviung41(
        _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, XXXXXXX,          KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX,          KC_TAB , KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PENT,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_PAST, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, _______,
                                   _______, KC_LGUI,          _______,          KC_P0  , KC_PDOT
    ),

    [_ADJUST] = LAYOUT_reviung41(
        RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_INS , KC_F1  , KC_F2  , KC_F3  , KC_F4  , XXXXXXX,
        KC_CLCK, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MOD, RGB_TOG,          KC_CAPS, KC_F5  , KC_F6  , KC_F7  , KC_F8  , XXXXXXX,
        XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD, RGB_RMOD,CMB_TOG,          XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , XXXXXXX,
                                   _______, _______,          XXXXXXX,          _______, _______
    ),
    // clang-format on
};
