#include <Wire.h>
#include <U8g2lib.h>

const int lightPin = A0;            
const int threshold = 2000;         
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

unsigned long lastBlinkMillis = 0;
const unsigned long blinkInterval = 300; // ms
bool blinkOn = false;

void setup() {
  Serial.begin(9600);
  ledSetup();
  pinMode(lightPin, INPUT);
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB14_tr);
}

void loop() {
  ledLoop();
  int raw = analogRead(lightPin); // 0-16383 on R4
  Serial.print("light raw: ");
  Serial.println(raw);

  
  bool triggered = (raw < threshold);

  if (triggered) {
    unsigned long now = millis();
    if (now - lastBlinkMillis >= blinkInterval) {
      lastBlinkMillis = now;
      blinkOn = !blinkOn;
    }

    u8g2.clearBuffer();
    if (blinkOn) {
      u8g2.drawStr(0, 32, "test");
    }
    u8g2.sendBuffer();
  } else {
    
    u8g2.clearBuffer();
    u8g2.sendBuffer();
    blinkOn = false;
  }

  delay(50);
}
