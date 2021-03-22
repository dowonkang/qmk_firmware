#pragma once

// needed for the rotary encoder as volume knob
#define TAP_CODE_DELAY 10

// Adjust encoder resolution
#define ENCODER_RESOLUTION 2

// Layout wrapper
#define LAYOUT_wrapper(...) LAYOUT_preonic_1x2uC(__VA_ARGS__)
