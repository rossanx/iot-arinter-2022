
/*
  experiment-09 LDR
  Turns LED ON/OFF according to light

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

#define LDR_PIN A0
#define LED 13
int ldr_value = 0;
int state = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  ldr_value = analogRead(LDR_PIN);
  Serial.println(ldr_value);
  if (ldr_value >= 500 && state == 0) {
     Serial.println("Too dark, turn on light...");
     digitalWrite(LED, HIGH);
     state = 1;
  } else if (ldr_value <500 && state == 1) {
     Serial.println("That's not dark, turn off light...");
     digitalWrite(LED, LOW);
     state = 0;
  }
  delay(1000);
}
