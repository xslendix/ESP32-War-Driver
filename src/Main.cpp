#include <Arduino.h>

#include <BLEDevice.h>
#include <SD.h>
#include <SSD1306Wire.h>
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

char const* PRE_HEADER = "WigleWifi-1.4,appRelease=1.0,model=ESP32,release=0.0.0,device=ESP32WarDriving,display=SSD1306,board=esp32,brand=WeMos";

TinyGPSPlus gps;
SSD1306Wire display(0x3C, 21, 22);

struct Information {
    String wifi_status = "";
    String bte_status = "";
    String gps_status = "";

    uint wifi_count = -1;
    uint bte_count = -1;
} info;

void UpdateFileName();
bool PutHeader(char const*);
void ScanWiFiAndBluetoothNetworks(char const*);
void UpdateScreen();
void Panic(char const*);

void setup()
{
    bool flag = true;

    display.init();
    display.drawString(0, 0, "Intializing...");

    BLEDevice::init("netscan");
    if (!BLEDevice::getInitialized())
        Panic("BLE initialization failed");

    if (!WiFi.mode(WIFI_STA))
        Panic("Failed to set WiFi mode to STATION");
    WiFi.disconnect();
    delay(100);

    if (!SD.begin(5))
        Panic("SD card failed to initialize");

    UpdateFileName();
    if (!PutHeader(logFileName))
        flag = false;

    if (!flag)
        Panic("Failed to write header");
    
    display.clear();
}

void loop()
{
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
    // display.clear();
    auto time = String(gps.time.hour()) + ":" + String(gps.time.minute()) + ":" + String(gps.time.second());
    if (info.wifi_count < 0)
        info.wifi_status = "OFFLINE";
    else
        info.wifi_status = String(info.wifi_count);

    if (info.bte_count < 0)
        info.bte_status = "OFFLINE";
    else
        info.bte_status = String(info.bte_count);

    display.fillRect(0, 0, display.width(), 8);
    display.setColor(OLEDDISPLAY_COLOR::INVERSE);
    display.drawString(0, 0, logFileName);
    display.drawString(0, display.width() - time.length() * 8, time);
    display.setColor(OLEDDISPLAY_COLOR::WHITE);
    display.fillRect(48, 8, display.width() - 48, display.height() - 8);
    display.drawString(0, 8, "GPS:");
    display.drawString(display.width() - 8 * info.gps_status.length(), 8, info.gps_status);
    display.drawString(0, 16, "WiFi:");
    display.drawString(display.width() - 8 * info.wifi_status.length(), 16, info.wifi_status);
    display.drawString(0, 24, "BT:");
    display.drawString(display.width() - 8 * info.bte_status.length(), 24, info.bte_status);
}

void Panic(char const* message)
{
    Serial.printf("FATAL: %s\n", message);

    display.clear();
    display.setColor(OLEDDISPLAY_COLOR::INVERSE);
    display.drawString(0, 0, "FATAL:");
    display.setColor(OLEDDISPLAY_COLOR::WHITE);
    display.drawString(0, 56, message);

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
