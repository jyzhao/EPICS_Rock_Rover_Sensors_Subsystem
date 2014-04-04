/*     
 For more details see: http://projectsfromtech.blogspot.com/
 

 Read char value from Serial Monitor
 Display that value on the Serial Monitor
 */


char val = 0;
int incoming = 0;

void setup()
{
  Serial.begin(9600);     
  Serial.println("Serial Monitor Connected");  
}

void loop()
{
  /*
  incoming = Serial.available();  
  while (incoming == 0)     //keep checking until something is available
  {
    incoming = Serial.available();
  }*/
  if (Serial.available() > 0)
  {
   val = Serial.read();  //Reads the input from the Serial Monitor
   Serial.print(val);
  }
}


