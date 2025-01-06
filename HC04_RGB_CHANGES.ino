const int EchoPin = 8; //feel the back-wave from the trig 
const int TrigPin = 7; //trigers the chip to work
const int FRSled = 9;
const int SCDled = 11;
const int TRDled = 12;

long microsecondsToCentimeters(long microseconds) {
  return microseconds/29/2;
}



void setup() {
  Serial.begin(9600);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop() {
  long duration, cm;
 


  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

  
  Serial.print("cm:");
  Serial.print(cm);
  Serial.println();
  delay(100);

  if (cm > 40 || cm < 2) {
    cm = 0;
    int light = 0;
  }
  int light = map(cm, 2, 37, 225, 0);
  analogWrite(FRSled, light);
  analogWrite(SCDled, light);
  analogWrite(TRDled, light);
  Serial.println(light);




}
