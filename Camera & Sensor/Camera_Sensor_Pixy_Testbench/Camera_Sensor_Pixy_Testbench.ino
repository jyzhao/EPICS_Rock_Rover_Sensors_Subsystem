//Camera_Sensor_Pixy_Testbench

#include <EEPROM.h>
#include <Pixy.h>
#include <SPI.h>
const int EE_SIZE = 32;
static int i = 0;
uint16_t blocks;
static boolean finishDump = false;


Pixy pixy,dummyPixy;

void setup()
{
  Serial.begin(9600);
  Serial.println("Camera_Sensor_Pixy_Testbench\n");
  Serial.println("Start dumping data into EEPROM");
}

void loop()
{
  for (i;i++;i<EE_SIZE){
    writeDummyPixyToEEPROM(i);
    delay(20);
  }
  
  if (i == EE_SIZE - 1) {
    finishDump = true;
    Serial.println("Finish dumping data into EEPROM");
}  

}

//subroutine for setup dunmmyPixy, write data to EEPROM
void writeDummyPixyToEEPROM(int i){
    dummyPixy.blocks[i].signature = (int)random(1,8);
    dummyPixy.blocks[i].x = (int)random(255);
    dummyPixy.blocks[i].y = (int)random(255);
    EEPROM.write(3*i,dummyPixy.blocks[i].signature);
    EEPROM.write(3*i+1,dummyPixy.blocks[i].x);
    EEPROM.write(3*i+2,dummyPixy.blocks[i].y);
    
    Serial.print("dummyPixy ");
    Serial.print(i);
    Serial.print(" at EEPROM location ");
    Serial.print(3*i);
    Serial.print(" Object Color: ");
    Serial.print(dummyPixy.blocks[i].signature);
    Serial.print(", X: ");
    Serial.print(dummyPixy.blocks[i].x);    
    Serial.print(", Y: ");
    Serial.print(dummyPixy.blocks[i].y);
    Serial.println();
}
