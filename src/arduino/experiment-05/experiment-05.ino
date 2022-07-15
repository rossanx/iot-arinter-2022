
/*
  experiment-05 (PUSH BUTTONS + LED)
  LED mimics a PUSH BUTTON.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

#define LED 13
#define BUTTON 2
int button_state = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  button_state = digitalRead(BUTTON);
  if (button_state == HIGH) {
    digitalWrite(LED, HIGH);
  } else
    digitalWrite(LED, LOW);
}
