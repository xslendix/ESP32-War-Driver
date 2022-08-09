#include <Arduino.h>

#include <BLEDevice.h>
#include <SD.h>
#include <SSD1306Wire.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <WiFi.h>

#include "Config.h"

#include "Data.h"

char logFileName[20] = { 0 };

char const* log_col_names[LOG_COLUMN_COUNT] = {
    "MAC", "SSID", "AuthMode", "FirstSeen", "Channel", "RSSI", "Latitude", "Longitude", "AltitudeMeters", "AccuracyMeters", "Type"
};

char const* PRE_HEADER = "WigleWifi-1.4,appRelease=" DEVICE_APP_RELEASE ",model=D1 Mini,release=" DEVICE_VERSION ",device=" DEVICE_CODENAME ",display=SSD1306,board=espressif32,brand=WeMos";

SoftwareSerial ss(GPS_RX, GPS_TX);
TinyGPSPlus gps;
SSD1306Wire display(OLED_ADDERSS, OLED_SDA, OLED_SCL, OLED_RES);

struct Information {
    String wifi_status = "";
    String bte_status = "";
    String gps_status = "";

    int wifi_count = -1;
    int bte_count = -1;
} info;

void UpdateFileName();
bool PutHeader(char const*);
void ScanWiFiAndBluetoothNetworks(char const*);
void UpdateScreen();
void Panic(char const*);

void setup()
{
    bool flag = true;

    Serial.begin(9600);

    if (!display.init()) {
        Serial.print("Display initialization failed");
        for (;;)
            delay(200);
    }

    display.setFont(Dialog_plain_8);
    display.drawFastImage(display.getWidth() / 2 - 16, display.getHeight() / 2 - 16, 32, 32, SPLASH_DATA);
    display.display();

    delay(1000);

    BLEDevice::init("netscan");
    if (!BLEDevice::getInitialized())
        Panic("BLE initialization failed");

    if (!WiFi.mode(WIFI_STA))
        Panic("Failed to set WiFi mode to STATION");
    WiFi.disconnect();
    delay(100);

    if (!SD.begin(SS, SPI, 4000000, "/sd", 5, true))
        Panic("SD card failed to initialize");

    ss.begin(GPS_BAUD);

    display.clear();
    display.setColor(OLEDDISPLAY_COLOR::WHITE);
    display.drawStringMaxWidth(0, 0, display.width(), "Waiting for GPS...");
    display.display();

    while (!ss.available())
        ;

    while (!(ss.readStringUntil('\n').startsWith("$GP")))
        ;

    UpdateFileName();
    if (!PutHeader(logFileName))
        flag = false;

    if (!flag)
        Panic("Failed to write header");

    display.clear();
    display.display();
}

void loop()
{
    gps.encode(Serial1.read());

    if (gps.location.isValid()) {
        info.gps_status = "ONLINE";
        ScanWiFiAndBluetoothNetworks(logFileName);
    } else {
        info.gps_status = "OFFLINE";
    }

    UpdateScreen();
}

void UpdateScreen()
{
    display.clear();
    String time = "";
    if (gps.time.isValid()) {
        uint8_t hour = gps.time.hour();
        if (hour < 10)
            hour = 0;

        uint8_t minute = gps.time.minute();
        if (minute < 10)
            minute = 0;

        time = String(hour, DEC) + ":" + String(minute, DEC);
    }

    if (info.wifi_count < 0)
        info.wifi_status = "OFFLINE";
    else
        info.wifi_status = String(info.wifi_count);

    if (info.bte_count < 0)
        info.bte_status = "OFFLINE";
    else
        info.bte_status = String(info.bte_count);

    if (display.width() > display.getStringWidth(String(logFileName) + time) + 16 && time.length() > 0) {
        display.drawString(0, 0, logFileName);
        display.drawString(display.width() - display.getStringWidth(time), 0, time);

        for (int i = 1; i < 8; i += 2)
            display.drawLine(
                display.getStringWidth(String(logFileName)) + 2 + (i != 1 && i != 7 ? 1 : 0), i,
                display.width() - display.getStringWidth(time) - 3 - (i != 1 && i != 7 ? 1 : 0), i);

    } else {
        display.setColor(OLEDDISPLAY_COLOR::WHITE);

        for (int i = 1; i < 8; i += 2)
            display.drawLine(0, i, display.width(), i);

        display.setColor(OLEDDISPLAY_COLOR::BLACK);

        display.fillRect(display.width() / 2 - display.getStringWidth(time.length() ? time : logFileName) / 2 - 2, 0, display.getStringWidth(time.length() ? time : logFileName) + 4, 8);
        display.fillRect(display.width() / 2 - display.getStringWidth(time.length() ? time : logFileName) / 2 - 3, 2, display.getStringWidth(time.length() ? time : logFileName) + 6, 5);

        display.setColor(OLEDDISPLAY_COLOR::WHITE);
        display.drawString(display.width() / 2 - display.getStringWidth(time.length() ? time : logFileName) / 2, 0, time.length() ? time : logFileName);
    }
    display.setColor(OLEDDISPLAY_COLOR::WHITE);

    display.drawString(0, 8, "GPS:");
    display.drawString(display.width() - display.getStringWidth(info.gps_status), 8, info.gps_status);
    display.drawString(0, 16, "WiFi:");
    display.drawString(display.width() - display.getStringWidth(info.wifi_status), 16, info.wifi_status);
    display.drawString(0, 24, "BT:");
    display.drawString(display.width() - display.getStringWidth(info.bte_status), 24, info.bte_status);

    display.display();
}

void Panic(char const* message)
{
    Serial.printf("FATAL: %s\n", message);

    display.clear();
    display.setColor(OLEDDISPLAY_COLOR::INVERSE);
    display.drawString(0, 0, "FATAL:");
    display.setColor(OLEDDISPLAY_COLOR::WHITE);
    display.drawStringMaxWidth(0, 10, display.width(), message);

    display.display();

    while (true)
        delay(200);
}

bool PutHeader(char const* filename)
{
    File file = SD.open(filename, FILE_WRITE);
    if (file) {
        file.println(PRE_HEADER);
        for (uint i = 0; i < LOG_COLUMN_COUNT; i++) {
            if (i != 0)
                file.print(',');
            file.print(log_col_names[i]);
        }
        file.println();
        file.close();
        return true;
    }
    return false;
}

bool IsOnFile(char const* filename, char const* mac)
{
    File file = SD.open(filename);
    if (!file) {
        Serial.println("Failed to open file");
        return false;
    }

    uint const BUFFER_SIZE = 128;
    char line[BUFFER_SIZE];
    while (file.available()) {
        file.readBytesUntil('\n', line, BUFFER_SIZE);
        if (strstr(line, mac)) {
            file.close();
            return true;
        }
    }

    file.close();

    return false;
}

void PutDateToFile(File& file)
{
    file.print(",");
    file.print(gps.date.year());
    file.print('-');
    file.print(gps.date.month());
    file.print('-');
    file.print(gps.date.day());
    file.print(' ');
    file.print(gps.time.hour());
    file.print(':');
    file.print(gps.time.minute());
    file.print(':');
    file.print(gps.time.second());
}

String GetEncryption(uint8_t network)
{
    byte encryption = WiFi.encryptionType(network);
    switch (encryption) {
    case 2:
        return "[WPA-PSK-CCMP+TKIP][ESS]";
    case 5:
        return "[WEP][ESS]";
    case 4:
        return "[WPA2-PSK-CCMP+TKIP][ESS]";
    case 7:
        return "[ESS]";
    case 8:
        return "[WPA-PSK-CCMP+TKIP][WPA2-PSK-CCMP+TKIP][ESS]";
    default:
        return "[Unknown]";
    }
}

void ScanWiFiAndBluetoothNetworks(char const* filename)
{
    // Scan WiFi networks

    int n = WiFi.scanNetworks();
    if (n == 0) {
        Serial.println("No WiFi networks found");
    } else {
        for (u8_t i = 0; i <= n; i++) {
            if ((!IsOnFile(filename, WiFi.BSSIDstr(i).c_str())) && (WiFi.channel(i) > 0) && (WiFi.channel(i) < 15)) {
                info.wifi_count++;
                File file = SD.open(filename, FILE_APPEND);
                if (!file) {
                    Serial.println("Failed to open file");
                    return;
                }

                file.print(WiFi.BSSIDstr(i));
                file.print(',');
                auto SSID = WiFi.SSID(i);
                SSID.replace(",", ".");
                file.print(SSID);
                file.print(',');
                file.print(GetEncryption(i));
                PutDateToFile(file);
                file.print(',');
                file.print(WiFi.channel(i));
                file.print(',');
                file.print(WiFi.RSSI(i));
                file.print(',');
                file.print(gps.location.lat(), 6);
                file.print(',');
                file.print(gps.location.lng(), 6);
                file.print(',');
                file.print(gps.altitude.meters(), 1);
                file.print(',');
                file.print((gps.hdop.value(), 1));
                file.println(",WIFI");
                file.close();
            }
        }
    }

    // Scan Bluetooth networks

    auto advertisedDevices = BLEDevice::getScan()->getResults();
    for (int i = 0; i < advertisedDevices.getCount(); i++) {
        auto device = advertisedDevices.getDevice(i);

        if (device.haveName()) {
            if (!IsOnFile(filename, device.getAddress().toString().c_str())) {
                info.bte_count++;
                File file = SD.open(filename, FILE_APPEND);
                if (!file) {
                    Serial.println("Failed to open file");
                    return;
                }

                file.print(device.getAddress().toString().c_str());
                file.print(",");
                file.print(device.getName().c_str());
                file.print(",");
                // file.print(device.getAppearance());
                PutDateToFile(file);
                file.print(",");
                file.print(0);
                file.print(",");
                file.print(device.getRSSI());
                file.print(",");
                file.print(gps.location.lat(), 6);
                file.print(",");
                file.print(gps.location.lng(), 6);
                file.print(",");
                file.print(gps.altitude.meters());
                file.print(",");
                file.print((gps.hdop.value(), 1));
                file.println(",BLE");

                file.close();
            }
        }
    }
}

void UpdateFileName()
{
    int i = 0;
    for (; i < MAX_LOG_FILES; i++) {
        memset(logFileName, 0, strlen(logFileName));
        sprintf(logFileName, "/%i.log.csv", i);
        if (!SD.exists(logFileName)) {
            break;
        } else {
            Serial.print(logFileName);
            Serial.println(" exists");
        }
    }
    Serial.print("File name: ");
    Serial.println(logFileName);
}
