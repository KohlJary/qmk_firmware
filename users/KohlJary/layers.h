#pragma once

//Layer names
enum LAYERS {
  L_B, //Base layer
  L_J, //Japanese input layer
  L_G, //Gaming layer
  L_I, //Inverted number layer
  L_F, //F-key number layer
  L_1, //Modified layer 1 (Quick symbols, macros, vim-key arrows, keyboard mouse commands)
  L_2, //Modified layer 2 (F-keys, number home row, media controls)
  L_3, //Modified layer 2 (Macros)
  L_S, //Settings layer (RGB settings, reflashing commands, debug utilities)
  L_8, //Byteboard prototyping layer
};

extern enum LAYERS layers;

