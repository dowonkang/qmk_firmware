#pragma once

#define LAYOUT_ortho_36( \
    L00, L01, L02, L03, L04,           R00, R01, R02, R03, R04, \
    L10, L11, L12, L13, L14,           R10, R11, R12, R13, R14, \
    L20, L21, L22, L23, L24,           R20, R21, R22, R23, R24, \
                   L30, L31, L32, R30, R31, R32 \
) \
LAYOUT_ortho_4x12( \
    L00 , L01 , L02 , L03 , L04 , XXXX, XXXX, R00 , R01 , R02 , R03 , R04 , \
    L10 , L11 , L12 , L13 , L14 , XXXX, XXXX, R10 , R11 , R12 , R13 , R14 , \
    L20 , L21 , L22 , L23 , L24 , XXXX, XXXX, R20 , R21 , R22 , R23 , R24 , \
    XXXX, XXXX, XXXX, L30 , L31 , L32 , R30 , R31 , R32 , XXXX, XXXX, XXXX \
)

#define LAYOUT_wrapper(...) LAYOUT_ortho_36(__VA_ARGS__)

// Combo
#define COMBO_COUNT 11
#define COMBO_TERM 30

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP
