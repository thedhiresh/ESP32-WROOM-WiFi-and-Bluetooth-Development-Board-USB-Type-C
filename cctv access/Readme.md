# ESP32 CCTV Camera Access

**Warning: This project is for educational purposes only.** Attempting to access a CCTV camera without the owner's consent or knowledge is illegal and unethical. Please respect the privacy and security of others' devices.

## Overview

This project demonstrates how to access a CCTV camera using an ESP32 board, without knowing the camera's username and password. This is not a recommended or approved practice, and you should only use this project for legitimate purposes, such as accessing your own camera or with the explicit permission of the camera's owner.

## Hardware Requirements

- ESP32 board
- Wi-Fi module (built-in or external)
- CCTV camera with Wi-Fi connectivity

## Software Requirements

- ESP32 Arduino core or MicroPython
- Wi-Fi library for ESP32
- HTTP or RTSP library for ESP32 (depending on the camera's protocol)

## Setup

1. Connect your ESP32 board to your computer using a USB cable.
2. Install the ESP32 Arduino core or MicroPython on your computer.
3. Upload the provided code to your ESP32 board.
4. Connect to the camera's Wi-Fi network using the ESP32's Wi-Fi module.
5. Identify the camera's IP address using tools like `nmap` or `arp-scan`.
6. Update the code with the camera's IP address and protocol (HTTP or RTSP).

## Code

The code is provided in two versions: Arduino and MicroPython.

### Arduino Code

You can find the Arduino code in the `arduino` folder.

### MicroPython Code

You can find the MicroPython code in the `micropython` folder.

## Note

- This project is for educational purposes only.
- You should only use this project for legitimate purposes, such as accessing your own camera or with the explicit permission of the camera's owner.
- Attempting to access a CCTV camera without the owner's consent or knowledge is illegal and unethical.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
