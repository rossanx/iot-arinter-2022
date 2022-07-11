
/*
  experiment-10 Temperature
  Reads ambient temperature

  Arduino ADC converter outputs values from 0-1023 (10 bit value). So, we must
  convert this value to a voltage between 0-5v.
  Resolution between readings of 5 volts / 1024 units: 0.0049 volts (4.9 mV) per unit.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

#define TEMP_PIN A0
int sensor_value = 0;
int state = 0;
float temperature_celsius=0.0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  sensor_value = analogRead(TEMP_PIN);
  temperature_celsius = (sensor_value * ( 5000 / 1024.0)) / 10;
  Serial.print(sensor_value);
  Serial.print(" - Celsius: ");
  Serial.println(temperature_celsius);
 
  delay(1000);
}
