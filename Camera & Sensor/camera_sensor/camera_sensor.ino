#include <Pixy.h>
#include <PixyI2C.h>
#include <TPixy.h>

/*
Camera & Sensor Module
This module is designed for object detection of the Rock Rover.
This module consists of two parts:
1. Pixy (CMUcam5) vision sensor
2. Parallax 15-122cm Laser Range Finder. 
*/


  //LRF commands
  const char LRF_u = 'U';          //automatic baud rate detection
  //basic commands
  const char LRF_r = 'R';          //single range measurement(returns a 4-digit value in millimeters)
  const char LRF_e = 'E';          //adjust camera for current lighting conditions
  const char LRF_s = 'S';          //reset camera to initial settings
  const char LRF_v = 'V';          //print version information
  const char LRF_h = 'H';          //print list of available commands
  
  //advanced commands
  const char LRF_o = 'O';          //display coordinate, mass, and centroid information for all detected blobs
  const char LRF_x = 'X';          //calibrate camera system for range finding
  const char LRF_c = 'C';          //capture & send single frame (16 bits/pixel YUV422 color @ 640*16) w/ laser enabled
  const char LRF_p = 'P';          //capture & send image processed frame (16 bits/pixel YUV422 color @ 640*16) w/ background subtraction

  //camera resolution
  const int RESOLUTION_X = 1280;
  const int RESOLUTION_Y = 800;
  
  //camera error tolerence
  const int TOLERENCE = 0.02;
  

void setup()
{
  Serial.begin(9600);              //baud rate
  
  //pixy var
  int pixy_sync;                   //synchronization tag, indicates start of object block
  int pixy_checksum;               //simple checksum for the rest of the object block data
  int pixy_signature;              //color signature of object(1-7) or list of signature for color code
  int pixy_x_position;             //X position of object center in image
  int pixy_y_position;             //Y position of object center in image
  int pixy_size;                   //size(area) of object in image
  //int pixy_angle;                //angle of object(optional, only available for color codes)
  
  //LRF var
  int LRF_distance;                //4-digit distance measurement in millimeters
  
}

void loop()
{
  int pixyX, pixyY;
  
  //pixyX = 
  //pixyY = 
  
  //control signal
  int move_horizontal;             //control horizontal movement: 0 for left, 1 for right
  int move_vertical;               //control vertical movement: 0 for up, 1 for down
  
  
  if ((pixyX < (TOLERENCE*RESOLUTION_X/2)) && (pixyX > -(TOLERENCE*RESOLUTION_X/2))) {  //check if it is pointing at the object
    if ((pixyY < (TOLERENCE*RESOLUTION_Y/2)) && (pixyY > -(TOLERENCE*RESOLUTION_Y/2))) {
      //enable LRF measurements
    }
    else{
      move_vertical = (pixyY > 0) ? 0 : 1;
    }
  }
  else{
    move_horizontal = (pixyX > 0) ? 0 : 1;
  }
}
  
