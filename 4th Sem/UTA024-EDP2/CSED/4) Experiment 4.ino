// Define the pin number for the LED
const int ledPin = 9;

void setup() {
  // Set the pin mode for the LED pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Use a for loop to increase the brightness from 0 to 255
  for (int i = 0; i <= 255; i++) {
    // Use the analogWrite function to set the brightness of the LED
    analogWrite(ledPin, i);
    // Delay for a small amount of time
    delay(10);
  }
  
  // Use a for loop to decrease the brightness from 255 to 0
  for (int i = 255; i >= 0; i--) {
    // Use the analogWrite function to set the brightness of the LED
    analogWrite(ledPin, i);
    // Delay for a small amount of time
    delay(10);
  }
}
