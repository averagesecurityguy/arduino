const int LED = 9;
const int SENSOR = 0;

int sval = 0;  // SENSOR value
int lval = 0;  // LED value

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  
  sval = analogRead(SENSOR);
  lval = 255 - sval/4;

  if (lval < 128) {
    analogWrite(LED, 0);
  } else {
    analogWrite(LED, lval);
  }
  
  delay(100);
}

