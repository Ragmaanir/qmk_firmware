
#include QMK_KEYBOARD_H

// #define _X_ KC_NO
// #define _T_ KC_TRNS
#define KC___ KC_NO
#define KC__T_ KC_TRNS

#define KC_LSQBR  KC_LBRACKET
#define KC_RSQBR  KC_RBRACKET

// https://www.reddit.com/r/olkb/comments/72wuxs/qmk_best_way_to_setup_a_key_to_switch_to_layer_a/

enum Layer {
  LAYER_0 = 0,
  LAYER_1,
  LAYER_2,
  LAYER_3,
  LAYER_A,
  LAYER_S,
  LAYER_F,
  LAYER_G
};

enum CustomKeycodes {
    KC_xA = SAFE_RANGE,
    KC_xS,
    KC_xF,
    KC_xG,
    KC_MO_1,
    KC_MO_2,
    KC_MO_3,
    KC_MO_4
};

static uint16_t tap_timers[4];

// remember whether a key was pressed in a tap-hold layer so the tapping-function is skipped
bool key_pressed_in_taphold_layer = false;

#define NO_FALLTHROUGH false
#define FALLTHROUGH true

bool hold_or_fallthrough(bool pressed, uint16_t kc, uint8_t held_layer, uint16_t mod_bits, uint16_t *p_timer) {
  if(pressed){
    *p_timer = timer_read();
    layer_on(held_layer);
    register_mods(mod_bits);
    key_pressed_in_taphold_layer = false;
    return FALLTHROUGH;
  } else {
    unregister_mods(mod_bits);
    layer_off(held_layer);

    // use default behavior if key tapped and no other key pressed while held
    // return timer_elapsed(*p_timer) < 300 && !key_pressed_in_taphold_layer;
    if(timer_elapsed(*p_timer) < 300 && !key_pressed_in_taphold_layer) {
      tap_code16(kc);
    }

    return NO_FALLTHROUGH;
  }
}

void layer_momentarily(uint8_t layer, bool state) {
  state ? layer_on(layer) : layer_off(layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool pressed = record->event.pressed;

  switch(keycode) {
    case KC_xA:
      return hold_or_fallthrough(pressed, KC_A, LAYER_A, MOD_BIT(KC_LCTRL), &tap_timers[0]);
    case KC_xS:
      return hold_or_fallthrough(pressed, KC_S, LAYER_S, 0, &tap_timers[0]);
    case KC_xF:
      return hold_or_fallthrough(pressed, KC_F, LAYER_F, 0, &tap_timers[0]);
    case KC_xG:
      return hold_or_fallthrough(pressed, KC_G, LAYER_G, 0, &tap_timers[0]);
    case KC_MO_1:
      layer_momentarily(1, pressed);
      return NO_FALLTHROUGH;
    case KC_MO_2:
      layer_momentarily(2, pressed);
      return NO_FALLTHROUGH;
    case KC_MO_3:
      layer_momentarily(3, pressed);
      return NO_FALLTHROUGH;
    case KC_MO_4:
      layer_momentarily(4, pressed);
      return NO_FALLTHROUGH;
    default:
      key_pressed_in_taphold_layer = true;
      return FALLTHROUGH; // use default
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_0] = LAYOUT_kc(
    B,  W,  E, R,  T,      Z, U, I, O, P,
    xA, xS, D, xF, xG,     H, J, K, L, Y,
    __, X,  C, V,  B,      N, M, Q, P, N,

   	__, MO_1, MO_3,           LSFT, MO_2, MO_4
  ),

  [LAYER_1] = LAYOUT_kc(
    PAUSE, __, SPACE, TAB, ESC,        __,   BSPC, UP,   DEL,   __,
    __,   TAB, __,    ENT, LWIN,       HOME, LEFT, DOWN, RIGHT, END,
    __,   TAB, __,    __,  __,         __,   BSPC, __,   __,    __,

    __, _T_, __,                       LSFT, __,   __
  ),

  [LAYER_2] = LAYOUT_kc(
    AMPR,  PIPE, UNDS, EQL,  COLN,      DLR,  LSQBR, RSQBR, LT, HASH,
    EXLM,  COMM, DOT,  MINS, ASTR,      DQT,  LPRN,  RPRN,  GT, PERC,
    QUES,  SCLN, BSLS, PLUS, SLASH,     QUOT, LCBR,  RCBR,  AT, TILD,

    __, __, LCTRL,                    __, _T_, __
  ),

  [LAYER_3] = LAYOUT_kc(
    COMM, DOT, 0, PLUS, MINS,         __,  BSPC,  9, DEL, __,
    1,    2,   3,   4,  SPACE,        ENT, 5,     6, 7,   8,
    __,   __, __, BSLS, ASTR,         __,  __,   __, __,  __,

    _T_, __, __,                      LSFT, LCTRL, LALT
  ),

  /* Copy-paste, select all, save, undo, redo, ... */
  [LAYER_A] = LAYOUT_kc(
    __,  __, __, __, __,     A,  N,  S,  O,  __,
    _T_, __, __, C,  V,      P,  __, X,  Z,  Y,
    __,  __, __, __, __,     __, F,  __, __, __,

    __, __, __,              __, __, __
  ),

  [LAYER_S] = LAYOUT_kc(
    __, __,  __, __, __,        __, __, __, __, __,
    __, _T_, __, __, __,        __, __, __, __, __,
    __, __,  __, __, __,        __, __, __, __, __,

    __, __, __,                            __, __, __
  ),

  [LAYER_F] = LAYOUT_kc(
    __, __, __, __,  __,     MS_WH_UP,   MS_BTN3, MS_UP,   __,       __,
    __, __, __, _T_, __,     MS_WH_DOWN, MS_LEFT, MS_DOWN, MS_RIGHT, __,
    __, __, __, __,  __,     __,         __,      __,      __,       __,

    __, __, __,              MS_BTN2,    MS_BTN1, __
  ),

  [LAYER_G] = LAYOUT_kc(
    __, __, __, __, __,        F1,  F2,  F3,  F4,  F5,
    __, __, __, __, _T_,       F6,  F7,  F8,  F9,  F10,
    __, __, __, __, __,        F11, F12, __, __, __,

    __, __, __,                __,  __,  __
  )

  /*
  [XXX] = LAYOUT_kc(
    __, __, __, __, __,        __, __, __, __, __,
    __, __, __, __, __,        __, __, __, __, __,
    __, __, __, __, __,        __, __, __, __, __,

    __, __, __,                            __, __, _T_
  ),
  */
};
