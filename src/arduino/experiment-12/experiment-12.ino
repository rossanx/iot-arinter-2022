
/*
  experiment-12 Analog imput
  Reads potentiometer to increase/decrease delay time.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

#define LED 13
#define POT_PIN A0
int sensor_value = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  sensor_value = analogRead(POT_PIN);
  Serial.println(sensor_value);
  digitalWrite(LED, HIGH);
  delay(sensor_value);
  digitalWrite(LED, LOW);
  delay(sensor_value + 500);
  
}
