/*
  experiment-14 - Network connection - several HTTP requests.
  Ethernet, IP, DNS.

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

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xAB, 0xCD, 0xEF, 0xAB, 0xCD, 0xEF };

EthernetClient client;
long elapsedTime = 1;

// CONSTANTS
char HOST[] = "rossano.pro.br";
String RESOURCE = "/arinter/data/serial";

void setup() {
  Serial.begin(115200);

  // initialize the Ethernet shield using DHCP:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("DHCP Failed");
    while(true) {
      delay(3000);
      Serial.println("Not working...");
    } 
  }
}

void loop() {
  if (client.available()) {
    char c = client.read();
    Serial.write(c);
  }
  if (elapsedTime-- <= 0) {
    request();
    elapsedTime = 100000; //around 10s
  }
}

void request() {
  client.stop();
  if(client.connect(HOST, 80)) {
    Serial.println("Connected.");
    client.println("GET " + RESOURCE + " HTTP/1.1");
    client.println("Host: " + String(HOST));
    client.println("Connection: close");
    client.println(); // end HTTP header
 }
}
