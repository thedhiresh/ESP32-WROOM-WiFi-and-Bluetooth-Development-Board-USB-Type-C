#include <WiFi.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println("Scanning for WiFi networks...");
  int numSsid = WiFi.scanNetworks();
  if (numSsid == -1) {
    Serial.println("WiFi scan failed");
  } else {
    Serial.print("Number of networks found: ");
    Serial.println(numSsid);
    for (int i = 0; i < numSsid; i++) {
      Serial.print("Network name: ");
      Serial.println(WiFi.SSID(i));
      Serial.print("Signal strength (RSSI): ");
      Serial.println(WiFi.RSSI(i));
      delay(10);
    }
  }
  delay(5000);
}
