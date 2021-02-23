#pragma once

// Macro doesn't work when link time optimization is enabled
// See https://github.com/qmk/qmk_firmware/issues/3224#issuecomment-399769416
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// 1000MHz polling rate
#define USB_POLLING_INTERVAL_MS 1

// Tap-Hold stuff
// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
