int ledPin = 9; // LED connected to digital pin 9
int ledBrightness = 0; // variable to store the value read from the user input

void setup() {
  pinMode(ledPin, OUTPUT); // set the LED pin as an output
  Serial.begin(9600); // set the baud rate for serial communication
}

void loop() {
 { // check if data is available
    ledBrightness = Serial.parseInt(); // read the value from the user input
    ledBrightness = constrain(ledBrightness, 0, 255); // constrain the value between 0 and 255
    analogWrite(ledPin, ledBrightness); // set the LED brightness to the user input value
  }
}
serial input
