# ESP32 WiFi Packet Sniffer

This project is an ESP32-based WiFi packet sniffer that connects to a WiFi network and captures network packets. The program identifies TCP packets, checks for HTTP requests, and prints relevant information to the Serial Monitor.

## Features

- Connects to a specified WiFi network.
- Initializes the WiFi sniffer.
- Captures and analyzes network packets.
- Detects HTTP requests and prints source IP, destination IP, destination port, and URL to the Serial Monitor.

## Requirements

- [ESP32 Board](https://www.espressif.com/en/products/hardware/esp32/overview) 
- [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/)
- [WiFi library for ESP32](https://github.com/espressif/arduino-esp32)
- [ESP32Ping library](https://github.com/roberttidey/ESP32Ping)
- [WiFiSniffer library](https://github.com/roberttidey/WiFiSniffer)

## Installation

1. **Install Libraries:**
   - Ensure you have the `WiFi`, `ESP32Ping`, and `WiFiSniffer` libraries installed in your Arduino IDE or PlatformIO environment.

2. **Upload the Code:**
   - Connect your ESP32 board to your computer.
   - Open the `ESP32_WiFi_Packet_Sniffer.ino` file in the Arduino IDE or PlatformIO.
   - Replace `your_ssid` and `your_password` with your WiFi credentials.
   - Choose the correct board and port in the Arduino IDE or PlatformIO.
   - Upload the code to your ESP32 board.

## Code Explanation

### Libraries

- `WiFi.h`: Handles WiFi connection.
- `ESP32Ping.h`: Provides functionality to ping devices (not used in this code but required by `WiFiSniffer`).
- `WiFiSniffer.h`: Provides functions to sniff and analyze WiFi packets.

### Configuration

- `const char* ssid` and `const char* password`: Your WiFi network credentials.
- `int channel`: Channel to sniff (default is 1, can be adjusted if needed).

### Setup

- Connects to the specified WiFi network.
- Initializes the WiFi sniffer to start capturing packets.

### Loop

- Continuously sniffs network packets.
- Analyzes TCP packets and identifies HTTP requests.
- Prints device IP, URL, destination IP, and port to the Serial Monitor.

### Functions

- `void analyzePacket(wifi_sniffer_packet_t* packet)`: Analyzes each captured packet for TCP and HTTP requests.
- `String getUrlFromPacket(wifi_sniffer_packet_t* packet)`: Placeholder function for extracting URLs from HTTP packets (not yet implemented).

## Notes

- The `getUrlFromPacket` function is not implemented. Parsing HTTP request packets to extract URLs can be complex and is beyond the scope of this simple example.
- For advanced use cases, consider implementing packet parsing and URL extraction according to your requirements.

## Troubleshooting

- Ensure your ESP32 is properly connected and selected in the Arduino IDE or PlatformIO.
- Verify that your WiFi credentials are correct.
- If you encounter issues, check the Serial Monitor for connection and sniffer initialization messages.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For any questions or issues, please open an issue on the project repository or contact [your email address].

Happy sniffing!

