// !!! DO NOT ADD #pragma once !!! //
/* #include <stdbool.h> */

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(my_cool_effect2)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// Enums
enum LED_GROUP {
  LED_R1 = 0,
  LED_R2,
  LED_R3,
  LED_R4,
  LED_R5,
  LED_NUMR,
  LED_HOME,
  LED_VIM,
};

// Helper functions

static int rgb_get_key_row(int x) {
  if (x >= 0 && x <= 13) {
    return LED_R1;
  }
  if (x >= 14 && x <= 28) {
    return LED_R2;
  }
  if (x >= 29 && x <= 42) {
    return LED_R3;
  }
  if (x >= 43 && x <= 56) {
    return LED_R4;
  }
  if (x >= 57 && x <= 65) {
    return LED_R5;
  }
  return -1;
}

static bool rgb_is_num_row(int x) {
  if (x >= 1 && x <= 12) {
    return true;
  }
  return false;
}

static bool rgb_is_home(int x) {
  //asdf
  if (x >= 31 && x <= 34) {
    return true;
  }
  //jkl;
  if (x >= 37 && x <= 40) {
    return true;
  }
  return false;
}

static bool rgb_is_vim(int x) {
  //hjkl
  if (x >= 36 && x <= 39) {
    return true;
  }
  return false;
}

// e.g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, RGB_YELLOW);
    switch (rgb_get_key_row(i)) {
      case LED_R1:
        rgb_matrix_set_color(i, RGB_RED);
        break;
      case LED_R2:
        rgb_matrix_set_color(i, RGB_ORANGE);
        break;
      case LED_R3:
        break;
      case LED_R4:
        rgb_matrix_set_color(i, RGB_GREEN);
        break;
      case LED_R5:
        rgb_matrix_set_color(i, RGB_BLUE);
        break;
    }
    if (rgb_is_num_row(i)) {
      rgb_matrix_set_color(i, RGB_MAGENTA);
    }
    if (rgb_is_home(i)) {
      rgb_matrix_set_color(i, RGB_CYAN);
    }
    if (rgb_is_vim(i)) {
      /* rgb_matrix_set_color(i, RGB_BLUE); */
    }
  }
  return rgb_matrix_check_finished_leds(led_max);
}

// e.g: A more complex effect, relying on external methods and state, with
// dedicated init and run methods
static uint8_t some_global_state;
static void my_cool_effect2_complex_init(effect_params_t* params) {
  some_global_state = 1;
}
static bool my_cool_effect2_complex_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    if (rgb_is_num_row(i)) {
      rgb_matrix_set_color(i, RGB_MAGENTA);
    }
    else {
      rgb_matrix_set_color(i, 0xff, some_global_state++, 0xff);
    }
  }
  return rgb_matrix_check_finished_leds(led_max);
}
static bool my_cool_effect2(effect_params_t* params) {
  if (params->init) my_cool_effect2_complex_init(params);
  return my_cool_effect2_complex_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
