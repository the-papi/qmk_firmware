/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum __layers {
    WIN_B,
    WIN_W,
    WIN_FN,
    MAC_B,
    MAC_W,
    MAC_FN
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_B] = LAYOUT_all( /* Base */
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12,   KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,KC_EQL,   KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,KC_RBRC,  KC_BSLS,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,KC_NUHS,  KC_ENT,           KC_PGUP,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(WIN_FN),KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_W] = LAYOUT_all( /* WASD/↑←↓→ */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_W,    _______,
        _______, _______, _______,                   _______,                            _______,MO(WIN_FN),_______,          KC_A,    KC_S,    KC_D),

    [WIN_FN] = LAYOUT_all( /* FN */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           RGB_MOD,
        _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______,           _______,
        _______, _______,TG(WIN_W),_______, _______, _______, _______, _______, KC_INS,  DF(MAC_B),KC_PSCR,_______, _______, RGB_MOD,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, RGB_MOD, RGB_TOG,           _______,
        _______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_MPRV, KC_MNXT, _______,          _______,  RGB_VAI, _______,
        _______, GU_TOGG, _______,                   KC_MPLY,                            _______, _______, _______,          RGB_HUD,  RGB_VAD, RGB_HUI),

    [MAC_B] = LAYOUT_all( /* Base */
        KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,   KC_F6,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,KC_VOLU,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,KC_EQL,   KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,KC_RBRC,  KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,KC_NUHS,  KC_ENT,           KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RGUI, MO(MAC_FN),KC_RCTL,        KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_W] = LAYOUT_all( /* WASD/↑←↓→ */
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_W,    _______,
        _______, _______, _______,                   _______,                            _______, MO(MAC_FN), _______,          KC_A,    KC_S,    KC_D),

    [MAC_FN] = LAYOUT_all( /* FN */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,            RGB_MOD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, _______,           _______,
        _______, _______,TG(MAC_W),_______, _______, _______, _______, _______, KC_INS,  DF(WIN_B),KC_PSCR,_______, _______, RGB_MOD,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, RGB_MOD, RGB_HUI,           _______,
        _______, _______, _______, _______, KC_CALC, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______,          _______,  RGB_VAI, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______,          RGB_SAD,  RGB_VAD, RGB_SAI)
};

// Key overrides to fix issues with Meta+accent keys in KDE
const key_override_t lgui_numpad_1 = ko_make_basic(MOD_MASK_GUI, KC_1, LGUI(KC_KP_1));
const key_override_t lgui_numpad_2 = ko_make_basic(MOD_MASK_GUI, KC_2, LGUI(KC_KP_2));
const key_override_t lgui_numpad_3 = ko_make_basic(MOD_MASK_GUI, KC_3, LGUI(KC_KP_3));
const key_override_t lgui_numpad_4 = ko_make_basic(MOD_MASK_GUI, KC_4, LGUI(KC_KP_4));
const key_override_t lgui_numpad_5 = ko_make_basic(MOD_MASK_GUI, KC_5, LGUI(KC_KP_5));
const key_override_t lgui_numpad_6 = ko_make_basic(MOD_MASK_GUI, KC_6, LGUI(KC_KP_6));
const key_override_t lgui_numpad_7 = ko_make_basic(MOD_MASK_GUI, KC_7, LGUI(KC_KP_7));
const key_override_t lgui_numpad_8 = ko_make_basic(MOD_MASK_GUI, KC_8, LGUI(KC_KP_8));
const key_override_t lgui_numpad_9 = ko_make_basic(MOD_MASK_GUI, KC_9, LGUI(KC_KP_9));
const key_override_t lgui_numpad_0 = ko_make_basic(MOD_MASK_GUI, KC_0, LGUI(KC_KP_0));

const key_override_t **key_overrides = (const key_override_t *[]){
    &lgui_numpad_1,
    &lgui_numpad_2,
    &lgui_numpad_3,
    &lgui_numpad_4,
    &lgui_numpad_5,
    &lgui_numpad_6,
    &lgui_numpad_7,
    &lgui_numpad_8,
    &lgui_numpad_9,
    &lgui_numpad_0,
    NULL // Null terminate the array of overrides!v
};


// clang-format off
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_W] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) }
};
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool win_fn_layer_active = false;

    // Check if WIN_FN layer is activated or deactivated
    if (layer_state_is(WIN_FN)) {
        win_fn_layer_active = true;
    } else {
        win_fn_layer_active = false;
    }

    // Check if WIN_FN is active and KC_1 is pressed
    if (win_fn_layer_active) {
        switch (keycode) {
            case KC_1:
                // Change RGB color to orange
                rgblight_sethsv(14, 255, 100);  // Set HSV values for orange color
                return false;  // Skip further processing of this keypress
            case KC_2:
                // Change RGB color to orange
                rgblight_sethsv(183, 255, 100);  // Set HSV values for orange color
                return false;  // Skip further processing of this keypress
            case KC_3:
                // Change RGB color to orange
                rgblight_sethsv(0, 0, 100);  // Set HSV values for orange color
                return false;  // Skip further processing of this keypress
        }
    }

    return true; // Process all other keypresses normally
}
