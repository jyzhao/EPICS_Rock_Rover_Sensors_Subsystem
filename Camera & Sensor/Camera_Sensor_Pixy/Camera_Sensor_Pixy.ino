//include libraries
//SPI.h for Pixy API
//Pixy.h for Pixy firmware
#include <SPI.h>  
#include <Pixy.h>

//global instance
Pixy pixy;

void setup()
{
  //baud rate at 9600
  Serial.begin(9600);
  Serial.print("EPICS: Rock Rover Team\nCamera & Sensor Subsystem\nPowered by Pixy\nJiyuan Zhao");
}

void loop()
{ 
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[16]; 
  
  //block contains the number of objects Pixy has detected
  //detailed object information is in the blocks[] array
  /*
  pixy.blocks[i].signature The signature number of the detected object (1-7)
  pixy.blocks[i].x The x location of the center of the detected object (0 to 319)
  pixy.blocks[i].y The y location of the center of the detected object (0 to 199)
  pixy.blocks[i].width The width of the detected object (1 to 320)
  pixy.blocks[i].height The height of the detected object (1 to 200)
  pixy.blocks[i].print() A member function that prints the detected object information to the serial port  
  */
  
  blocks = pixy.getBlocks();
  
  
  if (blocks)
  {
    i++;
    
    //outputs object information every 50 frames (1 second)
    if (i%50==0)
    {
      //Detected blocks => buf
      sprintf(buf, "Detected %d:\n", blocks);
      //print buf to monitor
      Serial.print(buf);
      //print detailed object information in blocks[] array
      for (j=0; j<blocks; j++)
      {
        //detailed object information in blocks[] array
        sprintf(buf, "  block %d: ", j);
        Serial.print(buf); 
        pixy.blocks[j].print();
      }
    }
  }  
}

