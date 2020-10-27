#----------------------------------------------------------------------------
# make gergoplex:default:flash
# Make sure you have dfu-programmer installed!
#----------------------------------------------------------------------------
# Firmware options
MOUSEKEY_ENABLE						= yes

#Debug options
VERBOSE										= yes
DEBUG_MATRIX_SCAN_RATE		= no
DEBUG_MATRIX							= no
CONSOLE_ENABLE						= no

ifeq ($(strip $(DEBUG_MATRIX)), yes)
    OPT_DEFS += -DDEBUG_MATRIX
endif
