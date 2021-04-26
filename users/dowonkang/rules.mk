COMMAND_ENABLE = no
UNICODE_ENABLE = no
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

SRC += dowonkang.c

# Enable link time optimization to reduce firmware size
# See https://github.com/qmk/qmk_firmware/issues/3224#issuecomment-399769416
EXTRAFLAGS += -flto
