
/*
  experiment-04 (PUSH BUTTONS + LED)
  Turns an LED ON/OFF with a PUSH BUTTON.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

#define LED 13
#define BUTTON 2
int button_state = 0;
int led_state = LOW;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  button_state = digitalRead(BUTTON);
  if (button_state == HIGH) {
    led_state = ~led_state;
    digitalWrite(LED, led_state);
  }
}
