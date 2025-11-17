void setup () {
  OLED_setup();
  touchsensor_setup();
}

void loop () {
  OLED();
  touchsensor();
  
