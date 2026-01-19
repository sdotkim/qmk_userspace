#include QMK_KEYBOARD_H
#include "main.h"
#include "tapdance.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( \
    TD__ESC,       KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          TD_F1_2,           TD_F7_8,       KC_6,          KC_7,          KC_8,          KC_9,          KC_0,          KC_TAB, \
    XXXXXXX,       KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          TD_F3_4,           TD_F9_A,       KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          XXXXXXX,\
    TD_MALS,       KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          TD_F5_6,           TD_FB_C,       KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       TD_MARS,\
    TD_MALC,       KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          LOWER,             RAISE,         KC_N,          KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,       TD_MARC,\
                                                 KC_LALT,       KC_LGUI,       TD_MABS,       KC_SPC,            KC_ENT,        TD_MADE,       META,          KC_RALT \
  ),
  [_RAISE] = LAYOUT( \
    _______,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,           XXXXXXX,       LALT(KC_LEFT), LCTL(KC_T),    LCS(KC_T),     LALT(KC_RGHT), XXXXXXX,       _______,\
    _______,       KC_EXLM,       KC_AT,         KC_HASH,       KC_DLR,        KC_PERC,       XXXXXXX,           XXXXXXX,       LSAG(KC_LEFT), LGUI(KC_PGUP), LGUI(KC_PGDN), LSAG(KC_RGHT), XXXXXXX,       _______,\
    _______,       KC_CIRC,       KC_AMPR,       KC_ASTR,       KC_LPRN,       KC_RPRN,       XXXXXXX,           XXXXXXX,       KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       XXXXXXX,       _______,\
    _______,       KC_MINS,       KC_UNDS,       KC_EQL,        KC_PLUS,       XXXXXXX,       XXXXXXX,           RAISE,         KC_HOME,       KC_PGDN,       KC_PGUP,       KC_END,        XXXXXXX,       _______,\
                                                 KC_LBRC,       KC_RBRC,       KC_LCBR,       KC_RCBR,           XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX \
  ),
  [_LOWER] = LAYOUT( \
    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,           XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       _______,\
    XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       TD__KCT,       XXXXXXX,           XXXXXXX,       KC_MINS,       KC_7,          KC_8,          KC_9,          KC_PLUS,       _______,\
    XXXXXXX,       TD__KCA,       TD__KCS,       TD__KCD,       TD__KCF,       TD__KCG,       XXXXXXX,           XXXXXXX,       KC_PAST,       KC_4,          KC_5,          KC_6,          KC_0,          _______,\
    KC_LGUI,       TD__KCZ,       TD__KCX,       TD__KCC,       TD__KCV,       TD__KCB,       LOWER,             KC_LALT,       KC_PSLS,       KC_1,          KC_2,          KC_3,          KC_DOT,        _______,\
                                                 XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,           KC_GRV,        KC_TILD,       KC_QUOT,       KC_DQUO \
  ),
  [_META] = LAYOUT( \
    XXXXXXX,       LAG(KC_P1),    LAG(KC_P2),    LAG(KC_P3),    LAG(KC_P4),    LAG(KC_P5),    TO(0),             TO(5),         XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       TO(0),\
    XXXXXXX,       LAG(KC_P6),    LAG(KC_P7),    LAG(KC_P8),    LAG(KC_P9),    LAG(KC_P0),    TO(1),             TO(6),         XXXXXXX,       LCAG(KC_7),    LCAG(KC_8),    LCAG(KC_9),    XXXXXXX,       XXXXXXX,\
    XXXXXXX,       LCG(KC_P1),    LCG(KC_P2),    LCG(KC_P3),    LCG(KC_P4),    LCG(KC_P5),    TO(3),             TO(7),         XXXXXXX,       LCAG(KC_4),    LCAG(KC_5),    LCAG(KC_6),    LCAG(KC_0),    XXXXXXX,\
    XXXXXXX,       LCG(KC_P6),    LCG(KC_P7),    LCG(KC_P8),    LCG(KC_P9),    LCG(KC_P0),    TO(4),             TO(8),         XXXXXXX,       LCAG(KC_1),    LCAG(KC_2),    LCAG(KC_3),    XXXXXXX,       KC_SLEP,\
                                                 _______,       _______,       _______,       _______,           _______,       _______,       _______,       _______ \
  ),
};
