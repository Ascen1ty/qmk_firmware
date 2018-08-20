#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define _BA 0
#define _FN 1
#define _RST 2

#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum custom_keycodes {
  EMAIL = SAFE_RANGE,
  MEME,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
    case EMAIL:
		SEND_STRING(SS_LSFT("'")"my_email_address");
        return false;break;  	
    case MEME:
		SEND_STRING("mememacro");
        return false;break; 
	}
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BA: (Base) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]| Ret |
   * |-------------------------------------------------------.   |
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| # |urn|
   * |-----------------------------------------------------------|
   * |Shift | \ |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /| Shift  |
   * |-----------------------------------------------------------|
   * |Ctrl | WinK | Alt |      Space           | Alt | FN | Ctrl |
   * `-----------------------------------------------------------'
   *
   */
  [_BA] = LAYOUT_60_iso_split_rshift(\
    KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,        KC_BSPC,
    KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    KC_CAPS,      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,       KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,
    KC_LCTRL,       KC_LGUI, KC_LALT,                   KC_SPC,                                      XXXXXXX, KC_RALT, MO(1),       KC_RCTRL
  ),

  /* Keymap _FN: (Function) Second Layer
   * ,-----------------------------------------------------------.
   * |  ~ |F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| DEL   |
   * |-----------------------------------------------------------|
   * |   |   | UP |   |   |   |   |    | UP | | PRV|PLY|NXT|PRTS |
   * |-------------------------------------------------------.   |
   * |    | LFT | DWN | RGT |  |  | |LFT|DWN|RGT | MT| VUP | VDN |
   * |-----------------------------------------------------------|
   * |  SHFT |BL_TOGG|  |   |   |   |    |   |   |  |  |  | SHFT |
   * |-----------------------------------------------------------|
   * | CTRL| GUI |  ALT  |              |    |   FN2  |  | EMAIL |
   * `-----------------------------------------------------------'
   */
  [_FN] = LAYOUT_60_iso_split_rshift(\
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_DEL,
    XXXXXXX, XXXXXXX, KC_UP  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, KC_MPRV, KC_MPLY,  KC_MNXT,
    XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR,
    _______, BL_TOGG, BL_DEC, BL_INC, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
    _______, _______, _______,                    _______,                                     XXXXXXX, MO(2), _______, EMAIL
  ),
  
   /* Keymap _RST: (Reset) Third Layer
   * ,-----------------------------------------------------------.
   * |   |    |   |   |   |   |   |   |   |   |    |   |    |    |
   * |-----------------------------------------------------------|
   * |   |    |   |   |   |   |   |   |   |   |    |   |    |    |
   * |-------------------------------------------------------.   |
   * |    |   |   |   |    |    |   |     |   |   |    |   |     |
   * |-----------------------------------------------------------|
   * |    |   |   |   |   | | RESET |       |   |   |    |    |  |
   * |-----------------------------------------------------------|
   * |    |    |       |              |     |   |       |        |
   * `-----------------------------------------------------------'
   */
  [_RST] = LAYOUT_60_iso_split_rshift(\
    XXXXXXX, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET, XXXXXXX, XXXXXXX, XXXXXXX, MEME, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                                     XXXXXXX, _______, XXXXXXX, XXXXXXX
  ),
};
