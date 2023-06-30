#include QMK_KEYBOARD_H

#pragma once

enum keyboard_keycodes {
    //User keycodes
    EQ_NEQ = QK_KB_0,  //Equal/not equal comparison
    LTE_GTE, //Less than equal to/greater than equal to
    INC_DEC, //Increment/decrement operator
    AND_OR,  //And/or operator
    LAMBDA,  //Lambda operator
    QUE_EXC, //!/? on one key
    AT_HASH, //@/# on one key
    DOL_CIR, //$/^ on one key
    PER_AST, //%/* on one key
    MK_FLSH, //Make/flash keymap
    T_RSTRT, //Restart terminal process shortcut
};
