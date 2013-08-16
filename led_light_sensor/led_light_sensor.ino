/*
Use a light sensor to control the brightness of an LED.
The darker the room, the brighter the LED. There has to
be a minimum level of darkness before the LED will come
on.
*/
const int LED = 9;
const int SENSOR = 0;

int sval = 0;  // SENSOR value
int lval = 0;  // LED value

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  
  sval = analogRead(SENSOR);
  
  /*
  The light sensor gives values between 0 and 1023 but the LED
  needs a value between 0 and 255. Also, the light sensor sends
  a lower value when there is less light. To give the LED a
  higher value when there is less light we need to subtract from
  255.
  */ 
  lval = 255 - sval/4;

  // Don't turn on the LED unless there is a certain level of 
  // darkness.
  if (lval < 128) {
    analogWrite(LED, 0);
  } else {
    analogWrite(LED, lval);
  }
  
  delay(100);
}

