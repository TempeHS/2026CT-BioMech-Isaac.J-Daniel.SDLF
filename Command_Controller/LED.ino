#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// Initialize display (SSD1306 compatible)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup(void) {
  u8g2.begin();
  Serial.begin(9600);
  Serial.println("OLED Display initialized");
}

void loop(void) {
  u8g2.clearBuffer();                   // Clear internal memory

  u8g2.setFont(u8g2_font_ncenB08_tr);   // Choose font
  u8g2.drawStr(0, 15, "Hello World!");  // Write at (x=0, y=15)

  u8g2.setFont(u8g2_font_ncenB14_tr);   // Larger font
  u8g2.drawStr(0, 40, "Arduino");

  u8g2.sendBuffer();                    // Transfer to display

  delay(2000);
}
// #include <Arduino.h>
// #include <Wire.h>
// #include <U8g2lib.h>
// 
//  // Initialize display (SSD1306 compatible)
//  U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
// 
// void OLEDsetup() {
//   u8g2.begin();
//   Serial.begin(9600);
//   Serial.println("OLED Display initialized");
// }
// void LEDLoop() {
// 
//   // Powering on screen
//   u8g2.clearBuffer();
// 
//   u8g2.setFont(u8g2_font_ncenB08_tr);
//   u8g2.drawStr(0, 15, "Powering on...");
// 
//   u8g2.setFont(u8g2_font_ncenB14_tr);
//   u8g2.drawStr(0, 40, "Welcome!");
// 
//   u8g2.sendBuffer();
//   
//   delay(2000); // Show welcome for 2 seconds
// }
//  if (!logoShown) {
//  display.clear();
//  // Draw a circle for the face
//  display.drawCircle(64, 32, 20);
//  // Eyes
//  display.drawDisc(56, 28, 2);
//  display.drawDisc(72, 28, 2);
//  // Smile
//  display.drawArc(64, 34, 12, 0, 180);
//  display.sendBuffer();
//  logoShown = true;
//  delay(3000); // Show logo for 3 seconds
//  display.clear();
//  display.sendBuffer();
//}
//
//}