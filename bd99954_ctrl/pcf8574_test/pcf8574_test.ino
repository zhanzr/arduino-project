//Arduino Uno control the PCF8574A chip.
//Author: zhanzr@foxmail.com

#include <Wire.h>

#define PCF_ADDR 0x3F

#define RS_PIN  0
#define RW_PIN  1
#define E_PIN 2
#define BL_PIN 3
#define DB4_PIN 4
#define DB5_PIN 5
#define DB6_PIN 6
#define DB7_PIN 7

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
}

uint8_t tmp;
uint8_t _error;
uint8_t _address = PCF_ADDR;
uint8_t _data;
  
uint8_t read8()
{ 
  Wire.beginTransmission(_address);
  Wire.requestFrom(_address, 1);

   _data = Wire.read();

  _error = Wire.endTransmission();
  return _data;
}

void write8(uint8_t value)
{
  Wire.beginTransmission(_address);
  _data = value;
  Wire.write(_data);
  _error = Wire.endTransmission();
}

void toggle(uint8_t pin)
{
  switch(pin)
  {
    case RS_PIN:
    case RW_PIN:
    case E_PIN:
    read8();
    _data ^=  (1 << pin);
    write8(_data); 
    break;

    case BL_PIN:
    case DB4_PIN:
    case DB5_PIN:
    case DB6_PIN:
    case DB7_PIN:        
    if(_data &  (1 << pin))
    {
      _data &=  ~(1 << pin);
      write8(_data); 
    }
    else
    {
      _data |=  (1 << pin);
      write8(_data); 
    }
    break;
  }
}

uint8_t loop_idx;

void loop() {
  //write8(loop_idx++);
  //Serial.println(loop_idx, BIN);
  //Serial.println(read8(), BIN);   
  //Serial.println();     
//  toggle(RS_PIN);
//  delay(1000);
  
//  toggle(RW_PIN);
//  delay(1000);

//  toggle(E_PIN);
//  delay(1000);

  toggle(BL_PIN);
  delay(1000);

//  toggle(DB4_PIN);
//  delay(1000);
  
//  toggle(DB5_PIN);
//  delay(1000);

//  toggle(DB6_PIN);
//  delay(1000);

//  toggle(DB7_PIN);
//  delay(1000);
}
