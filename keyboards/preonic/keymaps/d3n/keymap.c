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

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
    // clang-format off
    _QWERTY,
    _ARROWS,
    _LOWER,
    _RAISE,
    _NUMPAD,
    _MOUSE,
    _ADJUST
    // clang-format on
};

enum preonic_keycodes {
    // clang-format off
    DEFAULT = SAFE_RANGE,
    LOW_ENT,
    RSE_SPC,
    LEFT,
    DOWN,
    RIGHT
    // clang-format on
};

#define ESCTRL LCTL_T(KC_ESCAPE)
#define ENT_SFT KC_SFTENT
#define NUMPAD TG(_NUMPAD)
#define MOUSE TO(_MOUSE)
#define MEN_ALT LALT_T(KC_APPLICATION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    /* Qwerty
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │   `   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │  BKSP │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Tab   │   Q   │   W   │   E   │   R   │   T   │   Y   │   U   │   I   │   O   │   P   │   \   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ ESCtrl│   A   │   S   │   D   │   F   │   G   │   H   │   J   │   K   │   L   │   ;   │   '   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Shift │   Z   │   X   │   C   │   V   │   B   │   N   │   M   │   ,   │   .   │   /   │ENT/SFT│
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Numpad│ Ctrl  │  GUI  │  Alt  │ Enter │ Lower │ Raise │ Space │Mn/Alt │ Left  │ Down  │ Right │
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [_QWERTY] = LAYOUT_preonic_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
        ESCTRL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, ENT_SFT, \
        NUMPAD,  KC_LCTL, KC_LGUI, KC_LALT, LOW_ENT, LOW_ENT, RSE_SPC, RSE_SPC, MEN_ALT, LEFT,    DOWN,    RIGHT
    ),

    /* Arrows
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │Default│       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │  Up   │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │ Left  │ Down  │ Right │
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [_ARROWS] = LAYOUT_preonic_grid(
        DEFAULT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Lower
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │   ~   │   !   │   @   │   #   │   $   │   %   │   ^   │   &   │   *   │   (   │   )   │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │   -   │   =   │   [   │   ]   │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │ Left  │ Down  │  Up   │ Right │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │ Home  │  Up   │  End  │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │ Left  │ Down  │ Right │
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [_LOWER] = LAYOUT_preonic_grid(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______, \
        _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Raise
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │ ESC   │  F1   │  F2   │  F3   │  F4   │       │       │ PrtSc │ ScrLk │ Pause │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │  F5   │  F6   │  F7   │  F8   │       │       │  Ins  │ Home  │ PgUp  │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Caps  │  F9   │  F10  │  F11  │  F12  │       │       │  Del  │  End  │ PgDn  │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │ Prev  │ Play  │ Stop  │ Next  │       │       │ Mute  │ Vol - │ Vol + │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ MOUSE │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [_RAISE] = LAYOUT_preonic_grid(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, _______, \
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______, _______, \
        KC_CAPS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______, \
        _______, KC_MPRV, KC_MPLY, KC_MSTP, KC_MNXT, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, \
        MOUSE,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Numpad
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │DEFAULT│       │       │       │       │       │       │       │ NumLk │   /   │   *   │   -   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │   7   │   8   │   9   │   +   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │   4   │   5   │   6   │   =   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │   1   │   2   │   3   │ Enter │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │   0   │       │  Del  │       │
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [_NUMPAD] = LAYOUT_preonic_grid(
        DEFAULT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   XXXXXXX, KC_PDOT, XXXXXXX
    ),

    /* Mouse
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │DEFAULT│       │       │       │       │       │       │       │       │ ACL 0 │ ACL 1 │ ACL 2 │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │ WH UP │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │ WH DN │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │ BTN 3 │       │       │ WH L  │  UP   │ WH R  │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │ BTN 1 │ BTN 2 │       │       │ LEFT  │ DOWN  │ RIGHT │
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [_MOUSE] = LAYOUT_preonic_grid(
        DEFAULT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R
    ),

    /* Adjust (Lower + Raise)
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │ Reset │ Debug │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │ Audio │       │       │       │       │       │ M Mode│       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │Voice -│Voice +│       │       │       │       │ Music │ MIDI  │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
     */
    [_ADJUST] = LAYOUT_preonic_grid(
        _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, AU_TOG,  _______, _______, _______, _______, _______, MU_MOD,  _______, _______, _______, _______, \
        _______, MUV_DE,  MUV_IN,  _______, _______, _______, _______, MU_TOG,  MI_TOG,  _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
    // clang-format on
};

static uint16_t sc_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DEFAULT:
            if (record->event.pressed) {
                layer_move(_QWERTY);
            }
            return false;
            break;
        case LOW_ENT:
            if (record->event.pressed) {
                sc_timer = timer_read();
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);

                if (timer_elapsed(sc_timer) < TAPPING_TERM) {
                    register_code(KC_ENTER);
                    unregister_code(KC_ENTER);
                }
            }
            return false;
            break;
        case RSE_SPC:
            if (record->event.pressed) {
                sc_timer = timer_read();
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);

                if (timer_elapsed(sc_timer) < TAPPING_TERM) {
                    register_code(KC_SPACE);
                    unregister_code(KC_SPACE);
                }
            }
            return false;
            break;
        case LEFT:
            if (record->event.pressed) {
                layer_on(_ARROWS);
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LEFT);
            }
            break;
        case DOWN:
            if (record->event.pressed) {
                layer_on(_ARROWS);
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_DOWN);
            }
            break;
        case RIGHT:
            if (record->event.pressed) {
                layer_on(_ARROWS);
                register_code(KC_RIGHT);
            } else {
                unregister_code(KC_RIGHT);
            }
            break;
    }
    return true;
};

bool     muse_mode      = false;
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
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
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
        case RSE_SPC:
        case LOW_ENT:
            return false;
        default:
            return true;
    }
}
