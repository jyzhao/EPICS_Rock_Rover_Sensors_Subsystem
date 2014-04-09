//Camera_Sensor_Pixy_Testbench

#include <EEPROM.h>
#include <Pixy.h>
#include <SPI.h>
static int i = 0;
uint16_t blocks;

Pixy dummyPixy;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char temp[128];
  
  dummyPixy.blocks[i].signature = (int)random(1,8);
  dummyPixy.blocks[i].x = (int)random(255);
  dummyPixy.blocks[i].y = (int)random(255);
  dummyPixy.blocks[i].width = (int)random(255);
  dummyPixy.blocks[i].height = (int)random(255);  
  sprintf(temp,"sig: %d x: %d y: %d width: %d height: %d\n",dummyPixy.blocks[i].signature,dummyPixy.blocks[i].x,dummyPixy.blocks[i].y,dummyPixy.blocks[i].width,dummyPixy.blocks[i].height);
  Serial.write(temp);
  i++; 
}
