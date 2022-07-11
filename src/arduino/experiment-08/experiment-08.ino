
/*
  experiment-08 LED binary counter
  Turns LED ON/OFF representig a binary number

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 8
#define LED8 9

int counter=0;
int permanent_counter=0;
int pin=0;
boolean s=0;

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);  
}

void loop() {
  counter = permanent_counter++;
  for (pin=2; pin<=9; pin++) {
    s = counter & 128;
    digitalWrite(pin,s);
    counter=counter<<1;
    Serial.print(s);
    delay(50);
  }
  Serial.print(" - ");
  Serial.println(permanent_counter-1);
  if (permanent_counter == 256)
    permanent_counter=0; 
}
