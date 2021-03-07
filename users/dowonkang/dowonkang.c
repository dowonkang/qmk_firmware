#include "dowonkang.h"

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return layer_state_set_keymap(state);
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t u_esc_timer;
    static uint16_t u_space_timer;
    switch (keycode) {
        case U_ESC:
            if (record->event.pressed) {
                u_esc_timer = timer_read();
                layer_on(_NUMPAD);
            } else {
                uint8_t mods = get_mods();
                layer_off(_NUMPAD);
                if (timer_elapsed(u_esc_timer) < TAPPING_TERM) {
                    if (mods & MOD_LALT || mods & MOD_LGUI) {
                        tap_code(KC_GRAVE);
                    } else {
                        tap_code(KC_ESCAPE);
                    }
                }
            }
            return false;
        case U_SPACE:
            if (record->event.pressed) {
                u_space_timer = timer_read();
                layer_on(_CTRL);
            } else {
                layer_off(_CTRL);
                if (timer_elapsed(u_space_timer) < TAPPING_TERM) {
                    tap_code(KC_SPACE);
                }
            }
            return false;
        default:
            break;
    }
    return process_record_keymap(keycode, record);
}
