#include <Wire.h>
#include "Arduino.h"

class SSD1306 {
  private:
    byte addressI2C;
  public:
    SSD1306(byte addressI2C)
    {
      this->addressI2C = addressI2C;
      Serial.print(this->addressI2C, HEX);
    }
    void test();
    void sendCMD(byte cmd);
    void sendData(byte data);
    void off();
    void on();
    void setContrast(byte brightness);
    void normal();
    void inverse();
    void init();
    void rotate();
    void clear();
};
