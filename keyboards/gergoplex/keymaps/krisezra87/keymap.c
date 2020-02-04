/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // numbers/motion

// Combos
enum combos {
  QW,IO,OP,
  AS,HJ,JK,KL,LSCLN,
  FV,GB,
  DQ,
  FT,FF,FS,FN,FE,
  VV,LR
};

// NOTE: If you're using MT,LT or anything you must
// define it here. Note this if you change your layout!

/* Keymap 0: Basic layer
 *
 * ,-----------------------------.       ,--------------------------------.
 * |    TAB    |     |     |      |      |     |     |    MINS  BSLH      |
 * |-----+-----+-----+-----+------|      |--------------------------------|
 * |    ESC    |     |     |      |      |    LES   ESC   GRT    |        |
 * |-----+-----+-----+-RMB-+-LMB--|      |--------------------------------|
 * |     |     |     |     |      |      |     |     |     |     |        |
 * `-----+-----+-----+-----+------'      `--------------------------------'
 *  .-------------------------.           .-----------------.
 *  |        |       |        |           |     |     |     |
 *  '-------------------------'           '-----------------'
 */
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM as_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {KC_L, KC_SCLN, COMBO_END};

const uint16_t PROGMEM fv_combo[] = {KC_F, KC_V, COMBO_END};
const uint16_t PROGMEM gb_combo[] = {KC_G, KC_B, COMBO_END};

const uint16_t PROGMEM dq_combo[] = {KC_DLR, KC_QUOT, COMBO_END};

const uint16_t PROGMEM ft_combo[] = {KC_F1, KC_F3, COMBO_END};
const uint16_t PROGMEM ff_combo[] = {KC_F3, KC_F5, COMBO_END};
const uint16_t PROGMEM fs_combo[] = {KC_F5, KC_F7, COMBO_END};
const uint16_t PROGMEM fn_combo[] = {KC_F8, KC_F10, COMBO_END};
const uint16_t PROGMEM fe_combo[] = {KC_F10, KC_F12, COMBO_END};

const uint16_t PROGMEM vv_combo[] = {KC_VOLU, KC_VOLD, COMBO_END};
const uint16_t PROGMEM lr_combo[] = {KC_BTN1, KC_BTN2, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // Horizontal Chords
  [QW] = COMBO(qw_combo, KC_TAB),
  [IO] = COMBO(io_combo, KC_MINS),
  [OP] = COMBO(op_combo, KC_BSLS),

  [AS] = COMBO(as_combo, KC_ESC),
  [HJ] = COMBO(hj_combo, KC_LT),
  [JK] = COMBO(jk_combo, KC_ESC),
  [KL] = COMBO(kl_combo, KC_GT),
  [LSCLN] = COMBO(lscln_combo, KC_QUOT),

  // Vertical
  [GB] = COMBO(gb_combo, KC_BTN1),
  [FV] = COMBO(fv_combo, KC_BTN2),

  // Symbols
  [DQ] = COMBO(dq_combo, KC_PIPE),
  [FT] = COMBO(ft_combo, KC_F2),
  [FF] = COMBO(ff_combo, KC_F4),
  [FS] = COMBO(fs_combo, KC_F6),
  [FN] = COMBO(fn_combo, KC_F9),
  [FE] = COMBO(fe_combo, KC_F11),

  // Pad
  [VV] = COMBO(vv_combo, KC_MUTE),
  [LR] = COMBO(lr_combo, KC_BTN3),
};

enum custom_keycodes {
    ALT_ONE=SAFE_RANGE,
    ALT_TWO,
    ALT_THREE,
    ALT_FOUR,
    ALT_FIVE,
    ALT_SIX,
    ALT_SEVEN,
    ALT_EIGHT,
    ALT_NINE,
    ALT_ZERO
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_ONE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("1"));
            }
            break;

        case ALT_TWO:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("2"));
            }
            break;

        case ALT_THREE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("3"));
            }
            break;

        case ALT_FOUR:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("4"));
            }
            break;

        case ALT_FIVE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("5"));
            }
            break;

        case ALT_SIX:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("6"));
            }
            break;

        case ALT_SEVEN:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("7"));
            }
            break;

        case ALT_EIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("8"));
            }
            break;

        case ALT_NINE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("9"));
            }
            break;

        case ALT_ZERO:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("0"));
            }
            break;
    }
    return true;
};

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = {{ALT_ONE, ALT_TWO}},

/* Keymap 0: Basic layer
 *
 * ,------------------------------.      ,--------------------------------.
 * |   Q  |  W  |  E  |  R  |  T  |      |  Y  |  U  |  I  |  O  |    P   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |    A |  S  |  D  |  F  |  G  |      |  H  |  J  |  K  |  L  | CTRL/; |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |SHFT/Z|  X  |  C  |  V  |  B  |      |  N  |  M  |  <  |  >  | SHFT/? |
 * `------+-----+-----+-----+-----'      `--------------------------------'
 *       .------------------------.      .------------------.
 *       | LALT|DEL/LCTL|BSPC(SYM)|      | SPC(NUM)|ENT|RCTL|
 *       '------------------------'      '------------------'
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q, KC_W, KC_E, KC_R, KC_T,  	              KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    MT(MOD_RSFT, KC_Z),KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

   	KC_LALT, MT(MOD_LCTL,KC_DEL),  LT(SYMB,KC_BSPC), // Left
  	LT(NUMB, KC_SPC), KC_ENT, KC_RCTL  // Right
    ),

/* Keymap 1: Symbols/Function Layer
 * ,-----------------------------.       ,----------------------------------.
 * | ALT1 | ALT2| ALT3| ALT4| ALT5|      | ALT6| ALT7 | ALT8 | ALT9| ALT0   |
 * |------+-----+-----+-----+-----|      |----------------------------------|
 * |  `   |  0  |  (  |  {  |  [  |      |  ]  |  }   |  )   |  $ PIPE  '   |
 * |------+-----+-----+-----+-----|      |----------------------------------|
 * | SHIFT| F1 F2 F3 F4 F5 F6 F7  |      | F8 F9 F10 F11 F12 |     | SHIFT  |
 * `------+-----+-----+-----+-----'      `----------------------------------'
 *              .-----------------.      .-------------------.
 *              |     |     |     |      |  ~  |      |      |
 *              '-----------------'      '-------------------'
 */

[SYMB] = LAYOUT_gergoplex(
    ALT_ONE, ALT_TWO, ALT_THREE, ALT_FOUR, ALT_FIVE,   ALT_SIX, ALT_SEVEN, ALT_EIGHT, ALT_NINE, ALT_ZERO,
    KC_GRV,  KC_0,    KC_LPRN,   KC_LCBR,  KC_LBRC,    KC_RBRC, KC_RCBR,   KC_RPRN,   KC_DLR,   KC_QUOT,
    KC_LSFT, KC_F1,   KC_F3,     KC_F5,    KC_F7,      KC_F8,   KC_F10,    KC_F12,    KC_TRNS,  KC_RSFT,
                      KC_TRNS,   KC_TRNS,  KC_TRNS,    KC_TILD, KC_TRNS,   KC_TRNS
    ),

/* Keymap 2: Pad layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |      |     | SKP |VOLUP| LMB |      | LFT | DWN | UP  | RGT |       |
 * |------+-----+-----+MUTE-+-MMB-|      |-------------------------------|
 * | SHIFT|     | PLY |VOLDN| RMB |      |MLFT | MDWN| MUP | MRGT| SHIFT |
 * `------+-----+-----+-----+-----'      `-------------------------------'
 *              .-----------------.      .-----------------.
 *              |     |    |  =   |      |     |     |     |
 *              '-----------------'      '-----------------'
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 	   KC_6,  	KC_7, 	 KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLU, KC_BTN2,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_LSFT, KC_TRNS, KC_MPLY, KC_VOLD, KC_BTN1,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_RSFT,
       		          KC_TRNS, KC_TRNS, KC_EQL,   KC_TRNS,KC_TRNS,KC_TRNS
    )
};
