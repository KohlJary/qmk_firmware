# project specific files
SRC += config_led.c

#For platform and packs
ARM_ATSAM = SAMD51J18A
MCU = cortex-m4

# Bootloader selection
BOOTLOADER = md-boot

# Build Options
#   change yes to no to disable
#
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
VIRTSER_ENABLE = no         # USB Serial Driver
RAW_ENABLE = no             # Raw device

# Custom RGB matrix handling
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = custom

LAYOUTS = 65_ansi_blocker
