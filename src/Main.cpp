#include <Arduino.h>

#include <BLEDevice.h>
#include <SD.h>
#include <SSD1306Wire.h>
#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>
#include <WiFi.h>

#include <ESPAsyncWebServer.h>

#include "Config.h"

#include "Data.h"

char logFileName[20] = { 0 };

char const *log_col_names[LOG_COLUMN_COUNT] = {
    "MAC", "SSID", "AuthMode", "FirstSeen", "Channel", "RSSI", "Latitude", "Longitude", "AltitudeMeters", "AccuracyMeters", "Type"
};

char const *PRE_HEADER = "WigleWifi-1.4,appRelease=" DEVICE_APP_RELEASE ",model=D1 Mini,release=" DEVICE_VERSION ",device=" DEVICE_CODENAME ",display=SSD1306,board=espressif32,brand=WeMos";

char const INDEX_HTML[] PROGMEM =
"<link rel=icon href=data:,><pre style=font:unset>CONTENT UPDATED EVERY 5 SECONDS!\n\n"
"Current log file: <span id=\"log\">unknown</span>\n"
"Disk space: <span id=\"disk\">unknown</span>/<span id=\"total\">unknown</span>KB\n"
"GPS: <span id=\"gps\">unknown (0)</span>\n"
"WiFi: <span id=\"wifi\">unknown</span>\n"
"BT: <span id=\"bt\">unknown</span>\n"
"<button onclick=\"wipe();\">WIPE</button>"
"<script>"
"function wipe() {\n"
"	if (confirm('ARE YOU SURE YOU WANT TO WIPE ALL DATA?'))\n"
"		fetch('/wipe', { method: 'POST' });\n"
"}\n"
"const log = document.getElementById('log')\n"
"const disk = document.getElementById('disk')\n"
"const total = document.getElementById('total')\n"
"const gps = document.getElementById('gps')\n"
"const wifi = document.getElementById('wifi')\n"
"const bt = document.getElementById('bt')\n"
"setInterval(() => {\n"
"	fetch('/info').then(r => r.json()).then(d => {\n"
"		log.innerText = d.log\n"
"		disk.innerText = d.disk\n"
"		total.innerText = d.total\n"
"		gps.innerText = `${d.gps} (${d.sat})`\n"
"		wifi.innerText = d.wifi\n"
"		bt.innerText = d.bt\n"
"	}).catch(err => console.error)\n"
"}, 5000)\n"
"</script>";

SoftwareSerial ss(GPS_RX, GPS_TX);
TinyGPSPlus gps;
SSD1306Wire display(OLED_ADDERSS, OLED_SDA, OLED_SCL, OLED_RES);
AsyncWebServer server(80);

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
String GenearateData();

bool wipe = false;

void WipeAllFiles() {
    if (wipe == false) return;

    File root = SD.open("/");
    for (;;) {
        File entry = root.openNextFile();
        if (!entry) break;
        char const *path = entry.path();
        entry.close();
        SD.remove(path);
    }
    root.close();
}

void setup()
{
    bool flag = true;

    WiFi.mode(WIFI_AP_STA);

    Serial.begin(9600);

    if (!display.init()) {
        Serial.print("Display initialization failed");
        for (;;)
            delay(200);
    }

    if (!SD.begin(SS, SPI, 4000000, "/sd", 5, true))
        Panic("SD card failed to initialize");

    display.setFont(Dialog_plain_8);
    display.drawFastImage(display.getWidth() / 2 - 16, display.getHeight() / 2 - 16, 32, 32, SPLASH_DATA);
    display.display();

    UpdateFileName();

    delay(500);

    BLEDevice::init("netscan");
    if (!BLEDevice::getInitialized())
        Panic("BLE initialization failed");

    if (!WiFi.mode(WIFI_STA))
        Panic("Failed to set WiFi mode to STATION");
    WiFi.disconnect();
    delay(100);

    ss.begin(GPS_BAUD);

    display.clear();
    display.setColor(OLEDDISPLAY_COLOR::WHITE);
    display.drawStringMaxWidth(0, 0, display.width(), "Waiting for GPS...");
    display.display();

    while (!ss.available())
        ;

    while (!(ss.readStringUntil('\n').startsWith("$GP")))
        ;

    if (!PutHeader(logFileName))
        flag = false;

    if (!flag)
        Panic("Failed to write header");

    display.clear();
    display.display();

    Serial.println("Setting up AP...");
    WiFi.softAP(WIFI_SSID, WIFI_PSWD, 1, 0, 5);

    WiFi.softAPConfig(IP, Gateway, Mask);

    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/html", INDEX_HTML);
    });

    server.on("/info", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "application/json", GenearateData());
    });

    server.on("/wipe", HTTP_POST, [](AsyncWebServerRequest *request) {
        wipe = true;
        request->send(200, "text/plain", "OK");
    });

    server.begin();
}

void loop()
{
    WipeAllFiles();
    if (wipe) {
        ESP.restart();
    }

    gps.encode(ss.read());
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

    if (info.wifi_count < 0)
        info.wifi_status = "OFFLINE";
    else
        info.wifi_status = String(info.wifi_count);

    if (info.bte_count < 0)
        info.bte_status = "OFFLINE";
    else
        info.bte_status = String(info.bte_count);

    display.setColor(OLEDDISPLAY_COLOR::WHITE);

    for (int i = 1; i < 8; i += 2)
        display.drawLine(0, i, display.width(), i);

    display.setColor(OLEDDISPLAY_COLOR::BLACK);

    display.fillRect(display.width() / 2 - display.getStringWidth(logFileName) / 2 - 2, 0, display.getStringWidth(logFileName) + 4, 8);
    display.fillRect(display.width() / 2 - display.getStringWidth(logFileName) / 2 - 3, 2, display.getStringWidth(logFileName) + 6, 5);

    display.fillRect(0, 0, display.getStringWidth(String(gps.satellites.value())) + 2, 8);

    display.setColor(OLEDDISPLAY_COLOR::WHITE);
    display.drawString(display.width() / 2 - display.getStringWidth(logFileName) / 2, 0, logFileName);
    display.drawString(0, 0, String(gps.satellites.value()));

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
                file.print(gps.location.lat());
                file.print(',');
                file.print(gps.location.lng());
                file.print(',');
                file.print(gps.altitude.meters());
                file.print(',');
                file.print(gps.hdop.value());
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
                file.print(gps.location.lat());
                file.print(',');
                file.print(gps.location.lng());
                file.print(',');
                file.print(gps.altitude.meters());
                file.print(',');
                file.print(gps.hdop.value());
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

inline String GenearateData()
{
    String tmp = String("{\"log\":\"") + logFileName + "\",";
    tmp += String("\"disk\":") + (double)SD.usedBytes()/1000 + ",";
    tmp += String("\"total\":") + (double)SD.totalBytes()/1000 + ",";
    tmp += String("\"gps\":\"") + info.gps_status + "\",";
    tmp += String("\"sat\":") + gps.satellites.value() + ",";
    tmp += String("\"wifi\":\"") + info.wifi_status + "(" + info.wifi_count + ")\",";
    tmp += String("\"bt\":\"") + info.bte_status + "(" + info.bte_count + ")\"}";
    return tmp;
}
