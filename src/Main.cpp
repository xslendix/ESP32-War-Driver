#include <Arduino.h>

#include <BLEDevice.h>
#include <SD.h>
#include <TinyGPS++.h>
#include <WiFi.h>

#include <stdint.h>

char logFileName[20];

uint const MAX_LOG_FILES = 100;
uint const LOG_COLUMN_COUNT = 11;
uint const LOG_RATE = 500;
char const LOG_FILENAME[] = "netscan.csv";

char const* log_col_names[LOG_COLUMN_COUNT] = {
    "MAC", "SSID", "AuthMode", "FirstSeen", "Channel", "RSSI", "Latitude", "Longitude", "AltitudeMeters", "AccuracyMeters", "Type"
};

TinyGPSPlus gps;

uint total_networks = 0;

void UpdateFileName();
void PutHeader(char const*);
void ScanWiFiAndBluetoothNetworks(char const*);

void setup()
{
    bool flag = true;

    BLEDevice::init("netscan");

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    if (!SD.begin(5)) {
        Serial.println("SD card failed to initialize");
        flag = false;
    }

    if (flag) {
        UpdateFileName();
        PutHeader(logFileName);
    } else {
        while (true) {
            delay(200);
        }
    }
}

void loop()
{
    if (gps.location.isValid()) {
        ScanWiFiAndBluetoothNetworks(logFileName);
    }
}

void PutHeader(char const* filename)
{
    File file = SD.open(filename, FILE_WRITE);
    for (uint i = 0; i < LOG_COLUMN_COUNT; i++) {
        if (i != 0)
            file.print(',');
        file.print(log_col_names[i]);
    }
    file.println();
    file.close();
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
                total_networks++;
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
                file.print(',');
                file.print("WIFI");
                file.println();
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
                File file = SD.open(filename, FILE_APPEND);
                if (!file) {
                    Serial.println("Failed to open file");
                    return;
                }

                file.print(device.getAddress().toString().c_str());
                file.print(",");
                file.print(device.getName().c_str());
                file.print(",");
                file.print(device.getAppearance());
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
        sprintf(logFileName, "%i.log.csv", i);
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
