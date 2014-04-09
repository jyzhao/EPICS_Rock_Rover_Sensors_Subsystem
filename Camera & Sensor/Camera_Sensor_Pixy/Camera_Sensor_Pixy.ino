//include libraries
//SPI.h for Pixy API
//Pixy.h for Pixy firmware
#include <SPI.h>  
#include <Pixy.h>
#include <EEPROM.h>
const int EE_SIZE = 32;
uint16_t blocks;
static boolean finishRead = false;

enum Color {
  Red = 1,
  Orange = 2,
  Yellow = 3,
  Green = 4,
  Cyan = 5,
  Blue = 6,
  Violet = 7
};

//global instance
Pixy pixy;
static int i =0;
char val = 0;

void setup()
{
  //baud rate at 9600
  Serial.begin(9600);
  Serial.println("EPICS: Rock Rover Team\nCamera & Sensor Subsystem\nPowered by Pixy\nJiyuan Zhao");
  //Serial.println("Start reading from EEPROM");
  Serial.println("Waiting for serial input\nPlease press RESET on transmitter Arduino");
}

void loop()
{ 
  int j;
  //uint16_t blocks;
  char buf[16]; 
  Color colorCode;
  char temp[64];
  
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
  
  //blocks = pixy.getBlocks();
  
//  while(i<EE_SIZE){
//    pixy.blocks[i].signature = EEPROM.read(3*i);
//    pixy.blocks[i].x = EEPROM.read(3*i+1);
//    pixy.blocks[i].y = EEPROM.read(3*i+2);
//    pixy.blocks[i].width = 0;
//    pixy.blocks[i].height = 0;
//    /*
//    Serial.print(EEPROM.read(3*i));
//    Serial.print(" ");
//    Serial.print(EEPROM.read(3*i+1));
//    Serial.print(" ");
//    Serial.println(EEPROM.read(3*i+2));
//    */
//    
//    //delay(500);
//    i++;
//  }
  
//  if (i == EE_SIZE && finishRead == false){
//   finishRead = true; 
//   for (j = 0;j<EE_SIZE;j++){
//     //pixy.blocks[j].print();
//     colorCode = Color(pixy.blocks[j].signature);
//     sprintf(temp,"Color: %i; X: %i; Y: %i",pixy.blocks[j].signature,pixy.blocks[j].x,pixy.blocks[j].y);
//     Serial.println(temp);
//     //Serial.write(temp);
//     
//     delay(500);
//   }
//   Serial.println("Finish reading from EEPROM.");
//   Serial.end();
//  }
  
  //read from tx,rx serial port
  if(Serial.available() > 0){
    val = Serial.read();
    Serial.print(val);
  }
  
  //communicate with Pixy via SPI
  /*
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
*/
}

