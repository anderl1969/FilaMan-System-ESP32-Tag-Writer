# FilaMan - Filament Management System

⚠️ **Wichtig: Ab Version 3.0.0 erfordert dieses System das [FilaMan-System](https://github.com/Fire-Devils/filaman-system) Backend. Frühere direkte Integrationen (Spoolman, MQTT, Bambu Lab) wurden in das zentrale FilaMan-System verschoben.**

FilaMan ist ein Werkzeug zur Filamentverwaltung für den 3D-Druck. Es verwendet ESP32-Hardware zur Gewichtsmessung und Verwaltung von NFC-Tags.
Benutzer können Filamentspulen verwalten und das Gerät über eine Weboberfläche konfigurieren.
Das System integriert sich nahtlos in das [FilaMan-System](https://github.com/Fire-Devils/filaman-system).

## FilaMan-System-ESP32-Tag-Writer
Dieses Projekt ist ein Fork von [Fire-Devils/FilaMan-System-ESP32](https://github.com/Fire-Devils/FilaMan-System-ESP32).

Es soll ein schlanke Variante des originalen Designs sein, das sich nahtlos auf dem Schreibtisch als NFC-Terminal integriert.
Zugunsten eines geringeren Platzbedarfs verzichtet es auf eine Waage. Dadurch wird auch die Unterstützung des Touch-Sensors obsolet.
Als Erweiterung gegenüber dem Original verwendet es einen passiven Piezo-Summer, zum Abspielen akkustischer Signale.

| | Feature |
|---- |---- |
| - | Waage |
| - | Touch |
| + | Buzzer|

![Waage](./img/FilaLite_no_scale.png)


Weitere Bilder finden Sie im [img Ordner](/img/)

---

### ESP32 Hardware-Features
- **NFC-Tag Lesen/Schreiben:** PN532-Modul zum Lesen und Schreiben von Filamentdaten auf NFC-Tags.
- **OLED-Display:** Zeigt aktuelles Gewicht und Verbindungsstatus (WiFi, FilaMan-System) an.
- **WiFi-Konnektivität:** WiFiManager für einfache Netzwerkkonfiguration.
- **NFC-Tag NTAG213 NTAG215:** Verwendung von NTAG213, besser NTAG215 wegen ausreichendem Platz auf dem Tag.
- **Tonausgabe:** Piezo-Buzzer zur Wiedergabe akkustischer Signale.

### Weboberflächen-Features
- **Echtzeit-Updates:** WebSocket-Verbindung für Live-Datenaktualisierungen.
- **NFC-Tag-Verwaltung:**
	- Schreiben von Filamentdaten auf NFC-Tags.
	- Unterstützt automatische Spulenerkennung in kompatiblen Systemen.
- **FilaMan-System Integration:**
  - Synchronisierung der Spulendaten mit dem zentralen Backend.
  - Automatische Aktualisierung der Spulengewichte.
  - Verfolgung von NFC-Tag-Zuweisungen.


## Detaillierte Funktionalität

### ESP32-Funktionalität
- **Benutzerinteraktionen:** Das OLED-Display bietet sofortiges Feedback zum Systemstatus, einschließlich NFC-Tag Schreibvorgang und Verbindungsstatus.

### Weboberflächen-Funktionalität
- **Benutzerinteraktionen:** Die Weboberfläche ermöglicht es Benutzern, mit dem System zu interagieren, das Gerät zu konfigurieren und den Status zu überwachen.
- **UI-Elemente:** Enthält Formulare zur Registrierung und Echtzeit-Statusanzeigen.

## Hardware-Anforderungen

### Komponenten (Affiliate-Links)
- **ESP32 Development Board:** Jede ESP32-Variante.
[Amazon Link](https://amzn.to/3FHea6D)
- **OLED 0,96 Zoll I2C weiß/gelbes Display:** 128x64 SSD1306.
[Amazon Link](https://amzn.to/445aaa9)
- **PN532 NFC NXP RFID-Modul V3:** Für NFC-Tag-Operationen.
[Amazon Link](https://amzn.eu/d/gy9vaBX)
- **NFC-Tags NTAG213 NTAG215:** RFID-Tag.
[Amazon Link](https://amzn.to/3E071xO)


### Pin-Konfiguration
| Komponente         | ESP32 Pin |
|-------------------|-----------|
| BUZZER +          | 18        |
| OLED SDA          | 21        |
| OLED SCL          | 22        |
| PN532 IRQ         | 32        |
| PN532 RESET       | 33        |
| PN532 SDA         | 21        |
| PN532 SCL         | 22        |

**!! Stellen Sie sicher, dass die DIP-Schalter am PN532 auf I2C eingestellt sind.**

![Verkabelung](./img/Schaltplan.png)

## Software-Abhängigkeiten

### ESP32-Bibliotheken
- `WiFiManager`: Netzwerkkonfiguration
- `ESPAsyncWebServer`: Webserver-Funktionalität
- `ArduinoJson`: JSON-Parsing und -Erstellung
- `Adafruit_PN532`: NFC-Funktionalität
- `Adafruit_SSD1306`: OLED-Display-Steuerung
- `HX711`: Kommunikation mit der Wägezelle

# Installation

## Voraussetzungen
- **Software:**
  - [PlatformIO](https://platformio.org/) in VS Code
  - [FilaMan-System](https://github.com/Fire-Devils/filaman-system) Instanz
- **Hardware:**
  - ESP32 Development Board
  - OLED-Display (128x64 SSD1306)
  - PN532 NFC-Modul
  - Piezo Summer (passiv)
  - Verbindungskabel


## Schritt-für-Schritt-Installation
### Selbst kompilieren
1. **Repository klonen:**
    ```bash
    git clone https://github.com/anderl1969/FilaMan-System-ESP32-Tag-Writer.git
    cd FilaMan-System-ESP32-Tag-Writer
    ```
2. **Abhängigkeiten installieren:**
    ```bash
    pio lib install
    ```
3. **ESP32 flashen:**
    ```bash
    pio run --target upload
    ```
4. **Ersteinrichtung:**
    - Verbinden Sie sich mit dem "FilaMan" WiFi-Access-Point.
    - Konfigurieren Sie die WiFi-Einstellungen über das Captive Portal.
    - Greifen Sie über die IP-Adresse auf die Weboberfläche zu.

# Dokumentation

### Relevante Links
- [FilaMan-System](https://github.com/Fire-Devils/filaman-system)
- [PlatformIO Dokumentation](https://docs.platformio.org/)

### Tutorials und Beispiele
- [PlatformIO Erste Schritte](https://docs.platformio.org/en/latest/tutorials/espressif32/arduino_debugging_unit_testing.html)
- [ESP32 Web Server Tutorial](https://randomnerdtutorials.com/esp32-web-server-arduino-ide/)

# Lizenz

Dieses Projekt steht unter der MIT-Lizenz. Weitere Informationen finden Sie in der Datei [LICENSE](LICENSE).
