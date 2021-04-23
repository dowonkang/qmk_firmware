#include "dowonkang.h"

// Tap dance
typedef struct {
    // clang-format off
    bool is_press_action;
    uint8_t state;
    // clang-format on
} tap;

enum {
    // clang-format off
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD
    // clang-format on
};

enum {
    // clang-format off
    LEFT_THUMB_LEFT,
    RIGHT_THUMB_RIGHT
    // clang-format on
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

void ltl_finished(qk_tap_dance_state_t *state, void *user_data);
void ltl_reset(qk_tap_dance_state_t *state, void *user_data);
void rtr_finished(qk_tap_dance_state_t *state, void *user_data);
void rtr_reset(qk_tap_dance_state_t *state, void *user_data);

// clang-format off
#define LTH LOW
#define LTL TD(LEFT_THUMB_LEFT)
#define LTR CTL_TAB
#define RTH RSE
#define RTL CTL_SPC
#define RTR TD(RIGHT_THUMB_RIGHT)

// clang-format on

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE] = LAYOUT_wrapper(
        ______BASE_LEFT_1___________,              ______BASE_RIGHT_1__________,
        ______BASE_LEFT_2___________,              ______BASE_RIGHT_2__________,
        ______BASE_LEFT_3___________,              ______BASE_RIGHT_3__________,
                    LTL , LTH , LTR ,              RTL , RTH , RTR
    ),

    [_LOWER] = LAYOUT_wrapper(
        ______LOWER_LEFT_1__________,              ______LOWER_RIGHT_1_________,
        ______LOWER_LEFT_2__________,              ______LOWER_RIGHT_2_________,
        ______LOWER_LEFT_3__________,              ______LOWER_RIGHT_3_________,
                    XXXX, ____, XXXX,              SPC , ____, BSPC
    ),

    [_RAISE] = LAYOUT_wrapper(
        ______RAISE_LEFT_1__________,              ______RAISE_RIGHT_1_________,
        ______RAISE_LEFT_2__________,              ______RAISE_RIGHT_2_________,
        ______RAISE_LEFT_3__________,              ______RAISE_RIGHT_3_________,
                    ESC , ____, TAB ,              XXXX, ____, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ______NUMPAD_LEFT_1_________,              ______NUMPAD_RIGHT_1________,
        ______NUMPAD_LEFT_2_________,              ______NUMPAD_RIGHT_2________,
        ______NUMPAD_LEFT_3_________,              ______NUMPAD_RIGHT_3________,
                    ____, XXXX, XXXX,              SPC , P0  , PDOT
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ______FN_LEFT_1_____________,              ______FN_RIGHT_1____________,
        ______FN_LEFT_2_____________,              ______FN_RIGHT_2____________,
        ______FN_LEFT_3_____________,              ______FN_RIGHT_3____________,
                    ESC , ____, TAB ,              XXXX, XXXX, ____
    ),
    // clang-format on
};

// Let's DANCE!
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

static tap ltl_tap_state = {.is_press_action = true, .state = 0};

void ltl_finished(qk_tap_dance_state_t *state, void *user_data) {
    ltl_tap_state.state = cur_dance(state);
    switch (ltl_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code(KC_ESCAPE);
            break;
        case DOUBLE_HOLD:
            layer_on(_NUMPAD);
            break;
        default:
            break;
    }
}

void ltl_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (ltl_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_ESCAPE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_ESCAPE);
            break;
        case DOUBLE_HOLD:
            layer_off(_NUMPAD);
            break;
        default:
            break;
    }
    ltl_tap_state.state = 0;
}

static tap rtr_tap_state = {.is_press_action = true, .state = 0};

void rtr_finished(qk_tap_dance_state_t *state, void *user_data) {
    rtr_tap_state.state = cur_dance(state);
    switch (rtr_tap_state.state) {
        case SINGLE_TAP:
            register_code(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            register_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            register_code(KC_BSPACE);
            break;
        case DOUBLE_HOLD:
            layer_on(_FUNCTION);
            break;
        default:
            break;
    }
}

void rtr_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (rtr_tap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_BSPACE);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LALT);
            break;
        case DOUBLE_TAP:
            unregister_code(KC_BSPACE);
            break;
        case DOUBLE_HOLD:
            layer_off(_FUNCTION);
            break;
        default:
            break;
    }
    rtr_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // clang-format off
    [LEFT_THUMB_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ltl_finished, ltl_reset),
    [RIGHT_THUMB_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rtr_finished, rtr_reset)
    // clang-format on
};
