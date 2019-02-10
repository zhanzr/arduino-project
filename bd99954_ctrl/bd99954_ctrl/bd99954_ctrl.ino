//Arduino Uno control the BD99954 chip.
//Author: zhanzr@foxmail.com

#include <Wire.h>

#define BD_ADDR 0x09

//Bit 14 Trigger VRBOOST
#define VIN_CTRL_SET  0x0A
#define VRBOOST_SET 0x19

#define CHIP_ID 0x38
#define CHIP_REV 0x39
#define MAP_SET 0x3F

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(7, INPUT);
  Serial.begin(115200);
}

void wr16(uint8_t cmd, uint16_t d16)
{
  uint8_t dl = (uint8_t)d16;
  uint8_t dh = (uint8_t)(d16>>8);
    
  Wire.beginTransmission(BD_ADDR); // transmit to device
  Wire.write(cmd);
  Wire.write(dl);
  Wire.write(dh);
  Wire.endTransmission();    // stop transmitting]
}

uint16_t rd16(uint8_t cmd)
{
  uint16_t ret16 = 0;

  Wire.beginTransmission(BD_ADDR); // transmit to device
  Wire.write(cmd);
  Wire.endTransmission();    // stop transmitting]

  Wire.requestFrom(BD_ADDR, 2);

  while (2 != Wire.available())
  {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));    
  }

  uint8_t dl = Wire.read();
  uint8_t dh = Wire.read();
  ret16 = ((uint16_t)dh << 8) + dl;

  return ret16;
}

void loop() {
  uint16_t map_set = rd16(MAP_SET);
  Serial.println("MAP_SET:");
  Serial.println(map_set, HEX);
  
  uint16_t tmp = rd16(CHIP_ID);
  Serial.println("CHIP_ID:");
  Serial.println(tmp, HEX);
  
  tmp = rd16(CHIP_REV);
  Serial.println("CHIP_REV:");
  Serial.println(tmp, HEX);  
  
  tmp = rd16(VRBOOST_SET);
  Serial.println("VRBOOST_SET:");
  Serial.println(tmp, HEX);   

  wr16(VRBOOST_SET, 7000);

  tmp = rd16(VRBOOST_SET);
  Serial.println("VRBOOST_SET:");
  Serial.println(tmp, HEX);   
  
  tmp = rd16(VIN_CTRL_SET);
  Serial.println("VIN_CTRL_SET:");
  Serial.println(tmp, HEX);   
    
  delay(50000);
}
