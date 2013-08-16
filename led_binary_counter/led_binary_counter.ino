// This sketch uses four LEDs to count to visually
// count from 0 to 15. Each time a button is pushed
// the counter increases and displays the number in
// binary by lighting up the appropriate LED. Once the
// counter hits 16 it is reset to 0.

// Declare pins for the four LEDs and the button.
const byte ONE = 12;
const byte TWO = 10;
const byte FOUR = 8;
const byte EIGHT = 6;
const byte BUTTON = 2;

// Declare variables
byte counter = 0;  // Keep track of the number of button pushes.
byte bval = 0;  // Keep track of the previous value for the button.

// Setup our pins
void setup() {
  pinMode(ONE, OUTPUT);
  pinMode(TWO, OUTPUT);
  pinMode(FOUR, OUTPUT);
  pinMode(EIGHT, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// Read the button value and compare it to the previous value.
// The previous button value is stored in *old.
//
// Returns true if the button was pushed and false if not.
boolean read_button(const byte *button, byte *old) {
  boolean pushed = false;
  byte val = digitalRead(*button);

  if ((val == HIGH) and (*old == LOW)) {
    delay(10);
    pushed = true;
  }
  
  *old = val;
  return pushed;
}

// Use div and mod to determine which LEDs should be on and light
// them up.
void write_number(byte c) {
  digitalWrite(EIGHT, c / 8);
  c = c % 8;
  digitalWrite(FOUR, c / 4);
  c = c % 4;
  digitalWrite(TWO, c / 2);
  c = c % 2;
  digitalWrite(ONE, c);
}

// Run the main loop. Check for a button push. If the button is pushed
// update the counter. If the counter goes to 16 reset it to zero.
// Finally, display the value on the LEDs.
void loop() {
  boolean val = read_button(&BUTTON, &bval);
  if (val) { counter++; }
  counter = counter % 16;  // Roll the counter at 16.
  write_number(counter);
}
