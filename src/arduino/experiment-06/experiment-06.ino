
/*
  experiment-06 (INTERRUPTS)
  Turns an LED ON/OFF with a PUSH BUTTON + ISR + DEBOUNCING CODE.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

#define LED 13
#define INTERRUPT_PIN 2
volatile int led_state = LOW;
volatile long isr_entry_time = 0;
volatile long last_execution = 0;
volatile long elapsed = 100;


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(INTERRUPT_PIN, INPUT_PULLUP);
  // INT VECTOR ENTRY, ISR, MODE
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), 
                  toggle,
                  LOW);
}

void loop() {
}

void toggle() {
    isr_entry_time = millis();
    if (elapsed >= 5) { 
       led_state = ~led_state;
       last_execution = millis();
       digitalWrite(LED, led_state);
    }
    elapsed = isr_entry_time - last_execution;
}
 
