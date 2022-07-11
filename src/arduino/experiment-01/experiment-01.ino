/*
  experiment-01 (LED)
  Turns an LED ON and OFF.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/
#define LED 13
void setup() {
  
  pinMode(LED, OUTPUT);
}


void loop() {
  digitalWrite(LED, HIGH);  
  delay(500);
  digitalWrite(LED, LOW);    
  delay(500);                      
}
