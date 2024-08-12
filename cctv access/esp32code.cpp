#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "camera_wifi_ssid"; // Replace with the camera's Wi-Fi network name
const char* password = ""; // Leave empty if no password is set

WiFiClient client;
HTTPClient http;

void setup() {
  Serial.begin(115200);

  // Connect to the camera's Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Identify the camera's IP address (e.g., using nmap or arp-scan)
  String cameraIp = "192.168.1.100"; // Replace with the camera's IP address

  // Send an HTTP request to the camera
  http.begin(client, "http://" + cameraIp + "/cgi-bin/video.cgi");
  int httpCode = http.GET();
  if (httpCode > 0) {
    Serial.println("HTTP response code: " + String(httpCode));
    String response = http.getString();
    Serial.println(response);
  } else {
    Serial.println("Error sending HTTP request");
  }
  http.end();
}

void loop() {
  // Nothing to do here
}
