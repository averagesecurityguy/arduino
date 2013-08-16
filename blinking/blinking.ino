// Blink an LED on and off every second. This is basically
// the Hello World of Arduino.
void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(10, HIGH); // Turn on LED
  delay(1000);            // Wait 1000 miliseconds
  digitalWrite(10, LOW);  // Turn of LED
  delay(1000);            // Wait 1000 miliseconds
}
