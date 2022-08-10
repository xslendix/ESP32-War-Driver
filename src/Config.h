#pragma once

#include <stdint.h>

#include <OLEDDisplay.h>
#include <WiFi.h>

#define DEVICE_VERSION "1.0.0"
#define DEVICE_APP_RELEASE "1.0"
#define DEVICE_CODENAME "frailangel"

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

// WiFi AP configuration
char const *WIFI_SSID = DEVICE_CODENAME "_AP";
char const *WIFI_PSWD = "password1234";

IPAddress const IP = {192, 168, 1, 1};
IPAddress const Gateway = {192, 168, 1, 1};
IPAddress const Mask = {255, 255, 255, 0};

// Other configuration
unsigned int const MAX_LOG_FILES = 100;
unsigned int const LOG_COLUMN_COUNT = 11;
unsigned int const LOG_RATE = 500;
