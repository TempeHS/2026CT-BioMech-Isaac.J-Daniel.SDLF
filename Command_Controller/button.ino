#include <Wire.h>

const int ledOutPin = 8;  
const int buttonPin = 4;    

const bool ledActiveHigh = false; 

unsigned long lastDebounceMillis = 0;
const unsigned long debounceDelay = 50;
int lastReading = HIGH;
int stableReading = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledOutPin, OUTPUT);
  digitalWrite(ledOutPin, ledActiveHigh ? LOW : HIGH); 
  Serial.println("Ready - LED while held");
  Serial.print("ledActiveHigh=");
  Serial.println(ledActiveHigh ? "true" : "false");
}

void loop() {
  int reading = digitalRead(buttonPin); 

  if (reading != lastReading) {
    lastDebounceMillis = millis();
  }

  if (millis() - lastDebounceMillis > debounceDelay) {
    stableReading = reading;
  }

  bool wantLedOn = (stableReading == LOW);
  if (ledActiveHigh) {
    digitalWrite(ledOutPin, wantLedOn ? HIGH : LOW);
  } else {
    digitalWrite(ledOutPin, wantLedOn ? LOW : HIGH);
  }

  // Debug
  Serial.print("raw=");
  Serial.print(reading);
  Serial.print(" stable=");
  Serial.print(stableReading);
  Serial.print(" wantLedOn=");
  Serial.print(wantLedOn ? "Y" : "N");
  Serial.print(" led=");
  Serial.println(digitalRead(ledOutPin) ? "HIGH" : "LOW");

  lastReading = reading;
  delay(25);
}