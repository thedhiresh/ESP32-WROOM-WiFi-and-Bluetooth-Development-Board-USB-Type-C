# ESP32 WiFi Scanner

This project uses the ESP32 microcontroller to scan and display available WiFi networks in the vicinity. The scanner will print the network names (SSIDs) and their signal strengths (RSSI) to the Serial Monitor.

## Features

- Scans for WiFi networks and retrieves their SSIDs and signal strengths.
- Displays up to a defined maximum number of networks.
- Provides clear feedback if no networks are found or if the scan fails.

## Requirements

- **ESP32 Development Board**
- **Arduino IDE** with ESP32 board support installed
- **USB Cable** for connecting the ESP32 to your computer

## Installation

1. **Install the Arduino IDE:**
   - Download and install the Arduino IDE from [Arduino's official website](https://www.arduino.cc/en/software).

2. **Add ESP32 Board Support:**
   - Open the Arduino IDE.
   - Go to `File` -> `Preferences`.
   - In the "Additional Board Manager URLs" field, add: `https://dl.espressif.com/dl/package_esp32_index.json`
   - Go to `Tools` -> `Board` -> `Boards Manager`.
   - Search for `ESP32` and install the `esp32` package.

3. **Connect Your ESP32:**
   - Connect the ESP32 board to your computer using a USB cable.

4. **Load the Code:**
   - Open the Arduino IDE.
   - Create a new sketch and copy the provided code into it.

5. **Select Your Board and Port:**
   - Go to `Tools` -> `Board` and select your ESP32 board model.
   - Go to `Tools` -> `Port` and select the appropriate COM port for your ESP32.

6. **Upload the Code:**
   - Click the `Upload` button in the Arduino IDE to compile and upload the code to your ESP32 board.

## Usage

1. **Open Serial Monitor:**
   - After uploading the code, open the Serial Monitor by going to `Tools` -> `Serial Monitor` or pressing `Ctrl + Shift + M`.

2. **View Network Scan Results:**
   - The Serial Monitor will display the results of the WiFi scan, including the names and signal strengths of detected networks.

3. **Adjust Scan Settings:**
   - You can modify the `SCAN_INTERVAL_MS` constant to change the time between scans.
   - Adjust the `MAX_NETWORKS` constant to set the maximum number of networks displayed.

## Code Overview

The code performs the following tasks:

- Initializes the Serial communication.
- Sets the ESP32 WiFi mode to `WIFI_STA` for scanning.
- Scans for available networks and retrieves their SSIDs and signal strengths.
- Prints the network details to the Serial Monitor.
- Provides feedback for scan failures or empty results.
- Waits for a specified interval before performing the next scan.

## Code

```cpp
#include <WiFi.h>

const int SCAN_INTERVAL_MS = 5000; // Interval between scans (5 seconds)
const int MAX_NETWORKS = 20;       // Maximum number of networks to display

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA); // Set WiFi mode to Station (client) to scan networks
  Serial.println("ESP32 WiFi Scanner");
}

void loop() {
  Serial.println("Scanning for WiFi networks...");
  
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("WiFi scan failed");
  } else {
    if (numSsid == 0) {
      Serial.println("No networks found");
    } else {
      Serial.print("Number of networks found: ");
      Serial.println(numSsid);
      
      for (int i = 0; i < numSsid && i < MAX_NETWORKS; i++) {
        Serial.print("Network ");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" (Signal Strength: ");
        Serial.print(WiFi.RSSI(i));
        Serial.println(" dBm)");
        delay(10); // Small delay to prevent Serial buffer overflow
      }

      if (numSsid > MAX_NETWORKS) {
        Serial.print("Note: Only showing the first ");
        Serial.print(MAX_NETWORKS);
        Serial.println(" networks. Use a larger MAX_NETWORKS value to see more.");
      }
    }
  }

  Serial.println();
  delay(SCAN_INTERVAL_MS); // Wait before the next scan
}
