#include "dowonkang.h"


// clang-format off
#define LTH LOW
#define LTL MT_ESC
#define LTR MT_TAB
#define RTH RSE
#define RTL MT_SPC
#define RTR MT_BSPC

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
                    ____, ____, ____,              XXXX, ____, XXXX
    ),

    [_NUMPAD] = LAYOUT_wrapper(
        ______NUMPAD_LEFT_1_________,              ______NUMPAD_RIGHT_1________,
        ______NUMPAD_LEFT_2_________,              ______NUMPAD_RIGHT_2________,
        ______NUMPAD_LEFT_3_________,              ______NUMPAD_RIGHT_3________,
                    ____, XXXX, ____,              SPC , P0  , PDOT
    ),

    [_FUNCTION] = LAYOUT_wrapper(
        ______FN_LEFT_1_____________,              ______FN_RIGHT_1____________,
        ______FN_LEFT_2_____________,              ______FN_RIGHT_2____________,
        ______FN_LEFT_3_____________,              ______FN_RIGHT_3____________,
                    ____, ____, ____,              ____, ____, ____
    ),

    [_MOUSE] = LAYOUT_wrapper(
        ______MOUSE_WHEEL_1_________,              ______MOUSE_CURSOR_1________,
        ______MOUSE_WHEEL_2_________,              ______MOUSE_CURSOR_2________,
        SFTL, XXXX, XXXX, XXXX, XXXX,              XXXX, ACL0, ACL1, ACL2, XXXX,
                    ALT , GUI , CTRL,              BTN3, BTN1, BTN2
    ),

    [_ADJUST] = LAYOUT_wrapper(
        ______FN_LEFT_1_____________,              ______RGB_CONTROL_1_________,
        ______FN_LEFT_2_____________,              ______RGB_CONTROL_2_________,
        ______FN_LEFT_3_____________,              ______RGB_CONTROL_3_________,
                    XXXX, ____, XXXX,              XXXX, ____, XXXX
    )
    // clang-format on
};
