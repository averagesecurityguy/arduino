const int LED = 9;
const int SENSOR = 0;

int sval = 0;
int lval = 0;
char sbuffer[128];
char lbuffer[128];

void setup(){
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
  sval = analogRead(SENSOR);
  lval = 255 - (sval/4);
  
  sprintf(sbuffer, "SVal: %i\n", sval);
  sprintf(lbuffer, "LVal: %i\n", lval);  
  Serial.print(sbuffer);
  Serial.print(lbuffer);
  analogWrite(LED, lval);
  delay(10);
}

