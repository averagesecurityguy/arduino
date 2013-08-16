/*
Use PWM to make an LED get brighter then get dimmer.
*/
const int LED = 9;
const int SENSOR = 0;

int val = 0;

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  
  val = analogRead(SENSOR);
  
  for (int i = 0; i < 255; i++) {
    analogWrite(LED, i);
    delay(10);
  }
  
  for (int i = 255; i > 0; i--) {
    analogWrite(LED, i);
    delay(10);
  }
}

