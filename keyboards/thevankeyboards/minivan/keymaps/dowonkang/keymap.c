#include "dowonkang.h"

enum user_keycodes {
    // clang-format off
    USPC = NEW_SAFE_RANGE
    // clang-format on
};

#define UTAB LT(_FUNCTION, KC_TAB)
#define UESC LT(_NUMPAD, KC_ESCAPE)
#define LOCK LAYER_LOCK
#define LCLR LAYER_CLEAR

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        UTAB, ______BASE_LEFT_1___________, ______BASE_RIGHT_1__________, BSPC,
        UESC, ______BASE_LEFT_2___________, ______BASE_RIGHT_2__________, ENT ,
        SFTL, ______BASE_LEFT_3___________, ______BASE_RIGHT_3__________, SFTR,
        CTRL, GUI , ALT ,       LOW       ,       USPC      , ALT , GUIR, CTLR
    ),
    [_LOWER] = LAYOUT_wrapper(
        GRV , ______LOWER_LEFT_1__________, ______LOWER_RIGHT_1_________, DEL ,
        ESC , ______LOWER_LEFT_2__________, ______LOWER_RIGHT_2_________, ____,
        ____, ______LOWER_LEFT_3__________, ______LOWER_RIGHT_3_________, ____,
        ____, ____, ____,       ____      ,       ____      , ____, ____, ____
    ),
    [_RAISE] = LAYOUT_wrapper(
        GRV , ______RAISE_LEFT_1__________, ______RAISE_RIGHT_1_________, DEL ,
        ESC , ______RAISE_LEFT_2__________, ______RAISE_RIGHT_2_________, ____,
        ____, ______RAISE_LEFT_3__________, ______RAISE_RIGHT_3_________, ____,
        ____, ____, ____,       ____      ,       ____      , ____, ____, ____
    ),
    [_NUMPAD] = LAYOUT_wrapper(
        ____, ______NUMPAD_LEFT_1_________, ______NUMPAD_RIGHT_1________, ____,
        ____, ______NUMPAD_LEFT_2_________, ______NUMPAD_RIGHT_2________, ____,
        ____, ______NUMPAD_LEFT_3_________, ______NUMPAD_RIGHT_3________, ____,
        ____, ____, ____,       SPC       ,       P0        , PDOT, ____, ____
    ),
    [_FUNCTION] = LAYOUT_wrapper(
        ____, ______FN_LEFT_1_____________, ______FN_RIGHT_1____________, INS ,
        ____, ______FN_LEFT_2_____________, ______FN_RIGHT_2____________, ____,
        ____, ______FN_LEFT_3_____________, ______FN_RIGHT_3____________, ____,
        ____, ____, ____,       ____      ,       SPC       , ____, ____, ____
    ),
    [_MOUSE] = LAYOUT_wrapper(
        ____, ______MOUSE_WHEEL_1_________, ______MOUSE_CURSOR_1________, ____,
        ____, ______MOUSE_WHEEL_2_________, ______MOUSE_CURSOR_2________, ____,
        ____, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX, ACL0, ACL1, ACL2, XXXX, ____,
        ____, ____, ____,       BTN3      ,       BTN1       , BTN2, ____, ____
    ),
    [_GAME] = LAYOUT_wrapper(
        TAB , ______QWERTY_LEFT_1_________, ______QWERTY_RIGHT_1________, BSPC,
        ESC , ______QWERTY_LEFT_2_________, ______QWERTY_RIGHT_2________, ENT ,
        SFTL, ______QWERTY_LEFT_3_________, ______QWERTY_RIGHT_3________, SFTR,
        CTRL, XXXX, ALT ,       SPC       ,       GEXT      , ALTG, XXXX, CTLR
    ),
    [_GAMEXTRA] = LAYOUT_wrapper(
        TAB , ______NUMBER_12345__________, ______FN_RIGHT_1____________, BSPC,
        ESC , ______NUMBER_67890__________, ______FN_RIGHT_2____________, ENT ,
        SFTL, ______QWERTY_LEFT_3_________, ______FN_RIGHT_3____________, SFTR,
        CTRL, ____, ALT ,       SPC       ,       ____      , ALTG, CTLR, LCLR
    ),
    [_ADJUST] = LAYOUT_wrapper(
        RSET, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        CAPS, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        XXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXXXXXXXXXXXXXXXXXXXXXXXXXX, XXXX,
        XXXX, XXXX, XXXX,       ____      ,       ____      , ALTG, MENU, GAME
    ),
    // clang-format on
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
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
        led0g = 192;
        led0b = 203;
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
