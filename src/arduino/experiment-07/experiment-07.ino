
/*
  experiment-07 SERIAL READ
  Turns an LED ON/OFF with a serial input.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

#define LED 13
char input = '0';
char state = '0';

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  while (!Serial);
  Serial.println("0 - Turns LED OFF");
  Serial.println("1 - Turns LED ON");
  Serial.println("2 - Blink");
  Serial.println("3 - SOS (morse code)");
}

void loop() {
 //Serial.print("state == ");
 //Serial.println(state);
 if (Serial.available() > 0) {
    input = Serial.read();
    switch(input) {
      case '0':
      case '1':
      case '2':
      case '3':
      state = input;
      break;
    }
 }
 if (state == '0')
     digitalWrite(LED, LOW);
 else if (state == '1')
        digitalWrite(LED, HIGH);
 else if (state == '2') {
        digitalWrite(LED, HIGH);
        delay(500);
        digitalWrite(LED, LOW);
        delay(500);
 } else if (state == '3') {
        // . . . 
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200);
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200); 
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200);
        // - - -
        digitalWrite(LED, HIGH);
        delay(600);
        digitalWrite(LED, LOW);
        delay(200);
        digitalWrite(LED, HIGH);
        delay(600);
        digitalWrite(LED, LOW);
        delay(200); 
        digitalWrite(LED, HIGH);
        delay(600);
        digitalWrite(LED, LOW);
        delay(200);
        // . . . 
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200);
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(200); 
        digitalWrite(LED, HIGH);
        delay(200);
        digitalWrite(LED, LOW);
        delay(1000);
 }
 
}
 
