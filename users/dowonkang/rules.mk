MOUSEKEY_ENABLE = yes # Mouse keys
EXTRAKEY_ENABLE = yes # Audio control and System control

SRC += dowonkang.c

# Enable link time optimization to reduce firmware size
# See https://github.com/qmk/qmk_firmware/issues/3224#issuecomment-399769416
# EXTRAFLAGS += -flto
