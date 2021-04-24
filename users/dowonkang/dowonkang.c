#include "dowonkang.h"

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    return layer_state_set_keymap(state);
}

// __attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
//     return true;
// }

// uint8_t mod_state;

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     mod_state = get_mods();

//     static uint16_t low_esc_timer;
//     static uint16_t rse_spc_timer;
//     static uint16_t rse_ent_timer;

//     switch (keycode) {
//         case LOW_ESC:
//             if (record->event.pressed) {
//                 low_esc_timer = timer_read();
//                 layer_on(_LOWER);
//             } else {
//                 layer_off(_LOWER);
//                 if (timer_elapsed(low_esc_timer) < TAPPING_TERM) {
//                     if (mod_state & MOD_LALT || mod_state & MOD_LGUI) {
//                         tap_code(KC_GRAVE);
//                     } else {
//                         tap_code(KC_ESCAPE);
//                     }
//                 }
//             }
//             return false;

//         case RSE_SPC:
//             if (record->event.pressed) {
//                 rse_spc_timer = timer_read();
//                 layer_on(_RAISE);
//             } else {
//                 layer_off(_RAISE);
//                 if (timer_elapsed(rse_spc_timer) < TAPPING_TERM) {
//                     tap_code(KC_SPACE);
//                 }
//             }
//             return false;

//         case RSE_ENT:
//             if (record->event.pressed) {
//                 rse_ent_timer = timer_read();
//                 layer_on(_RAISE);
//             } else {
//                 layer_off(_RAISE);
//                 if (timer_elapsed(rse_ent_timer) < TAPPING_TERM) {
//                     tap_code(KC_ENTER);
//                 }
//             }
//             return false;

//         default:
//             return process_record_keymap(keycode, record);
//     }
// }

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_TAB:
        case CTL_SPC:
            return TAPPING_TERM - 50;

        default:
            return TAPPING_TERM;
    }
}

uint8_t cur_dance(qk_tap_dance_state_t *state) {
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
    return 8;
}
