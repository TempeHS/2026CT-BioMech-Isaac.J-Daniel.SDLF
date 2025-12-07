#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

 // Initialize display (SSD1306 compatible)
 U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

 bool logoShown = false;

void setup(void) {
  u8g2.begin();
  Serial.begin(9600);
  Serial.println("OLED Display initialized");
}
void loop(void) {

  // Powering on screen
  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 15, "Powering on...");

  u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.drawStr(0, 40, "Welcome!");

  u8g2.sendBuffer();
  
  delay(2000); // Show welcome for 2 seconds

  u8g2.clearBuffer();

  if (!logoShown) 
  u8g2.clearBuffer();
  // Draw a circle for the face
  u8g2.drawCircle(64, 32, 20);
  // Eyes
  u8g2.drawDisc(56, 28, 2);
  u8g2.drawDisc(72, 28, 2);
  // Smile
  u8g2.drawArc(64, 34, 12, 150, 240);
  u8g2.sendBuffer();
  logoShown = true;
  delay(3000); // Show logo for 3 seconds
  u8g2.clearBuffer();
  u8g2.sendBuffer();
}