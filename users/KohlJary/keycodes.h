#include QMK_KEYBOARD_H

bool process_record_user_keycodes(uint16_t keycode, keyrecord_t *record);
bool process_record_user_bit(uint16_t keycode, keyrecord_t *record);

enum USR_KEYCODES {
    //User keycodes
    EQ_NEQ = SAFE_RANGE,  //Equal/not equal comparison
    AND_OR,  //And/or operator
    LAMBDA,  //Lambda operator
    BRACES,  //Brace/curly brace
    PARBRA,  //Parentheses/brackets
    USR_QT,  //Single/double/back quote on one key
    USR_QTP, //Single/double/back quote pair on one key
    SLSH_BS, //Slash/backslash on one key
    ELPS,    //Ellipses
    MK_FLSH, //Make/flash keymap
    T_RSTRT, //Restart terminal process shortcut
    INV_1, INV_2, INV_3, INV_4, INV_5, //Inverted num keys
    INV_6, INV_7, INV_8, INV_9, INV_0,
    BIT_SAFE_RANGE
};

enum BIT_KEYCODES {
  BIT_0 = BIT_SAFE_RANGE,
  BIT_1,
  BIT_2,
  BIT_3,
  BIT_4,
  BIT_5,
  BIT_6,
  BIT_7,
  BIT_ENT,
  NEW_SAFE_RANGE
};

extern enum USR_KEYCODES usr_keycodes;
extern enum BIT_KEYCODES bit_keycodes;
