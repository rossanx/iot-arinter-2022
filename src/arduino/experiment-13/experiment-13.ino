
/*
  experiment-12 - Formating data
  Shows how encode sensor data for transmission.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

char buffer[64];
#define LDR_PIN A0
#define TEMP_PIN A1
int ldr_value = 0;
int adc_value = 0;
float temp_value = 0;
char float_str[10];
char id[] = "node_id";

void setup() {
  Serial.begin(115200);
  //pinMode(LDR_PIN, INPUT);
  //pinMode(TEMP_PIN, INPUT);
}

void loop() {
  ldr_value = analogRead(LDR_PIN);
  delay(100);
  adc_value = analogRead(TEMP_PIN);
  temp_value = (adc_value * ( 5000 / 1024.0)) / 10;
  dtostrf(temp_value,2,2,float_str);
  sprintf(buffer, "%s,%d,%s", id, ldr_value, float_str);
  Serial.println(buffer);
  delay(2000);
}
