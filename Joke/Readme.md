# Joke Display with TFT and ESP32

This project displays programming jokes on an Adafruit ILI9341 TFT display using an ESP32 microcontroller. The jokes are fetched from the JokeAPI service over WiFi. The TFT screen updates to show a new joke each time a button is pressed.

## Components

- ESP32 microcontroller
- Adafruit ILI9341 TFT display
- Push button
- Breadboard and jumper wires

## Libraries

- `WiFi` - Handles WiFi connections
- `HTTPClient` - Manages HTTP requests
- `ArduinoJson` - Parses JSON responses
- `Adafruit_GFX` - Core graphics library for Adafruit displays
- `Adafruit_ILI9341` - Driver for the ILI9341 TFT display

## Pin Connections

- **TFT Display:**
  - DC (Data/Command) -> Pin 2
  - CS (Chip Select) -> Pin 15

- **Button:**
  - Connected to Pin 5
  - Pull-up resistor is enabled (INPUT_PULLUP mode)

## How to Use

1. **Set up the hardware:**
   - Connect the TFT display and button to the ESP32 as specified in the Pin Connections section.
   - Ensure the TFT display is powered correctly.

2. **Upload the Code:**
   - Use the Arduino IDE or PlatformIO to upload the code to your ESP32.

3. **Connect to WiFi:**
   - Update the `ssid` and `password` variables in the code with your WiFi credentials.

4. **Power the ESP32:**
   - Once powered, the ESP32 will connect to WiFi and display the first joke on the TFT screen.

5. **Press the Button:**
   - Press the button connected to Pin 5 to load and display a new joke.

## Code Explanation

- `getJoke()`: Makes an HTTP GET request to the JokeAPI service to fetch a programming joke. Parses the JSON response and returns the joke as a `String`.

- `nextJoke()`: Clears the screen, displays a loading message, fetches a new joke, and updates the TFT display with the joke.

- `setup()`: Initializes the TFT display, connects to WiFi, and displays the first joke.

- `loop()`: Continuously checks if the button is pressed. If pressed, it clears the screen and displays a new joke.

## Troubleshooting

- **WiFi Connection Issues:** Ensure the `ssid` and `password` are correctly set and that your ESP32 is within range of your WiFi network.

- **Display Issues:** Verify that the TFT display connections are secure and that the display is powered.

- **Button Not Responding:** Confirm that the button is correctly connected to Pin 5 and that the pull-up resistor is functioning.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

- Adafruit for the TFT display and libraries
- JokeAPI for the jokes
