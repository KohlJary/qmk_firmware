#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(MO(3), KC_BSPC, KC_DEL, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_P4, KC_P5, KC_P6, KC_NO, KC_P1, KC_P2, KC_P3, KC_PENT, KC_P0, KC_NO, KC_PDOT, KC_NO),

[_LAYER1] = LAYOUT(KC_TRNS, KC_CUT, KC_COPY, KC_PASTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, S(KC_TAB), KC_PGUP, KC_TAB, KC_VOLU, KC_WWW_BACK, KC_F5, KC_WWW_FORWARD, KC_NO, KC_CUT, KC_COPY, KC_PASTE, KC_VOLD, KC_UNDO, KC_NO, KC_FIND, KC_NO),

[_LAYER2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LWIN(KC_7), LWIN(KC_8), LWIN(KC_9), KC_TRNS, LWIN(KC_4), LWIN(KC_5), LWIN(KC_6), KC_NO, LWIN(KC_1), LWIN(KC_2), LWIN(KC_3), KC_TRNS, LWIN(KC_TAB), KC_NO, KC_GRV, KC_NO),

[_LAYER3] = LAYOUT(KC_TRNS, TG(1), TG(2), KC_MPLY, RGB_MOD, RGB_VAI, KC_MPRV, KC_MUTE, RGB_RMOD, RGB_VAD, KC_MNXT, KC_VOLU, RGB_SAI, RGB_SPI, RGB_HUI, KC_NO, RGB_SAD, RGB_SPD, RGB_HUD, KC_VOLD, RGB_TOG, KC_NO, KC_MNXT, KC_NO) 

};
