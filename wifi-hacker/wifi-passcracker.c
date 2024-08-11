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
