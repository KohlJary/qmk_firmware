# Build Options
#   change yes to no to disable
#
CAPS_WORD_ENABLE = yes
REPEAT_KEY_ENABLE = yes
LEADER_ENABLE = yes
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
CUSTOM_MATRIX = lite

VPATH += drivers/gpio
SRC += matrix.c mcp23018.c
I2C_DRIVER_REQUIRED = yes

MCU_LDSCRIPT = STM32F303xB
