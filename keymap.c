/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"

enum custom_keycodes {
  MC_ARROW = SAFE_RANGE
};

enum combos {
  COMBO_LAYER_4,
  CB_ARROW,  // . + / = Flecha JS (= >)
  CB_BKSP    // H + J = Backspace (Opcional, muy cómodo)
};

const uint16_t PROGMEM space_enter_combo[] = {KC_SPC, KC_ENT, COMBO_END};
const uint16_t PROGMEM arrow_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM bksp_combo[]  = {KC_H, KC_J, COMBO_END};

combo_t key_combos[] = {
  [COMBO_LAYER_4] = COMBO(space_enter_combo, MO(4)),
  [CB_ARROW] = COMBO(arrow_combo, MC_ARROW),
  [CB_BKSP] = COMBO(bksp_combo, KC_BSPC),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MC_ARROW:
      if (record->event.pressed) {
        SEND_STRING("=>{}");
      }
      return false;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
KC_TAB, LGUI_T(KC_A),LALT_T(KC_S),LCTL_T(KC_D),LSFT_T(KC_F),KC_G,           KC_H,RSFT_T(KC_J),RCTL_T(KC_K),RALT_T(KC_L),RGUI_T(KC_SCLN),KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  MO(3),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENTER,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),
   [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_NUM,  KC_P7,   KC_P8,   KC_P9,  KC_ASTR, KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+---*-----|
      KC_CAPS,_______, _______, _______, _______, XXXXXXX,                      XXXXXXX,  KC_P4,   KC_P5,   KC_P6,  KC_PLUS, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_P1,   KC_P2,   KC_P3,  KC_PDOT, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______,  KC_SPC,     KC_ENT,   MO(3), KC_P0
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
_______, LGUI_T(KC_MINS), LALT_T(KC_EQL), LCTL_T(KC_LCBR), LSFT_T(KC_RCBR), KC_BSLS,                      KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT, KC_HOME,  KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_BSLS,                      KC_INS,KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD,                   KC_VOLU, RM_TOGG, RM_SATU, RM_VALU, RM_HUEU, RM_NEXT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, RM_SATD, RM_VALD, RM_HUED, RM_NEXT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

     [4] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------
      QK_BOOT, LALT(KC_F4), KC_UNDO, KC_CUT, KC_COPY, KC_PSTE,                      XXXXXXX, MS_BTN1, MS_UP, MS_BTN2, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_BSPC), XXXXXXX, XXXXXXX,                      XXXXXXX, MS_LEFT, MS_DOWN, MS_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )

};

#ifdef OLED_ENABLE

static void oled_render_layer_state(void) {
    // Línea 0: Información de Capa (Rellenar con espacios para borrar texto anterior)
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case 0: oled_write_P(PSTR("Qwerty    "), false); break;
        case 1: oled_write_P(PSTR("Calculator"), false); break;
        case 2: oled_write_P(PSTR("Symbols   "), false); break;
        case 3: oled_write_P(PSTR("FN        "), false); break;
        case 4: oled_write_P(PSTR("Admin     "), false); break;
        default: oled_write_P(PSTR("Undef     "), false); break;
    }

    // Línea 2: Estado de Bloqueo (CAPS & NUM)
    oled_set_cursor(0, 2);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("CAPS_LOCK"), led_usb_state.caps_lock);
    oled_write_P(PSTR(" & "), false);
    oled_write_P(PSTR("NUM_LOCK "), led_usb_state.num_lock);

    // Línea 3: Modificadores (SFT CTL ALT GUI)
    oled_set_cursor(0, 3);
    uint8_t current_mods = get_mods();
    oled_write_P(PSTR("SFT "), (current_mods & MOD_MASK_SHIFT));
    oled_write_P(PSTR("CTL "), (current_mods & MOD_MASK_CTRL));
    oled_write_P(PSTR("ALT "), (current_mods & MOD_MASK_ALT));
    oled_write_P(PSTR("GUI "), (current_mods & MOD_MASK_GUI));
}


void oled_render_logo(void) {
    static uint16_t scroll_timer = 0;
    static uint8_t scroll_offset = 0;
    
    // Texto con espacios para efecto de bucle suave
    const char *scroll_text = "   De los errores se aprende!!!  "; 
    const uint8_t text_len = 33; // Longitud total del texto (contando espacios)

    // Actualizar posición cada 250ms
    if (timer_elapsed(scroll_timer) > 250) {
        scroll_offset = (scroll_offset + 1) % text_len;
        scroll_timer = timer_read();
        
        oled_set_cursor(0, 0);
        oled_write_P(PSTR("@yariel_dev\n"), false);

        // Dibujar ventana de 21 caracteres (pantalla más ancha aprovechable)
        for (int i = 0; i < 21; i++) {
            uint8_t index = (scroll_offset + i) % text_len;
            oled_write_char(scroll_text[index], false);
        }
    }
}

bool oled_task_user(void) {
    if (!is_oled_on()) {
        return false;
    }
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE