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
    _LOWER,
    _RAISE,
    _NUMPAD,
    _MOUSE,
    _ADJUST
    // clang-format on
};

enum preonic_keycodes {
    // clang-format off
    ALT_ESC = SAFE_RANGE
    // clang-format on
};

// Let's dance
typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum {
    // clang-format off
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4
    // clang-format on
};

enum { EXTRA = 0 };

int cur_dance(qk_tap_dance_state_t *state);

void extra_finished(qk_tap_dance_state_t *state, void *user_data);
void extra_reset(qk_tap_dance_state_t *state, void *user_data);

#define TD_EXTR TD(EXTRA)
#define LOW_SPC LT(_LOWER, KC_SPACE)
#define RSE_SPC LT(_RAISE, KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    /* Qwerty
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │ ESC   │   1   │   2   │   3   │   4   │   5   │   6   │   7   │   8   │   9   │   0   │   `   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Tab   │   Q   │   W   │   E   │   R   │   T   │   Y   │   U   │   I   │   O   │   P   │BackSpc│
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Ctrl  │   A   │   S   │   D   │   F   │   G   │   H   │   J   │   K   │   L   │   ;   │   '   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │ Shift │   Z   │   X   │   C   │   V   │   B   │   N   │   M   │   ,   │   .   │   /   │Ent/Sft│
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │ Extra │ Ctrl  │  GUI  │  Alt  │  Enter/Lower  │  Raise/Space  │ Left  │ Down  │  Up   │ Right │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_QWERTY] = LAYOUT_preonic_2x2u(
        ALT_ESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
        TD_EXTR, KC_LCTL, KC_LGUI, KC_LALT,          LOW_SPC, RSE_SPC,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Lower
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │   !   │   @   │   #   │   $   │   %   │   ^   │   &   │   *   │   (   │   )   │   ~   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │   _   │   +   │   {   │   }   │   |   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │   -   │   =   │   [   │   ]   │   \   │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │       │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │ Home  │ PgDn  │ PgUp  │  End  │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_LOWER] = LAYOUT_preonic_2x2u(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, \
        _______, _______, _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
        _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______,          _______, _______,          KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    /* Raise
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │  F1   │  F2   │  F3   │  F4   │       │       │       │       │       │       │ PrtScr│
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │  F5   │  F6   │  F7   │  F8   │       │ Home  │ PgDn  │ PgUp  │  End  │  Ins  │  Del  │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │  F9   │  F10  │  F11  │  F12  │       │ Left  │ Down  │  Up   │ Right │       │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │ Prev  │ Vol - │ Vol + │ Next  │       │       │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │ MENU  │       │       │       │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_RAISE] = LAYOUT_preonic_2x2u(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, KC_PSCR, \
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  KC_DEL, \
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
        _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, _______, \
        _______, _______, _______, _______,          _______, _______,          KC_APP,  _______, _______, _______
    ),

    /* Numpad
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │       │       │       │       │       │       │   7   │   8   │   9   │   -   │NumLock│
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │   4   │   5   │   6   │   +   │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │   1   │   2   │   3   │   *   │       │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │   0   │       │   .   │   /   │ Enter │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_NUMPAD] = LAYOUT_preonic_2x2u(
        _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_NLCK, \
        _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______, \
        _______, _______, _______, _______, _______, _______, _______, KC_P0,   _______, KC_PDOT, KC_PSLS, KC_PENT, \
        _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
    ),

    /* Mouse
     * ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
     * │       │       │       │       │       │       │       │       │       │ ACL 0 │ ACL 1 │ ACL 2 │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │ WH UP │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │       │       │       │       │       │ WH DN │
     * ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │       │       │ BTN 3 │       │       │ WH L  │  UP   │ WH R  │
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │   Button 1    │    Button 2   │       │ LEFT  │ DOWN  │ RIGHT │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_MOUSE] = LAYOUT_preonic_2x2u(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, XXXXXXX, XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, \
        _______, XXXXXXX, XXXXXXX, XXXXXXX,          KC_BTN1, KC_BTN2,          XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R
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
     * ├───────┼───────┼───────┼───────┼───────┴───────┼───────┴───────┼───────┼───────┼───────┼───────┤
     * │       │       │       │       │               │               │       │       │       │       │
     * └───────┴───────┴───────┴───────┴───────────────┴───────────────┴───────┴───────┴───────┴───────┘
     */
    [_ADJUST] = LAYOUT_preonic_2x2u(
        _______, RESET,   DEBUG,   _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, AU_TOG,  _______, _______, _______, _______, _______, MU_MOD,  _______, _______, _______, _______, \
        _______, MUV_DE,  MUV_IN,  _______, _______, _______, _______, MU_TOG,  MI_TOG,  _______, _______, _______, \
        _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______
    )
    // clang-format on
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_ESC: {
            static uint8_t kc;
            static bool    is_alt_pressed;

            if (record->event.pressed) {
                is_alt_pressed = get_mods() & MOD_MASK_ALT;

                if (is_alt_pressed) {
                    kc = KC_GRAVE;
                } else {
                    kc = KC_ESCAPE;
                }

                register_code(kc);
            } else {
                unregister_code(kc);
            }
            break;
        }
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

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
        case LOW_SPC:
            return false;
        default:
            return true;
    }
}

// Track NumLock state
static bool numlock_state = false;

void keyboard_post_init_user(void) { numlock_state = host_keyboard_led_state().num_lock; }

bool led_update_user(led_t led_state) {
    numlock_state = led_state.num_lock;
    return true;
}

// Let's DANCE!
int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP;
        } else {
            return SINGLE_HOLD;
        }
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) {
            return DOUBLE_TAP;
        } else {
            return DOUBLE_HOLD;
        }
    }
    return 5;
}

static tap extra_state = {.is_press_action = true, .state = 0};

void extra_finished(qk_tap_dance_state_t *state, void *user_data) {
    extra_state.state = cur_dance(state);
    switch (extra_state.state) {
        case SINGLE_TAP:
            if (layer_state_is(_NUMPAD)) {
                if (numlock_state) {
                    tap_code(KC_NUMLOCK);
                }
                layer_off(_NUMPAD);
            } else {
                if (!numlock_state) {
                    tap_code(KC_NUMLOCK);
                }
                layer_move(_NUMPAD);
            }
            break;
        case SINGLE_HOLD:
            if (!numlock_state) {
                tap_code(KC_NUMLOCK);
            }
            layer_move(_NUMPAD);
            break;
        case DOUBLE_TAP:
            if (layer_state_is(_MOUSE)) {
                layer_off(_MOUSE);
            } else {
                layer_move(_MOUSE);
            }
            break;
        case DOUBLE_HOLD:
            layer_move(_MOUSE);
            break;
    }
}

void extra_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (extra_state.state) {
        case SINGLE_TAP:
            break;
        case SINGLE_HOLD:
            if (numlock_state) {
                tap_code(KC_NUMLOCK);
            }
            layer_off(_NUMPAD);
            break;
        case DOUBLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_off(_MOUSE);
            break;
    }
    extra_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {[EXTRA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, extra_finished, extra_reset)};
