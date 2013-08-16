/*
Use PWM to control the brightness of an LED based on how
long a button is held down. The longer the button is
held down, the brighter the LED will get up to the
maximum brightness. Then the brightness level will be reset
to zero.
*/
const int LED = 9;
const int BUTTON = 7;

int val = 0;
int old = 0;
int state = 0;

int brightness = 128;
unsigned long startTime = 0;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop(){
  
  val = digitalRead(BUTTON);
  
  // Has the button been pushed
  if ((val == HIGH) && (old == LOW)) {
    state = 1 - state;
    startTime = millis();
    delay(10);
  }
  
  // If so, how long was it held down?
  if ((val == HIGH) && (old == HIGH)) {
    if (state == 1 && (millis() - startTime) > 500) {
      brightness++;
      delay(10);
      
      // Roll the brightness level back to zero if the
      // button is held down too long.
      if (brightness > 255) { brightness == 0; }
    }
  }
  
  old = val;
  
  // Turn on the LED to the appropriate brightness.
  if (state == 1) {
    analogWrite(LED, brightness);
  } else {
    analogWrite(LED, 0);
  }
}

