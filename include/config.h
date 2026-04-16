#pragma once
// ============================================================
//  config.h  –  Pin definitions, display object, refresh mgmt
//  Target: CrowPanel ESP32 2.13" e-paper (122×250, SSD1680)
// ============================================================

#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>

// ── Display SPI pins (ESP32-S3 internal, fixed by board) ─────
#define EPD_CLK   12


// Display Pins (CrowPanel 2.13" SSD1680)
#define EPD_SCK   12
#define EPD_MOSI  11
#define EPD_MISO  -1  // Not used for E-paper
#define EPD_RST   10
#define EPD_DC    13
#define EPD_CS    14
#define EPD_BUSY  9
#define EPD_PWR   7   // Power Enable Pin

// UI Button and Encoder Pins
#define BTN_HOME  2
#define BTN_BACK  1
#define ENC_CLK   6
#define ENC_DT    4
#define ENC_SW    5

// Orientation: 1 = Landscape, 3 = Inverted Landscape
#define DISPLAY_ROTATION 1

// ── Display resolution ───────────────────────────────────────
// Physical: 122 wide × 250 tall (portrait)
// GxEPD2 treats it as width=122, height=250
// Rotation 1 → landscape: 250 wide × 122 tall  ← fbiego/ESP32Timewe use this
#define DISPLAY_ROTATION  1     // landscape (250×122)
#define DISP_W            250
#define DISP_H            122

// ── GxEPD2 display object ────────────────────────────────────
// SSD1680 = same controller as GDEH0213B72 / DEPG0213BN
// GxEPD2_213_BN matches the 122×250 Elecrow panel
#define GxEPD2_DISPLAY_CLASS GxEPD2_BW
#define GxEPD2_DRIVER_CLASS  GxEPD2_213_BN   // 122x250, SSD1680

GxEPD2_BW<GxEPD2_213_BN, GxEPD2_213_BN::HEIGHT>
    display(GxEPD2_213_BN(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY));

// ── Button / encoder GPIOs ───────────────────────────────────
// Based on CrowPanel e-paper series schematic
// (same across 2.13", 2.9", 4.2" models)
#define BTN_HOME   2    // MENU / HOME button
#define BTN_BACK   1    // BACK / EXIT button
#define ENC_CLK    6    // Rotary encoder CLK (A)
#define ENC_DT     4    // Rotary encoder DT  (B)
#define ENC_SW     5    // Rotary encoder push button