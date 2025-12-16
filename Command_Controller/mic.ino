// ...existing code...
const uint8_t LED_PIN = 4;
const uint8_t PIR_LEFT_PIN = 8;
const uint8_t PIR_RIGHT_PIN = 7;

const unsigned long TRIGGER_WINDOW = 800;

enum Sensor { NONE, LEFT, RIGHT };

Sensor firstTrigger = NONE;
unsigned long firstTime = 0;

void micSetup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_LEFT_PIN, INPUT);
  pinMode(PIR_RIGHT_PIN, INPUT);

  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);

  // { changed code }
  Serial.println("micSetup: waiting 30s for PIR warm-up...");
  delay(30000); // PIR sensors commonly need 20-60s to stabilise
  Serial.println("micSetup: ready");
  // ...existing code...
}
// ...existing code...

void micLoop() {
  bool leftState = digitalRead(PIR_LEFT_PIN) == HIGH;
  bool rightState = digitalRead(PIR_RIGHT_PIN) == HIGH;
  unsigned long now = millis();

  // { changed code: periodic debug output }
  static unsigned long lastDebug = 0;
  if (now - lastDebug > 300) {
    Serial.print("PIR L=");
    Serial.print(leftState ? "1" : "0");
    Serial.print("  R=");
    Serial.println(rightState ? "1" : "0");
    lastDebug = now;
  }
  // ...existing code...

  if (firstTrigger == NONE) {
    if (rightState) {
      firstTrigger = RIGHT;
      firstTime = now;
      delay(30);
    } else if (leftState) {
      firstTrigger = LEFT;
      firstTime = now;
      delay(30);
    }
  } else {
    if (now - firstTime > TRIGGER_WINDOW) {
      firstTrigger = NONE;
    } else {
      if (firstTrigger == LEFT && rightState) {
        digitalWrite(LED_PIN, LOW);
        Serial.println("Detected motion: LEFT -> RIGHT  (LED OFF)");
        firstTrigger = NONE;
        delay(100);
      } else if (firstTrigger == RIGHT && leftState) {
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Detected motion: RIGHT -> LEFT  (LED ON)");
        firstTrigger = NONE;
        delay(100);
      }
    }
  }

  delay(20);
}
