# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

UNICODE_ENABLE 		= yes
# UNICODEMAP_ENABLE = yes
MOUSEKEY_ENABLE   = yes
CUSTOM_MATRIX   	= yes
COMBO_ENABLE  		= yes
EXTRAKEY_ENABLE  	= yes
CONSOLE_ENABLE    = yes
COMMAND_ENABLE  	= yes
BOOTMAGIC_ENABLE = lite

DEBOUNCE_TYPE  = eager_pr
SRC += matrix.c
QUANTUM_LIB_SRC += i2c_master.c
