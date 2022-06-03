#include <Wire.h>
#include "SSD1306.h"

#define OLED_ADDRESS 0x3C

SSD1306 oled = SSD1306(OLED_ADDRESS);

void setup() {
  Wire.begin();
  oled.init();
  oled.on();
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  oled.normal();
  delay(2000);
  oled.inverse();
  delay(2000);
}
