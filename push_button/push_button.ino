// Declare constants
const int LED = 13;
const int BUTTON = 7;
const int ON = 1;
const int OFF = 0;

// Declare variables
int bval = LOW;
int bstate = 1;

// Setup our pins
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

// Read the button value and compare it to the previous value.
// The previous value is stored in a global variable bval.
void read_button(const int *button, int *old, int *bstate) {
  int val = digitalRead(*button);

  // If the button is pushed then swap the state.
  if ((val == HIGH) and (*old == LOW)) {
    *bstate = 1 - *bstate;
    delay (50);
  }
  
  *old = val;
}

// Run this thing.
void loop() {
  read_button(&BUTTON, &bval, &bstate);
  
  if (bstate == ON) { 
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
