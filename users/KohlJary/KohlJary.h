#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"
#include "tapdance.h"
#include "keycodes.h"

//Layer names
enum LAYERS {
  L_B, //Base layer
  L_I, //Inverted number row layer
  L_G, //Gaming layer
  L_1, //Modified layer 1 (Quick symbols, macros, vim-key arrows, keyboard mouse commands)
  L_2, //Modified layer 2 (F-keys, number home row, media controls)
  L_S, //Settings layer (RGB settings, reflashing commands, debug utilities)
};

extern enum LAYERS layers;
