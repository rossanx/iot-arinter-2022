
/*
  experiment-03 (Code Organization / functions)
  Shows how to use functions.

  Rossano Pablo Pinto - rossano at gmail dot com

  Example code for the Short Term Course IoT: From data collection to data presentation
  FATEC Americana - ARInter - CPS - July/2022
*/

void setup() {
  Serial.begin(9600);
  char buffer[32];
  sprintf(buffer, "Method 0: 10 + 10 = %d", calculate(10, 10, '+'));
  Serial.println(buffer);
  my_print_fmt(10, 10, calculate(10, 10, '+'), '+');
}

void loop() {
}


int calculate(int x, int y, byte operation)
{
  switch(operation) {
    case '+': return x + y; break;
    case '-': return x - y; break;
    case '*': return x * y; break;
    case '/': if (y != 0) return x / y; break;
    default:
      perror("Operation not allowed");
  }
}


void my_print_fmt(int a, int b, int result, byte operation) {
  // Method 1
  Serial.print("Method 1: ");
  Serial.print(a);
  Serial.print(" ");
  Serial.print((char)operation);
  Serial.print(" ");
  Serial.print(b);
  Serial.print(" = ");
  Serial.println(result);
  // Method 2
  Serial.print("Method 2: ");
  Serial.println((String) a + " " + (char)operation + " " + b + " = " + result);
}
