#pragma once
#ifndef USERSPACE_TAPDANCE
#define USERSPACE_TAPDANCE


//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0,
  TD_KC_A,
  TD_KC_B,
  TD_KC_C,
  TD_KC_D,
  TD_KC_F,
  TD_KC_G,
  TD_KC_S,
  TD_KC_T,
  TD_KC_V,
  TD_KC_X,
  TD_KC_Z,
  TD_MA_LSFT,
  TD_MA_LCTL,
  TD_MA_RSFT,
  TD_MA_RCTL,
  TD_MA_BSP,
  TD_MA_DEL,
  TD_F1_F2,
  TD_F3_F4,
  TD_F5_F6,
  TD_F7_F8,
  TD_F9_FA,
  TD_FB_FC,
};

// Tad Dance shorthands for LAYOUT definitions.
#define TD__ESC TD(TD_ESC_CAPS)
#define TD__KCA TD(TD_KC_A)
#define TD__KCB TD(TD_KC_B)
#define TD__KCC TD(TD_KC_C)
#define TD__KCD TD(TD_KC_D)
#define TD__KCF TD(TD_KC_F)
#define TD__KCG TD(TD_KC_G)
#define TD__KCS TD(TD_KC_S)
#define TD__KCT TD(TD_KC_T)
#define TD__KCV TD(TD_KC_V)
#define TD__KCX TD(TD_KC_X)
#define TD__KCZ TD(TD_KC_Z)
#define TD_MALS TD(TD_MA_LSFT)
#define TD_MALC TD(TD_MA_LCTL)
#define TD_MARS TD(TD_MA_RSFT)
#define TD_MARC TD(TD_MA_RCTL)
#define TD_MABS TD(TD_MA_BSP)
#define TD_MADE TD(TD_MA_DEL)
#define TD_F1_2 TD(TD_F1_F2)
#define TD_F3_4 TD(TD_F3_F4)
#define TD_F5_6 TD(TD_F5_F6)
#define TD_F7_8 TD(TD_F7_F8)
#define TD_F9_A TD(TD_F9_FA)
#define TD_FB_C TD(TD_FB_FC)


/*
 * onetwomod tap dance:
 *  - mod_ctrl + tap code
 *  - mod_ctrl + mod_shft + tap code
 */
typedef struct {
    uint16_t kc;
    bool mod_ctrl;
    bool mod_shft;
} utd_onetwomod_data_t;
void utd_onetwomod_finished (tap_dance_state_t *state, void *user_data);
void utd_onetwomod_reset (tap_dance_state_t *state, void *user_data);

#define ACTION_TAP_DANCE_ONETWOMOD(kc)                                            \
    {                                                                               \
        .fn        = {NULL, utd_onetwomod_finished, utd_onetwomod_reset, NULL}, \
        .user_data = (void *)&((utd_onetwomod_data_t){kc, false, false}),         \
    }


/*
 * Multiaction tap dance:
 *  - tap code
 *  - hold
 *  - double tap code
 *  - double tap hold
 * each action can be defined. use mod_ key codes for hold actions
 */
typedef struct {
    uint16_t single_tap;
    uint16_t single_hold;
    uint16_t double_tap;
    uint16_t double_hold;
} utd_multiaction_data_t;
void utd_multiaction_finished(tap_dance_state_t *state, void *user_data);
void utd_multiaction_reset(tap_dance_state_t *state, void *user_data);
#define ACTION_TAP_DANCE_MULTIACTION(st, sh, dt, dh)                                \
    {                                                                               \
        .fn        = {NULL, utd_multiaction_finished, utd_multiaction_reset, NULL}, \
        .user_data = (void *)&((utd_multiaction_data_t){st, sh, dt, dh}),           \
    }

#endif
