/*
 * Authors: Rossano Pablo Pinto
 *          José Luís Zem
 */
 
#include <SPI.h>
#include <UIPEthernet.h> /* In order to work with Proteus you need to use
                            this header instead of the usual Ethernet.h */
#include <PubSubClient.h>

/* 
 * Include the necessary headers for any 
 * sensor you are using.
 */

// MAC
byte mac[] = { 0xAB, 0xCD, 0xEF, 0x01, 0x02, 0x03 };
// MQTT Broker
const char* broker = "broker.hivemq.com";

EthernetClient ethernet;
PubSubClient client(ethernet);

long lastMsg = 0;

void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.print("Incoming message [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void setup()
{
  Serial.begin(9600);
  Ethernet.begin(mac);

  Serial.print("My IP Address: ");
  Serial.println(Ethernet.localIP());
  Serial.println();

  delay(4000);
  
  client.setServer(broker, 1883);   
  client.setCallback(callback);
}

void reconnect() {

  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ARInter-IoT-Instructor")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop(); 

  // REPLACE THIS WITH AN ACTUAL SENSOR READING
  //...sensor_value = "27.5";
    
  Serial.println("Publish message: ");
  Serial.println(/*sensor_value*/ "27.5");

  client.publish("arinter/americana/rossano/arduino/t",
		 /*sensor_value*/ "27.5");

  delay(5000);
}
