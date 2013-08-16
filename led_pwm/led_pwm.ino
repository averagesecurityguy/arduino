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
  
  if ((val == HIGH) && (old == LOW)) {
    state = 1 - state;
    startTime = millis();
    delay(10);
  }
  
  if ((val == HIGH) && (old == HIGH)) {
    if (state == 1 && (millis() - startTime) > 500) {
      brightness++;
      delay(10);
      
      if (brightness > 255) { brightness == 0; }
    }
  }
  
  old = val;
  
  if (state == 1) {
    analogWrite(LED, brightness);
  } else {
    analogWrite(LED, 0);
  }
}

