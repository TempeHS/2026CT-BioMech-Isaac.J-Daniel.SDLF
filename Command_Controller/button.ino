#include <Arduino.h>

const int BUTTON_PIN = 8;
const int BUZZER_PIN = 4;

void buttonSetup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  
  Serial.println("=== DIAGNOSTIC START ===");
  delay(1000);
}

void buttonLoop() {

  int buttonRaw = digitalRead(BUTTON_PIN);
  

  digitalWrite(BUZZER_PIN, HIGH);
  delay(500);
  digitalWrite(BUZZER_PIN, LOW);
  delay(500);
  
  // Output every 1 second
  Serial.print("Button D8: ");
  Serial.println(buttonRaw == LOW ? "PRESSED" : "NOT PRESSED");
  Serial.println("Buzzer D4: Should be buzzing for 500ms");
  Serial.println("---");
  
  delay(1000);
}