#include "ok60.h"


#define _KEYSTD 0
#define _KEYFUN 1
#define _KEYSPE 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* _KEYSTD
 * ,-------------------------------------------------------------------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |  =   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |  ]   |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |    ENTER    |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * |   LSHIFT    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   LSHIFT    |
 * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCTRL| LGUI | LALT |          SPACE                   |      |      |      |      | MENU | LCTRL |
 * `------+------+------+------+------+------+------+------+------+------+------+------+------+------'
 */
	[_KEYSTD] = KEYMAP_ANSI(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), TO(1), KC_MENU, KC_RCTL),

	[_KEYFUN] = KEYMAP_ANSI(
		RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		KC_TRNS, RGB_TOG, KC_UP, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_TRNS, KC_INS, KC_TILD,
		KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PENT,
		KC_LSFT, KC_PGUP, KC_PGDN, KC_TRNS, BL_TOGG, BL_INC, KC_MPLY, KC_MSTP, KC_VOLU, KC_VOLD, KC_MUTE, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT, TO(0), MO(2), TO(2), KC_RGUI, KC_RCTL),

	[_KEYSPE] = KEYMAP_ANSI(
		RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_LCTL, KC_LGUI, KC_LALT, TO(0), MO(3), TO(0), KC_RGUI, KC_RCTL),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	//keyevent_t event = record->event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
  rgblight_enable();
  rgblight_setrgb(0x00,  0xFF, 0xFF);
	led_init_ports();
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
      case _KEYSTD:
          rgblight_disable();
          break;
      case _KEYFUN:
          rgblight_enable();
          rgblight_setrgb (0x0D,  0xFF, 0x62);
          break;
      case _KEYSPE:
          rgblight_enable();
          rgblight_setrgb (0x0A, 0x5C, 0xFF);
          break;
      default: //  for any other layers, or the default layer
          rgblight_disable();
          break;
    }
  return state;
}
void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}
bool _t = false;
void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
	} else {
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
  rgblight_setrgb_at (0xFF, 0x80, 0x00, 7);

	} else {
  rgblight_setrgb_at (0x00, 0x00, 0x00, 7);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}
