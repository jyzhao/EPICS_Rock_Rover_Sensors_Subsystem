//Sensor_Receiver
//Jiyuan Zhao
//EPICS Rock Rover
//Purdue University, 2014

char val = 0;

void setup() {
  Serial.begin(9600);

  Serial.println("EPICS: Rock Rover Team\nCamera & Sensor Subsystem\nPowered by Pixy\nJiyuan Zhao");
  //Serial.println("Start reading from EEPROM");
  //Serial.println("Waiting for serial input\nPlease press RESET on transmitter Arduino");
  Serial.println("Start reading from interpreter/transmitter...");
}

void loop() {

  if(Serial.available() > 0){
    val = Serial.read();
    Serial.print(val);
  }
}
