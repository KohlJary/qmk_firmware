#pragma once

#include "leader.h"
#include "quantum.h"
#include "action.h"
#include "version.h"
#include "tapdance.h"
#include "keycodes.h"

//Layer names
enum LAYERS {
  L_B, //Base layer
  L_J, //Japanese input layer
  L_G, //Gaming layer
  L_I, //Inverted number layer
  L_F, //F-key number layer
  L_1, //Modified layer 1 (Quick symbols, macros, vim-key arrows, keyboard mouse commands)
  L_2, //Modified layer 2 (F-keys, number home row, media controls)
  L_S, //Settings layer (RGB settings, reflashing commands, debug utilities)
  L_8, //Byteboard prototyping layer
};

extern enum LAYERS layers;
