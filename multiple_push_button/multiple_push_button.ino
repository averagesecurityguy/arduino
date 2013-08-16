// Declare constants
const int RLED = 4;
const int RBUTTON = 8;
const int GLED = 2;
const int GBUTTON = 6;

// Declare variables
int rval = LOW;  // Red button value
int rstate = 0;  // Red button state
int gval = LOW;  // Green button value
int gstate = 0;  // Green button state

// Setup our pins
void setup() {
  pinMode(RLED, OUTPUT);
  pinMode(RBUTTON, INPUT);
  pinMode(GLED, OUTPUT);
  pinMode(GBUTTON, INPUT);
}


// Read the button value and compare it to the previous value.
// The previous value is stored in the bstate variable.
void read_button(const int *button, int *old, int *bstate) {
  int val = digitalRead(*button);

  // If the button is pushed then swap the state.
  if ((val == HIGH) and (*old == LOW)) {
    *bstate = 1 - *bstate;
    delay(20);
  }
  
  *old = val;
}


// Toggle the LED on or off based on the button state.
void toggle_led(const int *led, int *bstate) {
  if (*bstate == 1) {
    digitalWrite(*led, HIGH);
  } else {
    digitalWrite(*led, LOW);
  }
}


// Run this thing.
void loop() {
  read_button(&RBUTTON, &rval, &rstate);
  toggle_led(&RLED, &rstate);
  read_button(&GBUTTON, &gval, &gstate);
  toggle_led(&GLED, &gstate);
}
