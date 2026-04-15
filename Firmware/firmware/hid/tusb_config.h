#pragma once

#include "pico/stdlib.h"

// MCU
#define CFG_TUSB_MCU OPT_MCU_RP2040

// Device mode
#define CFG_TUSB_RHPORT0_MODE (OPT_MODE_DEVICE)

// Speed
#define CFG_TUD_MAX_SPEED OPT_MODE_FULL_SPEED

// ===== HID (Keyboard) =====
#define CFG_TUD_HID 1

// Buffer size (enough for keyboard)
#define CFG_TUD_HID_EP_BUFSIZE 16

// No CDC (serial over USB)
#define CFG_TUD_CDC 0

// No MSC (mass storage)
#define CFG_TUD_MSC 0

// No MIDI
#define CFG_TUD_MIDI 0

// No vendor interface
#define CFG_TUD_VENDOR 0