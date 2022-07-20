/*
  experiment-11 Temperature / Humidity / Luminosity
  Reads ambient temperature/humidity/luminosity
  Shows how to encode sensor data for transmission.
  
  Sensors:
    DHT11
    LDR

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/


#include <SimpleDHT.h>  


#define PROGNAMEID "RUNNING PROGRAM: ~/Arduino/experiment-11/experiment-11.ino"


int DHT11PIN = 4; 
SimpleDHT11 dht11(DHT11PIN);   
byte temperature;    
byte humidity;        
int ldr_value;        

char msg[65];

int msg_id = 0;

void setup() {
  Serial.begin(115200);
   /* PRINT PROGRAM NAME AT SERIAL PORT*/
  Serial.println(PROGNAMEID);
}

void loop() {
  dht11.read(&temperature, &humidity, NULL);
  delay(500);
  ldr_value = analogRead(A0);

  snprintf(msg, 45, "%d|%d|%d", (int)temperature, (int)humidity, ldr_value);
  Serial.print(msg_id++);
  Serial.print(": ");
  Serial.println(msg);

  delay(2000);
}
