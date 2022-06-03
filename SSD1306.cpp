#include "SSD1306.h"

/*
* Send command to SSD1306
* @param cmd
*/
void SSD1306::sendCMD(byte cmd)
{
  Wire.beginTransmission(this->addressI2C);
  Wire.write(0x80);// Set SSD1306 Command mode
  Wire.write(cmd);
  Wire.endTransmission();
}

/*
* Send data to SSD1306
* @param data
*/
void SSD1306::sendData(byte data)
{
  Wire.beginTransmission(this->addressI2C);
  Wire.write(0x40);// Set SSD1306 data mode
  Wire.write(data);
  Wire.endTransmission();
}

// Off OLED
void SSD1306::off()
{
  this->sendCMD(0xAE);
}

// On OLED
void SSD1306::on()
{
  this->sendCMD(0xAF);
}

/*
* Set OLED contrast/brightness
* @param brightness from 0 to 255
*/
void SSD1306::setContrast(byte brightness)
{
  this->sendCMD(0x81);
  this->sendCMD(brightness);
}

void SSD1306::normal()
{
  this->sendCMD(0xA6);
}

void SSD1306::inverse()
{
  this->sendCMD(0xA7);
}

void SSD1306::init()
{
  this->off();
  this->normal();
  // CHARGEPUMP
  this->sendCMD(0x8D);
  this->sendCMD(0x14);
  //MEMORYMODE
  this->sendCMD(0x20);
  this->sendCMD(0x00);
  // orientation
  this->sendCMD(0xA1);
  this->sendCMD(0xC8);
  this->setContrast(255);
  // HORIZONTAL_ADDRESSING
  this->sendCMD(0x20);
  this->sendCMD(0x00);
  this->clear();
}

void SSD1306::rotate()
{
  this->sendCMD(0xA0);
  this->sendCMD(0xC0);
}

void SSD1306::clear()
{
  this->sendCMD(0x21);
  this->sendCMD(0);
  this->sendCMD(127);
  this->sendCMD(0x22);  
  this->sendCMD(0);
  this->sendCMD(7);

  byte i, j;

  for(j = 0; j < 8; j++)
  {      
      for(i = 0; i < 128; i++)
      {
        this->sendData(0);   
      }
  }
  
}
