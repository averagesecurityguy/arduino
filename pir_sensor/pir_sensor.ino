/*
Use a PIR sensor, motion detector, to turn on an LED.
*/

// Declare constants
const int PIR = 12;
const int LED = 2;

// Setup our pins
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PIR, INPUT);
}


// Run this thing.
void loop() {
  if (digitalRead(PIR) == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
