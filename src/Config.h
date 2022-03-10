#pragma once

#include <stdint.h>

#include <OLEDDisplay.h>

// OLED screen configuration
// Addresses:
//  * 128x32: 0x3C
//  * 128x64: 0x3D
uint8_t const OLED_ADDERSS = 0x3C;
int const OLED_SDA = 22;
int const OLED_SCL = 21;
OLEDDISPLAY_GEOMETRY const OLED_RES = GEOMETRY_128_32;

// GPS configuration
uint8_t const GPS_RX = 16;
uint8_t const GPS_TX = 17;
uint32_t const GPS_BAUD = 9600;

// Other configuration
unsigned int const MAX_LOG_FILES = 100;
unsigned int const LOG_COLUMN_COUNT = 11;
unsigned int const LOG_RATE = 500;
