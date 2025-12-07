// ...new file...
const int GESTURE_PIN = 8;   // Grove D8
const int BUZZER_PIN  = 4;   // Grove D4

const unsigned long DEBOUNCE_MS = 200;
const int BUZZ_FREQ = 2000;      // Hz (for passive buzzer)
const int BUZZ_DURATION = 150;   // ms
const int ACTIVE_PULSE_MS = 150; // ms (for active buzzer)

int lastState = LOW;
unsigned long lastTime = 0;

void micSetup() {
  Serial.begin(9600);
  pinMode(GESTURE_PIN, INPUT); // if sensor is active-low, try INPUT_PULLUP and invert logic below
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.println("Gesture -> Buzzer test ready. Trigger the sensor on D8.");
}

void micLoop() {
  int state = digitalRead(GESTURE_PIN);

  if (state != lastState && (millis() - lastTime) > DEBOUNCE_MS) {
    Serial.print("GESTURE PIN changed: ");
    Serial.println(state == HIGH ? "HIGH" : "LOW");
    lastTime = millis();

    // Try passive buzzer first (tone). If your buzzer is active, the next block will also pulse it.
    Serial.println(" -> Attempting tone()");
    tone(BUZZER_PIN, BUZZ_FREQ);
    delay(BUZZ_DURATION);
    noTone(BUZZER_PIN);

    // Also try driving pin HIGH (active buzzer)
    Serial.println(" -> Attempting digital HIGH pulse (active buzzer test)");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(ACTIVE_PULSE_MS);
    digitalWrite(BUZZER_PIN, LOW);

    Serial.println("Done.");
  }

  lastState = state;
  delay(10);
}