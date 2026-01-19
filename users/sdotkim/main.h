#pragma once
#include QMK_KEYBOARD_H
#ifndef USERSPACE_MAIN
#define USERSPACE_MAIN


// Layer shorthand
enum layer {
  _BASE,
  _RAISE,
  _LOWER,
  _A,
  _META
};

// Layer modifiers.
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LT_A LT(_A, KC_A)
#define META MO(_META)

enum custom_keycodes {
  KC_MAKE = SAFE_RANGE,
  ALT_TAB,
  ALT_GRV,
};

#endif
