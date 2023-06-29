#include QMK_KEYBOARD_H

#pragma once

enum keyboard_keycodes {
    //User keycodes
    EQ_NEQ = QK_KB_0,  //Equal/not equal comparison
    LTE_GTE, //Less than equal to/greater than equal to
    INC_DEC, //Increment/decrement operator
    AND_OR,  //And/or operator
    LAMBDA,  //Lambda operator
    USR_QT,  //Single/double/back quote on one key
    SLSH_BS, //Slash/backslash on one key
    QUE_EXC, //!/? on one key
    AT_HASH, //@/# on one key
    DOL_CIR, //$/^ on one key
    PER_AST, //%/* on one key
    CLN_DSH, //Semicolon/colon/-/_ on one key
    BSP_DEL, //Backspace/delete on one key
    MK_FLSH, //Make/flash keymap
    T_RSTRT, //Restart terminal process shortcut
    INV_1, INV_2, INV_3, INV_4, INV_5, //Inverted num keys
    INV_6, INV_7, INV_8, INV_9, INV_0,
};
