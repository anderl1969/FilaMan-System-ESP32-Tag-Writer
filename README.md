# FilaMan TAG Writer

- Lean **NFC-Terminal** for the FilaMan System
- Small footprint
- Ideal for office
- With **sound** support :)

## FilaMan - Filament Management System

⚠️ **Important: Starting with v3.0.0, this system requires the [FilaMan-System](https://github.com/Fire-Devils/filaman-system) backend. Previous direct integrations (Spoolman, MQTT, Bambu Lab) have been moved to the central FilaMan-System.**

FilaMan is a filament management tool for 3D printing. It uses ESP32 hardware for weight measurement and NFC tag management.
Users can manage filament spools and configure the device via a web interface.
The system integrates seamlessly with the [FilaMan-System](https://github.com/Fire-Devils/filaman-system).

## FilaMan-System-ESP32-Tag-Writer
This is a fork of [Fire-Devils/FilaMan-System-ESP32](https://github.com/Fire-Devils/FilaMan-System-ESP32).

Its purpose is a slim alternative to the original design integrating seamlessly on your desk as a plain NFC terminal.
In favor of a smaller footprint, it omits a scale. This also makes support for the touch sensor obsolete.
As an extension compared to the original, it uses a passive piezo buzzer to play acoustic signals.

| | Feature Comparison[<sup>*</sup>](#1)|
|---- |---- |
| - | Scale |
| - | Touch |
| + | Buzzer|

<sup>*) compared to the original [Fire-Devils/FilaMan-System-ESP32](https://github.com/Fire-Devils/FilaMan-System-ESP32).<a class="anchor" id="1"></a></sup>



![Scale](./img/FilaLite_no_scale.png)


More Images can be found in the [img Folder](/img/)

---

### ESP32 Hardware Features
- **NFC Tag Reading/Writing:** PN532 module for reading and writing filament data to NFC tags.
- **OLED Display:** Shows current weight and connection status (WiFi, FilaMan-System).
- **WiFi Connectivity:** WiFiManager for easy network configuration.
- **NFC-Tag NTAG213 NTAG215:** Use NTAG213, better NTAG215 because of enough space on the Tag
- **Sound Output:** Piezo-Buzzer for accustic signals.

### Web Interface Features
- **Real-time Updates:** WebSocket connection for live data updates.
- **NFC Tag Management:**
	- Write filament data to NFC tags.
	- Supports automatic Spool detection in compatible systems.
- **FilaMan-System Integration:**
  - Synchronize spool data with the central backend.
  - Update spool weights automatically.
  - Track NFC tag assignments.

## Detailed Functionality

### ESP32 Functionality
- **User Interactions:** The OLED display provides immediate feedback on the system status, including NFC tag writing and connection status.

### Web Interface Functionality
- **User Interactions:** The web interface allows users to interact with the system, configure the device, and monitor status.
- **UI Elements:** Includes forms for registration and real-time status indicators.

## Hardware Requirements

### Components (Affiliate Links)
- **ESP32 Development Board:** Any ESP32 variant.
[Amazon Link](https://amzn.to/3FHea6D)
- **OLED 0.96 Zoll I2C white/yellow Display:** 128x64 SSD1306.
[Amazon Link](https://amzn.to/445aaa9)
- **PN532 NFC NXP RFID-Modul V3:** For NFC tag operations.
[Amazon Link](https://amzn.eu/d/gy9vaBX)
- **NFC Tags NTAG213 NTAG215:** RFID Tag
[Amazon Link](https://amzn.to/3E071xO)


### Pin Configuration
| Component          | ESP32 Pin |
|-------------------|-----------|
| BUZZER +          | 18        |
| OLED SDA          | 21        |
| OLED SCL          | 22        |
| PN532 IRQ         | 32        |
| PN532 RESET       | 33        |
| PN532 SDA         | 21        |
| PN532 SCL         | 22        |

**!! Make sure that the DIP switches on the PN532 are set to I2C**

![Wiring](./img/Schaltplan%20NFC%20Tag%20Writer.png)

## Software Dependencies

### ESP32 Libraries
- `WiFiManager`: Network configuration
- `ESPAsyncWebServer`: Web server functionality
- `ArduinoJson`: JSON parsing and creation
- `Adafruit_PN532`: NFC functionality
- `Adafruit_SSD1306`: OLED display control
- `HX711`: Load cell communication

# Installation

## Prerequisites
- **Software:**
  - [PlatformIO](https://platformio.org/) in VS Code
  - [FilaMan-System](https://github.com/Fire-Devils/filaman-system) instance
- **Hardware:**
  - ESP32 Development Board
  - OLED Display (128x64 SSD1306)
  - PN532 NFC Module
  - Piezo Buzzer (passive)
  - Connecting wires


## Step-by-Step Installation
### Compile by yourself
1. **Clone the Repository:**
    ```bash
    git clone https://github.com/anderl1969/FilaMan-System-ESP32-Tag-Writer.git
    cd FilaMan-System-ESP32-Tag-Writer
    ```
2. **Install Dependencies:**
    ```bash
    pio lib install
    ```
3. **Flash the ESP32:**
    ```bash
    pio run --target upload
    ```
4. **Initial Setup:**
    - Connect to the "FilaMan" WiFi access point.
    - Configure WiFi settings through the captive portal.
    - Access the web interface adressing the IP address.

# Documentation

### Relevant Links
- [FilaMan-System](https://github.com/Fire-Devils/filaman-system)
- [PlatformIO Documentation](https://docs.platformio.org/)

### Tutorials and Examples
- [PlatformIO Getting Started](https://docs.platformio.org/en/latest/tutorials/espressif32/arduino_debugging_unit_testing.html)
- [ESP32 Web Server Tutorial](https://randomnerdtutorials.com/esp32-web-server-arduino-ide/)

# License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
