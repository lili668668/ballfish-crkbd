#include QMK_KEYBOARD_H

enum crkbd_layers {
    _QWERT,
    _NUMBER,
    _RIGHTARROW,
    _FN,
    _COPY,
    _MOUSE,
    _LEFTARROW,
    _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERT] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, MO(2), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_SCLN, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, KC_RALT, KC_LGUI, KC_SPC, KC_ENT, MO(1), KC_LSFT),
	[_NUMBER] = LAYOUT_split_3x6_3(KC_TAB, KC_7, KC_8, KC_9, KC_0, KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, MO(3), KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, KC_LCTL, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_ESC, KC_RALT, KC_LGUI, KC_SPC, KC_ENT, KC_TRNS, KC_LSFT),
	[_RIGHTARROW] = LAYOUT_split_3x6_3(KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_GRV, KC_UP, KC_NO, KC_HOME, KC_PGUP, KC_DEL, KC_TRNS, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_PGDN, KC_PSCR, KC_LCTL, TG(5), TG(6), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_RALT, KC_LGUI, KC_SPC, KC_ENT, MO(3), KC_LSFT),
	[_FN] = LAYOUT_split_3x6_3(KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_LCTL, KC_NO, KC_NO, KC_NO, TG(7), TG(4), KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, KC_ESC, KC_RALT, KC_LGUI, KC_SPC, KC_ENT, KC_TRNS, KC_LSFT),
	[_COPY] = LAYOUT_split_3x6_3(TG(4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_C, KC_V, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_ENT, KC_NO, KC_NO, KC_NO),
	[_MOUSE] = LAYOUT_split_3x6_3(KC_TAB, KC_BTN1, KC_MS_U, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_WBAK, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_PGDN, KC_NO, KC_WFWD, KC_VOLD, KC_VOLU, KC_WH_L, KC_WH_D, KC_WH_R, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LGUI, TG(5), KC_NO, KC_NO, KC_NO),
	[_LEFTARROW] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_UP, KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(6), KC_NO, KC_NO, KC_NO),
	[_RGB] = LAYOUT_split_3x6_3(KC_NO, BL_TOGG, BL_STEP, BL_BRTG, BL_ON, BL_INC, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_NO, BL_OFF, BL_DEC, KC_NO, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, KC_NO, RGB_M_P, RGB_M_B, RGB_M_SW, RGB_M_SN, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_NO, KC_NO, KC_NO, KC_NO, TG(7), KC_NO, KC_NO, KC_NO)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}

void render_logo(void) {
    static const char PROGMEM logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x30, 0x78, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0xe0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xf0, 0xe0, 
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xf0, 0xf0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xf0, 0xf0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 
0xf0, 0xfc, 0xfe, 0xfe, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xef, 0xdf, 0xbf, 0x7e, 0xfe, 
0xfe, 0xfc, 0xfc, 0xf8, 0xf0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x70, 0x70, 0x71, 0x39, 0x1b, 0x01, 0xff, 0xff, 0x83, 0x83, 0x83, 0xff, 
0xff, 0x83, 0x83, 0xff, 0xff, 0x07, 0x07, 0x0e, 0xfc, 0xfc, 0x18, 0x38, 0x30, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x18, 0x79, 0xff, 
0xff, 0x9f, 0x03, 0x03, 0x03, 0x83, 0x83, 0xdf, 0xff, 0x63, 0x03, 0xfb, 0xfb, 0x03, 0x1f, 0x1f, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xfb, 0xf7, 0x77, 0x77, 0x31, 0x30, 0xf1, 
0xf1, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x18, 0x1c, 0x1c, 0x0e, 0x8e, 0xc6, 0xff, 0xff, 0x83, 0x83, 0x83, 0xff, 
0xff, 0x83, 0x83, 0xff, 0xff, 0x0e, 0x1c, 0x1c, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 
0x1d, 0x9f, 0xdf, 0xfe, 0x1c, 0xdd, 0xdf, 0x9d, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0x1c, 0x1c, 0xdc, 
0xfc, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, 0xfc, 0xfc, 0xe3, 
0xe3, 0xe3, 0xe3, 0xff, 0x3f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x0c, 0x1c, 0x0e, 0x0e, 0x07, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1c, 
0x0e, 0x07, 0x03, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x03, 0x00, 0x0f, 0x0f, 0x02, 0x07, 0x03, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x0f, 0x0f, 0x0f, 0x1f, 0x1f, 0x1f, 
0x0f, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
    oled_write_raw_P(logo, sizeof(logo));
}

#define KEYLOG_LEN 5

uint8_t current_layer = 0;
layer_state_t layer_state_set_user(layer_state_t state) {
	current_layer = get_highest_layer(state);
	return state;
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Lyout"), false);
    switch (current_layer) {
      case _QWERT:
        oled_write_P(PSTR("QWERT"), false);
        break;
      case _NUMBER:
        oled_write_P(PSTR("NUMBR"), false);
        break;
      case _RIGHTARROW:
        oled_write_P(PSTR("RARRW"), false);
        break;
      case _FN:
        oled_write_P(PSTR("FUNCT"), false);
        break;
      case _COPY:
        oled_write_P(PSTR("COPY "), false);
        break;
      case _MOUSE:
        oled_write_P(PSTR("MOUSE"), false);
        break;
      case _LEFTARROW:
        oled_write_P(PSTR("LARRW"), false);
        break;
      case _RGB:
        oled_write_P(PSTR("RGB  "), false);
        break;
    }
}

void render_status_main(void) {
    render_default_layer_state();
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status_main();
  } else {
    render_logo();
  }
}
#endif
