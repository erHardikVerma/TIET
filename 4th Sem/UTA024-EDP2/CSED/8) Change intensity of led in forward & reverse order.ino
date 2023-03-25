// Define the 5 pins for the LEDs
const int led1 = 1;
const int led2 = 2;
const int led3 = 3;
const int led4 = 4;
const int led5 = 5;

void setup() {
  // Set the 5 pins as output pins
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  // Set all pins low
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
}

void loop() {
  // Forward sequence
  analogWrite(led1, 150);
 
  analogWrite(led2, 250);
  analogWrite(led3, 100);
  analogWrite(led4, 50);
  analogWrite(led5, 200);
// Reverse sequence
  analogWrite(led5, 4);
  delay(1000);
  analogWrite(led4, 1);
  delay(1000);
  analogWrite(led3, 2);
  delay(1000);
  analogWrite(led2, 5);
  delay(1000);
  analogWrite(led1, 3);
  delay(1000);
}
