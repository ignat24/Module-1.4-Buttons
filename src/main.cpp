#include <Arduino.h>

constexpr uint8_t LED_1 = 15;
constexpr uint8_t LED_2 = 16;
constexpr uint8_t BUILTIN_BUTTON = 0;
constexpr uint8_t OUTSIDE_BUTTON = 21;
uint8_t currentMode = 1;
constexpr uint8_t DELAY_MODE_1 = 200;
constexpr uint32_t DELAY_MODE_2 = 1000;

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(BUILTIN_BUTTON, INPUT);
  pinMode(OUTSIDE_BUTTON, INPUT_PULLUP);
  Serial.begin(115200);
}

void sinkhronnyyBlink();

void asynchronousBlink();


void loop() {
  if (digitalRead(BUILTIN_BUTTON) == LOW) {
      currentMode = 2;
  }
  if (digitalRead(OUTSIDE_BUTTON) == LOW) {
    currentMode = 1;
  }
  Serial.printf("Current Mode = %u \n", currentMode);

  switch (currentMode)
  {
  case 1:
    sinkhronnyyBlink();
    break;
  
  case 2:
    asynchronousBlink();
    break;
  }
  delay(100);
}

void sinkhronnyyBlink() {
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, HIGH);
  delay(DELAY_MODE_1);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, LOW);
}

void asynchronousBlink() {
  digitalWrite(LED_1, HIGH);
  delay(DELAY_MODE_2);
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);
  delay(DELAY_MODE_2);
  digitalWrite(LED_2, LOW);
}