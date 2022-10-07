/* Copyright 2015-2021 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_steno.h"

enum layers {
    // clang-format off
    _DEFAULT,
    _LOWER,
    _RAISE,
    _NUMPAD,
    _FN,
    _PLOVER,
    _ADJUST
    // clang-format on
};

// clang-format off
// Layer Switchers
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define FN      MO(_FN)
#define ESCTL   MT(MOD_LCTL, KC_ESCAPE)
#define CAPSCTL MT(MOD_LCTL, KC_CAPS_LOCK)
#define LT_Q    LT(_FN, KC_Q)
#define LT_A    LT(_NUMPAD, KC_A)
#define PLOVER  TO(_PLOVER)
#define EXIT    TO(_DEFAULT)

// Ctrl Combos
#define CTL_A   LCTL(KC_A)
#define CTL_S   LCTL(KC_S)
#define CTL_D   LCTL(KC_D)
#define CTL_F   LCTL(KC_F)
#define CTL_G   LCTL(KC_G)
#define CTL_Z   LCTL(KC_Z)
#define CTL_X   LCTL(KC_X)
#define CTL_C   LCTL(KC_C)
#define CTL_V   LCTL(KC_V)
#define CTL_B   LCTL(KC_B)

// Home/End
#define HOME    LCTL(KC_LEFT)
#define END     LCTL(KC_RIGHT)

// Screenshot
#define SCRSH_A C(S(G(KC_3)))
#define SCRSH_P C(S(G(KC_4)))

// Web Functions
#define WBCK    KC_WWW_BACK
#define WFWD    KC_WWW_FORWARD
#define WTOP    LCTL(KC_UP)
#define WBTM    LCTL(KC_DOWN)
// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_DEFAULT] = LAYOUT_preonic_grid(
    KC_MUTE, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
    KC_TAB , LT_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
    ESCTL  , LT_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    KC_LCTL, FN     , KC_LGUI, KC_LALT, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_RALT, KC_RGUI, KC_APP , KC_RCTL
    ),

    [_LOWER] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
    CAPSCTL, CTL_A  , CTL_S  , CTL_D  , CTL_F  , CTL_G  , KC_QUOT, KC_MINS, KC_LBRC, KC_RBRC, _______, _______,
    _______, CTL_Z  , CTL_X  , CTL_C  , CTL_V  , CTL_B  , KC_BSLS, KC_EQL , _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_RAISE] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
    _______, CTL_A  , CTL_S  , CTL_D  , CTL_F  , CTL_G  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    _______, CTL_Z  , CTL_X  , CTL_C  , CTL_V  , CTL_B  , HOME   , KC_PGDN, KC_PGUP, END    , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_NUMPAD] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_HOME, KC_UP  , KC_END , KC_VOLU, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PENT,
    _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSLS, KC_P1  , KC_P2  , KC_P3  , KC_PEQL, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P0  , KC_P0  , KC_PDOT, _______, _______
    ),

    [_FN] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, WBCK   , WFWD   , WTOP   , _______, KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,
    _______, _______, _______, _______, WBTM   , _______, KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,
    _______, _______, _______, _______, _______, _______, KC_PAUS, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_PLOVER] = LAYOUT_preonic_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, STN_S1 , STN_TL , STN_PL , STN_HL , STN_ST1, STN_ST3, STN_FR , STN_PR , STN_LR , STN_TR , STN_DR ,
    XXXXXXX, STN_S2 , STN_KL , STN_WL , STN_RL , STN_ST2, STN_ST4, STN_RR , STN_BR , STN_GR , STN_SR , STN_ZR ,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    EXIT   , XXXXXXX, XXXXXXX, STN_N1 , STN_A  , STN_O  , STN_E  , STN_U  , STN_N2 , XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_ADJUST] = LAYOUT_preonic_grid(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_CAPS, XXXXXXX, MU_MOD , AU_ON  , AU_OFF , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, MUV_DE , MUV_IN , MU_ON  , MU_OFF , MI_ON  , MI_OFF , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    PLOVER , XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
    // clang-format on
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}

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
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
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
    return true;
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
