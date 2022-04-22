/* Copyright Spaceman 2021
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
enum layers {
    // clang-format off
    _DEFAULT,
    _LOWER,
    _RAISE,
    _NUMPAD,
    _FN,
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

// Ctrl Combos
#define CMD_A   LCMD(KC_A)
#define CMD_S   LCMD(KC_S)
#define CMD_D   LCMD(KC_D)
#define CMD_F   LCMD(KC_F)
#define CMD_G   LCMD(KC_G)
#define CMD_Z   LCMD(KC_Z)
#define CMD_X   LCMD(KC_X)
#define CMD_C   LCMD(KC_C)
#define CMD_V   LCMD(KC_V)
#define CMD_B   LCMD(KC_B)

// Screenshot
#define SCRSH_A C(S(G(KC_3)))
#define SCRSH_P C(S(G(KC_4)))

// Web Functions
#define WBCK    LCMD(KC_LBRC)
#define WFWD    LCMD(KC_RBRC)
#define WTOP    LCMD(KC_UP)
#define WBTM    LCMD(KC_DOWN)
// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_DEFAULT] = LAYOUT_ortho_4x12(
        // clang-format off
        KC_TAB , LT_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        ESCTL  , LT_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_LCTL, FN     , KC_LOPT, KC_LCMD, LOWER  , KC_SPC , KC_SPC , RAISE  , KC_RCMD, KC_ROPT, FN     , KC_RCTL
        // clang-format on
        ),

    [_LOWER] = LAYOUT_ortho_4x12(
        // clang-format off
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL,
        CAPSCTL, CMD_A  , CMD_S  , CMD_D  , CMD_F  , CMD_G  , KC_QUOT, KC_MINS, KC_LBRC, KC_RBRC, _______, _______,
        _______, CMD_Z  , CMD_X  , CMD_C  , CMD_V  , CMD_B  , KC_BSLS, KC_EQL , _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        // clang-format on
        ),

    [_RAISE] = LAYOUT_ortho_4x12(
        // clang-format off
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL,
        _______, CMD_A  , CMD_S  , CMD_D  , CMD_F  , CMD_G  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
        _______, CMD_Z  , CMD_X  , CMD_C  , CMD_V  , CMD_B  , KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        // clang-format on
        ),

    [_NUMPAD] = LAYOUT_ortho_4x12(
        // clang-format off
        _______, _______, KC_HOME, KC_UP  , KC_END , KC_VOLU, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
        _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, KC_PAST, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PENT,
        _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PSLS, KC_P1  , KC_P2  , KC_P3  , KC_PEQL, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P0  , KC_P0  , KC_PDOT, _______, _______
        // clang-format on
        ),

    [_FN] = LAYOUT_ortho_4x12(
        // clang-format off
        _______, _______, WBCK   , WFWD   , WTOP   , SCRSH_A, KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,
        _______, _______, _______, _______, WBTM   , SCRSH_P, KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,
        _______, _______, _______, _______, _______, _______, KC_PAUS, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        // clang-format on
        ),

    [_ADJUST] = LAYOUT_ortho_4x12(
        // clang-format off
        RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
        // clang-format on
        ),

};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    static const char PROGMEM pancake_logo[] = {
        // clang-format off
        0x00, 0x00, 0x3e, 0x0a, 0x04, 0x00, 0x3c, 0x0a, 0x3c, 0x00, 0x3e, 0x0c, 0x18, 0x3e, 0x00, 0x3e,
        0x22, 0x22, 0x00, 0x3c, 0x0a, 0x3c, 0x00, 0x3e, 0x08, 0x36, 0x00, 0x3e, 0x2a, 0x22, 0x00, 0x00,
        0x00, 0x30, 0xc8, 0x84, 0x84, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x19, 0x1d,
        0x1d, 0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x84, 0x84, 0xc8, 0x30, 0x00,
        0x00, 0x63, 0x94, 0x08, 0x08, 0x11, 0x71, 0x17, 0x13, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x62,
        0xe2, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x31, 0x08, 0x08, 0x94, 0x63, 0x00,
        0x00, 0x00, 0x03, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x06, 0x02, 0x02, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00
        // clang-format on
    };
    oled_write_raw_P(pancake_logo, sizeof(pancake_logo));
    // Host Keyboard Layer Status
    oled_set_cursor(0, 4);
    oled_write_P(PSTR("\nLAYER\n-----\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("DEFLT\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("FUNCT\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("NUMPD\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
            break;
    }
    return false;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return state;
}
