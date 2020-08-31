#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum damas_layers {
    // clang-format off
    _BASE,
    _SYMBOLS,
    _NUMPAD,
    _NUMPADLOCK,
    _FUNCTION,
    _FUNCTIONLOCK,
    _ADJUST
    // clang-format on
};

// Shortcuts
#define FN_TAB LT(_FUNCTION, KC_TAB)
#define FN_ESC LT(_NUMPAD, KC_ESCAPE)
#define BASE TO(_BASE)
#define SYMBOLS MO(_SYMBOLS)
#define LOCK_NP TO(_NUMPADLOCK)
#define LOCK_FN TO(_FUNCTIONLOCK)
#define CTL_A LCTL(KC_A)
#define CTL_S LCTL(KC_S)
#define CTL_D LCTL(KC_D)
#define CTL_F LCTL(KC_F)
#define CTL_G LCTL(KC_G)
#define CTL_Z LCTL(KC_Z)
#define CTL_X LCTL(KC_X)
#define CTL_C LCTL(KC_C)
#define CTL_V LCTL(KC_V)
#define CTL_B LCTL(KC_B)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT(
        FN_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        FN_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,          SYMBOLS         ,          KC_SPC          , KC_RALT, KC_RGUI, KC_RCTL
    ),
    [_SYMBOLS] = LAYOUT(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL ,
        KC_CAPS, CTL_A  , CTL_S  , CTL_D  , CTL_F  , CTL_G  , KC_QUOT, KC_MINS, KC_LBRC, KC_RBRC, _______, _______,
        _______, CTL_Z  , CTL_X  , CTL_C  , CTL_V  , CTL_B  , KC_BSLS, KC_EQL , _______, _______, _______, _______,
        _______, _______, _______,          _______         ,          _______         , _______, _______, _______
    ),
    [_NUMPAD] = LAYOUT(
        _______, KC_HOME, KC_UP  , KC_END , KC_VOLU, XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, KC_BSPC,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, XXXXXXX, KC_TAB , KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, XXXXXXX, XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______,
        _______, _______, _______,          KC_SPC          ,          KC_P0           , KC_P0  , KC_PDOT, LOCK_NP
    ),
    [_NUMPADLOCK] = LAYOUT(
        _______, KC_HOME, KC_UP  , KC_END , KC_VOLU, XXXXXXX, KC_NLCK, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, KC_BSPC,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLD, XXXXXXX, KC_TAB , KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, XXXXXXX, XXXXXXX, KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______,
        _______, _______, _______,          KC_SPC          ,          KC_P0           , KC_P0  , KC_PDOT, UNLOCK
    ),
    [_FUNCTION] = LAYOUT(
        _______, KC_WBAK, KC_HOME, KC_PGUP, KC_VOLU, KC_PSCR, XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,
        _______, KC_WFWD, KC_END , KC_PGDN, KC_VOLD, KC_SLCK, XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PAUS, XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
        _______, _______, _______,          KC_SPC          ,          _______         , XXXXXXX, _______, LOCK_FN
    ),
    [_FUNCTIONLOCK] = LAYOUT(
        _______, KC_WBAK, KC_HOME, KC_PGUP, KC_VOLU, KC_PSCR, XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,
        _______, KC_WFWD, KC_END , KC_PGDN, KC_VOLD, KC_SLCK, XXXXXXX, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_PAUS, XXXXXXX, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,
        _______, _______, _______,          KC_SPC          ,          _______         , XXXXXXX, _______, BASE
    ),
    [_ADJUST] = LAYOUT(
        RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,          _______         ,          XXXXXXX         , _______, XXXXXXX, XXXXXXX
    )
    // clang-format on
};

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

uint32_t layer_state_set_user(uint32_t state) {
#ifdef RGBLIGHT_ENABLE
    uint8_t led0r = 0;
    uint8_t led0g = 0;
    uint8_t led0b = 0;
    if (layer_state_cmp(state, _ADJUST)) {
        led0r = 255;
        led0b = 255;
    }
    if (layer_state_cmp(state, _SYMBOLS)) {
        led0b = 255;
    }
    if (layer_state_cmp(state, _NUMPAD)) {
        led0g = 255;
    }
    if (layer_state_cmp(state, _FUNCTION)) {
        led0r = 255;
    }
    setrgb(led0r, led0g, led0b, (LED_TYPE *)&led[0]);
#endif  // RGBLIGHT_ENABLE
    return update_tri_layer_state(state, _NUMPAD, _SYMBOLS, _ADJUST);
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
