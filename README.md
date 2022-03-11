<h1 align=center>ESP32 War Driver</h1>
<p align=center>War driving with an ESP32</p>

## Features

 * OLED display support
 * BLE
 * WiFi
 * Saving on MicroSD Card

## Getting started

### Hardware

Parts:
 * WeMos D1 Mini ESP32 ([AliExpress](https://www.aliexpress.com/item/32815530502.html))
 * MicroSD Card Reader ([AliExpress](https://www.aliexpress.com/item/32938935724.html))
 * GY-NEO6MV2 + Antenna ([AliExpress](https://www.aliexpress.com/item/1005001635722164.html))
 * SSD1306 I²C OLED Display ([AliExpress](https://www.aliexpress.com/item/32879702750.html))

Wiring diagram (also available as a [Fritzing file](Meta/Diag.fzz)):
![diagram](/Meta/Diag.png)

### Firmware

 * Install [VSCode](https://code.visualstudio.com/) and the [PlatformIO IDE Extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)
 * [Clone](https://github.com/xSlendiX/esp32-war-driver.git)/[download](https://github.com/xSlendiX/esp32-war-driver/archive/refs/heads/master.zip) git repository
 * Go to the PlatformIO home, click on "Open Project" and navigate to where you downloaded the git repository 
 * Modify the [configuration file](src/Config.h) if needed
 * Press the Build button at the bottom of VSCode. (tick icon)
 * Upload the firmware using the "Upload" button at the bottom of VSCode. (right arrow icon)
   * If on linux, make sure you set up the udev rules needed: [documentation](https://docs.platformio.org/page/faq.html#platformio-udev-rules)

## Credits

This project uses some logic as [Nico's work](https://github.com/reynico/arduino-wardriving).

## License

This software is licensed under the GPLv3 public license. View more details [here](/LICENSE).
