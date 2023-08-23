#pragma once

//Layer names
enum LAYERS {
  LYB, //Base layer
  LYG, //Gaming layer
  LYI, //Inverted number layer
  LYN, //Numpad layer
  LYF, //F-key number layer
  LYM, //Mouse-key layer
  LY1, //Modified layer 1 (Quick symbols, macros, vim-key arrows, keyboard mouse commands)
  LY2, //Modified layer 2 (F-keys, number home row, media controls)
  LY3, //Modified layer 2 (Macros)
  LYS, //Settings layer (RGB settings, reflashing commands, debug utilities)
  LY8, //Byteboard prototyping layer
};

extern enum LAYERS layers;

