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

void render_crkbd_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
  render_crkbd_logo();
}
#endif
