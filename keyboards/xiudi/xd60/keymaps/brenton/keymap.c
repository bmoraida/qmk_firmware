#include QMK_KEYBOARD_H

// Macro section
enum custom_keycodes {
  KCLOGIN = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case KCLOGIN:
      if (record->event.pressed) {
        SEND_STRING("Smileclub2036");
      }
      return false;
  }
  return true;
}

// Combos
const uint16_t PROGMEM shift_caps[] = {KC_LSFT, KC_RSFT, COMBO_END};
combo_t key_combos[] = {
    COMBO(shift_caps, KC_CAPS),
};

//Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_60_ansi_split_bs_rshift_space(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSPC,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC,  KC_RBRC,           KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT,  _______,           KC_ENT,
        KC_LSFT, KC_DEL,  KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_RSFT,  KC_RSFT, KC_UP,    KC_SLSH,
        KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,                KC_SPC,          KC_RCTL, KC_RALT, MO(1),    KC_LEFT, KC_DOWN,  KC_RIGHT
    ),

    [1] = LAYOUT_60_ansi_split_bs_rshift_space(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_F13,  KC_DEL,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI,_______,_______,_______, KC_INS, _______, KC_PSCR, KC_SCRL,  KC_PAUS,          _______,
        _______, _______, _______, _______, _______,_______,KC_MUTE,KC_VOLD, KC_VOLU,KCLOGIN, _______, _______,  _______,          _______,
        _______, _______, _______, _______, _______,_______,_______,_______, _______,_______, _______, _______,  _______, KC_PGUP, _______,
        _______, _______, _______,          _______,                _______,        _______,  _______, MO(1),    KC_HOME, KC_PGDN, KC_END
    )
};
