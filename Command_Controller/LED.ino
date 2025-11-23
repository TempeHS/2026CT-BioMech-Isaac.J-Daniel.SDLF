// OLED status display for device power, pairing, and battery
#include <Wire.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C display(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
const int BATTERY_PIN = A0; // Analog pin for battery voltage

void setup() {
  Serial.begin(9600);
  display.begin();

  // Powering on screen
  display.clearBuffer();
  display.setFont(u8g2_font_ncenB08_tr);
  display.drawStr(0, 20, "Powering on...");
  display.drawStr(0, 40, "Welcome!");
  display.sendBuffer();
  delay(2000); // Show welcome for 2 seconds

  display.clearDisplay(); // Clear after welcome
}

void loop() {
  // Example: Show battery and Bluetooth status
  int raw = analogRead(BATTERY_PIN); // 0-16383 (R4 WiFi)
  float voltage = raw * (5.0 / 16383.0); // Adjust divider math as needed
  int percent = map(raw, 0, 16383, 0, 100);

  // Simulate Bluetooth status (replace with actual check)
  String btStatus = "Disconnected"; // or "Pairing...", "Connected"

  display.clearBuffer();
  display.setFont(u8g2_font_ncenB08_tr);

  // Battery icon (simple rectangle)
  display.drawFrame(0, 0, 20, 10);
  display.drawBox(20, 3, 3, 4); // battery tip
  display.drawBox(2, 2, percent/5, 6); // fill level

  // Battery percentage
  char battStr[16];
  sprintf(battStr, "%d%% %.2fV", percent, voltage);
  display.drawStr(30, 8, battStr);

  // Bluetooth status
  display.drawStr(0, 30, ("BT: " + btStatus).c_str());

  display.sendBuffer();
  delay(500);
}