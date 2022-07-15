/*
  experiment-02 (SERIAL WRITE + SRAM x Flash memory)
  Writes to serial.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello World.");
  //Serial.println(F("Hello World.")); // Saves 12 bytes in SRAM, uses 12 bytes more in Flash.
  delay(1000);
}
