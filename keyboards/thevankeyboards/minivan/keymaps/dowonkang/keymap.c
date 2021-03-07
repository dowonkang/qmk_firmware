#include "dowonkang.h"

enum custom_keycodes {
    // clang-format off
    RSE_SPC = NEW_SAFE_RANGE
    // clang-format on
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT(
        FN_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        U_ESC  , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,           LOWER          ,          RSE_SPC         , KC_RALT, KC_RGUI, KC_RCTL
    ),
    [_LOWER] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_ESC , CTRL_A , CTRL_S , CTRL_D , CTRL_F , CTRL_G , KC_QUOT, KC_MINS, KC_LBRC, KC_RBRC, _______, _______,
        _______, CTRL_Z , CTRL_X , CTRL_C , CTRL_V , CTRL_B , KC_BSLS, KC_EQL , _______, _______, _______, _______,
        _______, _______, _______,          _______         ,          KC_SPC          , _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_ESC , _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX, _______,
        _______, _______, _______,          _______         ,          _______         , _______, _______, _______
    ),
    [_FUNCTION] = LAYOUT(
        _______, KC_WBAK, KC_HOME, KC_WFWD, KC_WREF, KC_VOLU, KC_PSCR, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_INS ,
        KC_ESC , XXXXXXX, KC_END , KC_WSCH, KC_WSTP, KC_VOLD, KC_SLCK, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_WHOM, KC_MUTE, KC_PAUS, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
        _______, _______, _______,          _______         ,          KC_SPC          , _______, _______, _______
    ),
    [_NUMPAD] = LAYOUT(
        _______, KC_HOME, KC_UP  , KC_END , KC_PGUP, XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_TAB , KC_P4  , KC_P5  , KC_P6  , KC_PPLS, KC_PENT,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, _______,
        _______, _______, _______,          KC_SPC          ,          KC_P0           , KC_PDOT, _______, _______
    ),
    [_ADJUST] = LAYOUT(
        RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,          _______         ,          XXXXXXX         , _______, XXXXXXX, XXXXXXX
    )
    // clang-format on
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    static uint16_t u_spc_timer;
    switch (keycode) {
        case RSE_SPC:
            if (record->event.pressed) {
                u_spc_timer = timer_read();
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
                if (timer_elapsed(u_spc_timer) < TAPPING_TERM) {
                    tap_code(KC_SPACE);
                }
            }
            return false;
        default:
            return true;
    }
    return true;
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    // Set up RGB effects on _only_ the third LED (index 2)
    rgblight_set_effect_range(2, 1);
    // Set LED effects to breathing mode in a tealish blue color
    rgblight_sethsv_noeeprom(38, 191, 198);
    rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);

    // Init the first two LEDs to a static color
    setrgb(0, 0, 0, (LED_TYPE *)&led[0]);
    setrgb(0, 0, 0, (LED_TYPE *)&led[1]);
    rgblight_set();
#endif  // RGBLIGHT_ENABLE
}

layer_state_t layer_state_set_keymap(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    uint8_t led0r = 0;
    uint8_t led0g = 0;
    uint8_t led0b = 0;
    if (layer_state_cmp(state, _ADJUST)) {
        led0g = 255;
        led0b = 255;
    }
    if (layer_state_cmp(state, _LOWER)) {
        led0g = 255;
    }
    if (layer_state_cmp(state, _RAISE)) {
        led0b = 255;
    }
    if (layer_state_cmp(state, _NUMPAD)) {
        led0r = 255;
    }
    if (layer_state_cmp(state, _FUNCTION)) {
        led0r = 255;
        led0g = 255;
    }
    setrgb(led0r, led0g, led0b, (LED_TYPE *)&led[0]);
#endif  // RGBLIGHT_ENABLE
    return state;
}

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_ENABLE
    uint8_t led1r = 0;
    uint8_t led1g = 0;
    uint8_t led1b = 0;

    if (led_state.caps_lock) {
        led1r = 255;
    } else {
        led1r = 0;
    }
    if (led_state.num_lock) {
        led1g = 255;
    } else {
        led1g = 0;
    }
    if (led_state.scroll_lock) {
        led1b = 255;
    } else {
        led1b = 0;
    }

    setrgb(led1r, led1g, led1b, (LED_TYPE *)&led[1]);
    rgblight_set();
#endif  // RGBLIGHT_ENABLE
    return true;
}
