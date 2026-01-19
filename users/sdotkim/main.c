#include "quantum.h"
#include "main.h"

bool is_sticky_alt_active = false; // ADD this near the beginning of keymap.c
uint16_t sticky_alt_timer = 0;     // we will be using them soon.

__attribute__ ((weak)) bool process_record_keymap (uint16_t keycode, keyrecord_t *record) {
  return true;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  switch (keycode) {
    case KC_MAKE:  // Compiles the firmware, and adds the flash command based on keyboard bootloader
      if (!pressed) {
        send_string_with_delay_P(PSTR("make " QMK_KEYBOARD ":" QMK_KEYMAP
#if defined(__ARM__)
                     ":dfu-util"
#elif defined(BOOTLOADER_DFU)
                     ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
                     ":teensy"
#elif defined(BOOTLOADER_CATERINA)
                     ":avrdude"
#endif // bootloader options
                     SS_TAP(X_ENTER)), 3);
      }
      return false;
      break;
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_sticky_alt_active) {
          is_sticky_alt_active = true;
          register_code(KC_LALT);
        }
        sticky_alt_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case ALT_GRV:
      if (record->event.pressed) {
        if (!is_sticky_alt_active) {
          is_sticky_alt_active = true;
          register_code(KC_LALT);
        }
        sticky_alt_timer = timer_read();
        register_code(KC_GRV);
      } else {
        unregister_code(KC_GRV);
      }
      break;
  }
  return true;
};

void matrix_scan_user(void) { // The very important timer.
  if (is_sticky_alt_active) {
    if (timer_elapsed(sticky_alt_timer) > 500) {
      unregister_code(KC_LALT);
      is_sticky_alt_active = false;
    }
  }
}
