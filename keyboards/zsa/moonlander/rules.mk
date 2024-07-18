# Build Options
#   change yes to no to disable
#
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
LEADER_ENABLE = yes
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
CUSTOM_MATRIX = lite

# project specific files
SRC += matrix.c
I2C_DRIVER_REQUIRED = yes
