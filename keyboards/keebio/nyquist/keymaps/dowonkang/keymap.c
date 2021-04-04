#include "dowonkang.h"

#define LTH LOW
#define LTL NUM_TAB
#define LTR CTL_ESC
#define RTH RSE
#define RTL SPC
#define RTR FN_BSPC

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
                    XXXX, ____, XXXX,              ____, ____, BSPC
    ),

    [_RAISE] = LAYOUT_wrapper(
        ______RAISE_LEFT_1__________,              ______RAISE_RIGHT_1_________,
        ______RAISE_LEFT_2__________,              ______RAISE_RIGHT_2_________,
        ______RAISE_LEFT_3__________,              ______RAISE_RIGHT_3_________,
                    TAB , ____, ESC ,              XXXX, ____, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ______NUMPAD_LEFT_1_________,              ______NUMPAD_RIGHT_1________,
        ______NUMPAD_LEFT_2_________,              ______NUMPAD_RIGHT_2________,
        ______NUMPAD_LEFT_3_________,              ______NUMPAD_RIGHT_3________,
                    ____, ____, XXXX,              P0  , PDOT, XXXX
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ______FN_LEFT_1_____________,              ______FN_RIGHT_1____________,
        ______FN_LEFT_2_____________,              ______FN_RIGHT_2____________,
        ______FN_LEFT_3_____________,              ______FN_RIGHT_3____________,
                    ____, ____, ____,              XXXX, XXXX, ____
    ),
    // clang-format on
};
