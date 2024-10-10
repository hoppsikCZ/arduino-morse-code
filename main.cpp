#include <Arduino.h>

#define LED_PIN 2
#define DOT_DURATION 250
#define DASH_DURATION 3 * DOT_DURATION
#define SPACE_DURATION 7 * DOT_DURATION



const String morseCodes[36] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--..", // Z
  "-----", // 0
  ".----", // 1
  "..---", // 2
  "...--", // 3
  "....-", // 4
  ".....", // 5
  "-....", // 6
  "--...", // 7
  "---..", // 8
  "----."  // 9
};

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void morseCode(String message) {
  Serial.print("New message: ");
  Serial.println(message);
  for (int i = 0; i < message.length(); i++) {
    char c = message.charAt(i);
    
    if (c == ' ') {
      delay(i == 0 ? SPACE_DURATION : SPACE_DURATION - DASH_DURATION);
    } else {
      int index = -1;

      if (c >= 'a' && c <= 'z') {
        c = c - 32;
      }

      if (c >= 'A' && c <= 'Z') {
        index = c - 'A';
      } else if (c >= '0' && c <= '9') {
        index = c - '0' + 26;
      }

      if (index != -1) {
        String morseCode = morseCodes[index];
        Serial.print("Displaying: ");
        Serial.println(morseCode);
        for (int j = 0; j < morseCode.length(); j++) {
          if (j > 0) {
            delay(DOT_DURATION);
          }

          char morseChar = morseCode.charAt(j);
          digitalWrite(LED_PIN, HIGH);
          delay(morseChar == '.' ? DOT_DURATION : DASH_DURATION);
          digitalWrite(LED_PIN, LOW);
        }

        delay(DASH_DURATION);
      }
      else {
        Serial.print("Invalid character \"");
        Serial.print(c);
        Serial.println("\". Skipping");
        Serial.println("Valid characters are A-Z and 0-9");
      }
    }
  }

  Serial.println("End of message");
  Serial.println();
  delay(SPACE_DURATION - DASH_DURATION);
}

void loop() {
  if (Serial.available()) {
    morseCode(Serial.readString());
  }
}