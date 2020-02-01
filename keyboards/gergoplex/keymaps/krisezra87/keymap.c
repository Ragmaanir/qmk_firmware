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

  // Pad
  [VV] = COMBO(vv_combo, KC_MUTE),
  [LR] = COMBO(lr_combo, KC_BTN3),
};

// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
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
 *       | LALT |DEL/ALT|BSPC(SYM)|      | SPC(NUM)|ENT|RCTL|
 *       '------------------------'      '------------------'
 */
[BASE] = LAYOUT_gergoplex(
    KC_Q, KC_W, KC_E, KC_R, KC_T,  	              KC_Y, KC_U, KC_I,    KC_O,   KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,                 KC_H, KC_J, KC_K,    KC_L,   KC_SCLN,
    MT(MOD_RSFT, KC_Z),KC_X, KC_C, KC_V, KC_B,    KC_N, KC_M, KC_COMM, KC_DOT, MT(MOD_RSFT, KC_SLSH),

   	KC_LALT, KC_DEL,  LT(SYMB,KC_BSPC), // Left
  	LT(NUMB, KC_SPC), KC_ENT, KC_RCTL  // Right
    ),

/* Keymap 1: Symbols/Function Layer
 * ,-----------------------------.       ,--------------------------------.
 * |  !   |  @  |  #  |  $  |  %  |      |  ^  |  &  |  *  |  (  |    )   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * |  `   |  0  |  (  |  {  |  [  |      |  ]  |  }  |  )  |  $ PIPE  '   |
 * |------+-----+-----+-----+-----|      |--------------------------------|
 * | SHIFT| F1  |  F2 | F3  | F4  |      |  F5 | F6  | F7  | F8  | SHIFT  |
 * `------+-----+-----+------+----'      `--------------------------------'
 *  .-----------------.                   .------------------.
 *  | F9 | F10 |      |                   |  ~  | F11 | F12  |
 *  '-----------------'                   '------------------'
 */

[SYMB] = LAYOUT_gergoplex(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_GRV,  KC_0,    KC_LPRN, KC_LCBR, KC_LBRC,   KC_RBRC, KC_RCBR, KC_RPRN, KC_DLR,  KC_QUOT,
    KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,     KC_F6,   KC_F7,   KC_F8, KC_RSFT,
                      KC_F9,   KC_F10,  KC_TRNS,   KC_TILD,  KC_F11,  KC_F12
    ),

/* Keymap 2: Pad layer
 * ,-----------------------------.       ,-------------------------------.
 * |  1   |  2  |  3  |  4  |  5  |      |  6  |  7  |  8  |  9  |   0   |
 * |------+-----+-----+-----+-----|      |-------------------------------|
 * |      |     | SKP |VOLUP| LMB |      | LFT | DWN | UP  | RGT |       |
 * |------+-----+-----+MUTE-+-MMB-|      |-------------------------------|
 * | SHIFT|     | PLY |VOLDN| RMB |      |MLFT | MDWN| MUP | MRGT| SHIFT |
 * `------+-----+-----+-----+-----'      `-------------------------------'
 *  .-----------------.                   .-----------------.
 *  |     |    |  =   |                   |     |     |     |
 *  '-----------------'                   '-----------------'
 */
[NUMB] = LAYOUT_gergoplex(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, 	   KC_6,  	KC_7, 	 KC_8,    KC_9,    KC_0,
    KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLU, KC_BTN2,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
    KC_LSFT, KC_TRNS, KC_MPLY, KC_VOLD, KC_BTN1,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_RSFT,
       		          KC_TRNS, KC_TRNS, KC_EQL,   KC_TRNS,KC_TRNS,KC_TRNS
    )
};
