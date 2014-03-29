//Camera_Sensor_Pixy_Testbench

#include EEPROM.h
#include <Pixy.h>

const int EE_SIZE = 128;

Pixy pixy;

void setup()
{
  Serial.begin(9600);
  Serial.print("Camera_Sensor_Pixy_Testbench\n");
  Serial.print
}

void loop()
{
  static int i = 0;
  uint16_t blocks;
  
  while (i < EE_SIZE){
  
  //case 1
  pixy.blocks[i].signature = 1;
  pixy.blocks[i].x = 159;
  pixy.blocks[i].y = 109;
  pixy.blocks[i].width = 61;
  pixy.blocks[i].height = 61;
  pixy.blocks[i].print();
  delay(20);
  i++;
  
  //case 2
  pixy.blocks[i].signature = 1;
  pixy.blocks[i].x = 173;
  pixy.blocks[i].y = 114;
  pixy.blocks[i].width = 60;
  pixy.blocks[i].height = 61;
  pixy.blocks[i].print();
  delay(20);
  i++;
  
  //case 3
  pixy.blocks[i].signature = 1;
  pixy.blocks[i].x = 146;
  pixy.blocks[i].y = 111;
  pixy.blocks[i].width = 70;
  pixy.blocks[i].height = 65;
  pixy.blocks[i].print();
  delay(20);
  i++;  
  
  //Serial.println(i);
  }
}
  
