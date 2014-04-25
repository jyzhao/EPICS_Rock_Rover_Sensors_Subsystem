//Sensor_Receiver
//Jiyuan Zhao
//EPICS Rock Rover
//Purdue University, 2014

//This module receives string message from Sensor_Interpreter_Transmitter via UART Serial.
//Wire Connection:
//Interpreter_Transmitter -> Receiver
//5V  -> 5V
//GND -> GND
//TX  -> RX
//RX  -> TX

char val = 0;  //initialized val to an empty char

void setup() {
  //set baud rate to 9600
  Serial.begin(9600);
  
  //print setup message
  Serial.println("\nEPICS: Rock Rover Team\nCamera & Sensor Subsystem\nPowered by Pixy\nJiyuan Zhao");
  Serial.println("Start reading from interpreter/transmitter...");
}

void loop() {
  
  if(Serial.available() > 0){  //listen to serial port, TRUE if there's a signal coming
    val = Serial.read();  //read the signal and store it into val
    Serial.print(val);  //print val to serial monitor
  }
}
