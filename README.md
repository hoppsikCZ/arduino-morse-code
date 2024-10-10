# Morse Code LED Display

This Arduino program reads a string from the serial input and converts each character into Morse code, which is then displayed using an LED. The program supports both uppercase and lowercase letters (A-Z) and digits (0-9).

## Usage

### Setup

- Upload this to your arduino device.
- Connect an LED to the specified pin (e.g., `LED_PIN`).
- Open any serial monitor and you're ready to go.

### Input

- Type a message in the serial monitor and send it.
- The LED will blink the Morse code for each valid character in the message.

### Feedback

- The serial monitor will display the Morse code being shown and any invalid characters encountered.