#include "dowonkang.h"

enum user_keycodes {
    // clang-format off
    USPC = SAFE_RANGE
    // clang-format on
};

#define UTAB LT(_FUNCTION, KC_TAB)
#define UESC LT(_NUMPAD, KC_ESCAPE)

// clang-format off
#define ______BASE_RIGHT_2_LT_SCLN__ KC_H   , KC_J   , KC_K   , KC_L   , LT_SCLN
#define ______LOW_RIGHT_2_____       KC_QUOT, KC_MINS, KC_LBRC, KC_RBRC
#define ______LOW_RIGHT_3_____       KC_BSLS, KC_EQL , _______, _______
#define ______RSE_RIGHT_1___________ KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS
#define ______RSE_RIGHT_2___________ KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX
#define ______RSE_RIGHT_3___________ KC_HOME, KC_PGDN, KC_PGUP, KC_END , XXXXXXX
// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        UTAB, ______QWERTY_LEFT_1_________, ______QWERTY_RIGHT_1________, BSPC,
        UESC, ______QWERTY_LEFT_2_________, ______BASE_RIGHT_2_LT_SCLN__, ENT ,
        SFTL, ______QWERTY_LEFT_3_________, ______QWERTY_RIGHT_3________, SFTR,
        CTRL, GUI , ALT ,       LOW       ,       USPC      , ALT , GUIR, CTLR
    ),
    [_LOWER] = LAYOUT_wrapper(
        GRV , ______NUMBER_12345__________, ______NUMBER_67890__________, DEL ,
        ESC , ____________________________, ______LOW_RIGHT_2_____, ____, ____,
        ____, ____________________________, ______LOW_RIGHT_3_____, ____, ____,
        ____, ____, ____,       ____      ,       SPC       , ____, ____, ____
    ),
    [_RAISE] = LAYOUT_wrapper(
        GRV , ______NUMBER_12345__________, ______NUMBER_67890__________, DEL ,
        ESC , ____________________________, ______RSE_RIGHT_2___________, ____,
        ____, ____, ____, ____, ____, ____, ______RSE_RIGHT_3___________, ____,
        ____, ____, ____,       ____      ,       ____      , ____, ____, ____
    ),
    [_NUMPAD] = LAYOUT_wrapper(
        ____, WBCK, _UP_, WFWD, HOME, XXXX, ______NUMPAD_RIGHT_1________, ____,
        ____, LEFT, _DN_, RGHT, END , XXXX, ______NUMPAD_RIGHT_2________, ____,
        ____, XXXX, XXXX, XXXX, XXXX, XXXX, ______NUMPAD_RIGHT_3________, ____,
        ____, ____, ____,       SPC       ,       P0        , PDOT, ____, ____
    ),
    [_FUNCTION] = LAYOUT_wrapper(
        ____, MPRV, MPLY, MNXT, VOLU, XXXX, ______FN_RIGHT_1____________, INS ,
        ____, XXXX, XXXX, XXXX, VOLD, XXXX, ______FN_RIGHT_2____________, ____,
        ____, XXXX, XXXX, XXXX, MUTE, XXXX, ______FN_RIGHT_3____________, ____,
        ____, ____, ____,       ____      ,       SPC       , ____, ____, ____
    ),
    [_MOUSE] = LAYOUT_wrapper(
        ____, ______MOUSE_WHEEL_1_________, ______MOUSE_CURSOR_1________, ____,
        ____, ______MOUSE_WHEEL_2_________, ______MOUSE_CURSOR_2________, ____,
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX, ACL0, ACL1, ACL2, XXXX, ____,
        ____, ____, ____,       BTN3      ,       BTN1       , BTN2, ____, ____
    ),
    [_ADJUST] = LAYOUT_wrapper(
        RSET, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        CAPS, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        XXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        XXXX, XXXX, XXXX,       ____      ,       ____      , ALTG, MENU, XXXX
    )
    // clang-format on
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t u_spc_timer;
    switch (keycode) {
        case USPC:
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
