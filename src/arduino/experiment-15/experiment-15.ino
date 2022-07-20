/*
  experiment-15 - Writes data to ThingSpeak.
  Using fake sensor.

  Hardware:
     Ethernet w5500
        P3 - 18 PB4/12
        P5 - 17 PB3/~11
        P6 -  1 PC6/RST
        P7 - 16 PB2/~10
        P8 - NC
        P9 - PB5/13
 
  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
 
 */

//#include <SPI.h>
#include <Ethernet.h>
#include "secrets.h"
#include "ThingSpeak.h" // Always include last

byte mac[] = { 0xAB, 0xCD, 0xEF, 0xAB, 0xCD, 0xEF };

EthernetClient client;
long elapsedTime = 1;

// CONSTANTS DEFINED AT secrets.h
unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

int sensor_value = 0;

void setup() {
  Serial.begin(115200);

  // Use DHCP to configure network
  if (Ethernet.begin(mac) == 0) {
    Serial.println("DHCP Failed");
    while(true) {
      delay(3000);
      Serial.println("Not working...");
    } 
  }
  delay(1000);

  // initialize random number generator (used to generate fake sensor values)
  randomSeed(analogRead(0));
  // initialize 
  ThingSpeak.begin(client);
  
}

void loop() {
  sensor_value = random(20, 25);

  int ret = ThingSpeak.writeField(myChannelNumber, 1, sensor_value, myWriteAPIKey);
  if (ret == 200)
    Serial.println("Channel update successful with value " + String(sensor_value));
  else 
    Serial.println("Error. HTTP error code "+ String(ret));

  delay(25000); // wait 25 seconds for the next channel update
  
}
