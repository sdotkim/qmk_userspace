#include "quantum.h"
#include "tapdance.h"

tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_KC_A] = ACTION_TAP_DANCE_ONETWOMOD(KC_A),
  [TD_KC_B] = ACTION_TAP_DANCE_ONETWOMOD(KC_B),
  [TD_KC_C] = ACTION_TAP_DANCE_ONETWOMOD(KC_C),
  [TD_KC_D] = ACTION_TAP_DANCE_ONETWOMOD(KC_D),
  [TD_KC_F] = ACTION_TAP_DANCE_ONETWOMOD(KC_F),
  [TD_KC_G] = ACTION_TAP_DANCE_ONETWOMOD(KC_G),
  [TD_KC_S] = ACTION_TAP_DANCE_ONETWOMOD(KC_S),
  [TD_KC_T] = ACTION_TAP_DANCE_ONETWOMOD(KC_T),
  [TD_KC_V] = ACTION_TAP_DANCE_ONETWOMOD(KC_V),
  [TD_KC_X] = ACTION_TAP_DANCE_ONETWOMOD(KC_X),
  [TD_KC_Z] = ACTION_TAP_DANCE_ONETWOMOD(KC_Z),
  [TD_MA_LSFT] = ACTION_TAP_DANCE_MULTIACTION(KC_TAB, KC_LSFT, KC_ESC, KC_NO),
  [TD_MA_LCTL] = ACTION_TAP_DANCE_MULTIACTION(KC_GRV, KC_LCTL, KC_TILD, KC_NO),
  [TD_MA_RSFT] = ACTION_TAP_DANCE_MULTIACTION(KC_QUOT, KC_RSFT, KC_DQUO, KC_NO),
  [TD_MA_RCTL] = ACTION_TAP_DANCE_MULTIACTION(KC_BSLS, KC_RCTL, KC_ESC, KC_NO),
  [TD_MA_BSP] = ACTION_TAP_DANCE_MULTIACTION(KC_BSPC, KC_LALT, KC_ESC, KC_BSPC),
  [TD_MA_DEL] = ACTION_TAP_DANCE_MULTIACTION(KC_DEL, KC_RALT, KC_ESC, KC_DEL),
  [TD_F1_F2] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F2),
  [TD_F3_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F4),
  [TD_F5_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F6),
  [TD_F7_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_F8),
  [TD_F9_FA] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F10),
  [TD_FB_FC] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_F12),
};


void utd_onetwomod_finished (tap_dance_state_t *state, void *user_data) {
    utd_onetwomod_data_t *data = (utd_onetwomod_data_t *)user_data;
    switch (state->count) {
        case 1:
            register_code(KC_LCTL);
            register_code(data->kc);
            data->mod_ctrl = true;
            break;
        case 2:
            register_code(KC_LCTL);
            register_code(KC_LSFT);
            register_code(data->kc);
            data->mod_ctrl = true;
            data->mod_shft = true;
            break;
    }
}

void utd_onetwomod_reset (tap_dance_state_t *state, void *user_data) {
    utd_onetwomod_data_t *data = (utd_onetwomod_data_t *)user_data;
    unregister_code16(data->kc);
    if (data->mod_ctrl) unregister_code16(KC_LCTL);
    if (data->mod_shft) unregister_code16(KC_LSFT);
}

void utd_multiaction_finished(tap_dance_state_t *state, void *user_data) {
    utd_multiaction_data_t *data = (utd_multiaction_data_t *)user_data;

    if (state->count == 1) {
        // Single tap
        if (state->interrupted || !state->pressed) register_code(data->single_tap);
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return register_code(data->single_hold);
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) { tap_code(data->single_tap); register_code(data->single_tap); }
        else if (state->pressed) register_code(data->double_hold);
        else return register_code(data->double_tap);
    }
}

void utd_multiaction_reset(tap_dance_state_t *state, void *user_data) {
    utd_multiaction_data_t *data = (utd_multiaction_data_t *)user_data;
    if (data->single_tap) unregister_code(data->single_tap);
    if (data->single_hold) unregister_code(data->single_hold);
    if (data->double_tap) unregister_code(data->double_tap);
    if (data->double_hold) unregister_code(data->double_hold);
}
