/*
 Author: rossano at gmail dot com
*/


#include <SimpleDHT.h>  


#define PROGNAMEID "RUNNING PROGRAM: /home/rossano/Arduino/experiment-11/experiment-11.ino"


int DHT11PIN = 2;     
SimpleDHT11 dht11(DHT11PIN);   
byte temperature;    
byte humidity;        
int ldr_value;        

char temp_hum_lum[65];
char t[10];  
char h[10];  
char l[10]; 

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

  snprintf (temp_hum_lum, 45, "%d|%d|%d", (int)temperature, (int)humidity, ldr_value);
  Serial.print(msg_id++);
  Serial.print(": ");
  Serial.println(temp_hum_lum);

  delay(2000);
}
