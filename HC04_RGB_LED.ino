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

  if (cm < 10) {
    analogWrite(FRSled, 225);
    analogWrite(SCDled, 0);
    analogWrite(TRDled, 0);
    Serial.println("HIGH");
  }
  
  else if (cm > 10 && cm < 20) {
    analogWrite(FRSled, 0);
    analogWrite(SCDled, 225);
    analogWrite(TRDled, 0);
    Serial.println("HIGH2");
  }

  else if (cm > 20 && cm < 30) {
    analogWrite(FRSled, 0);
    analogWrite(SCDled, 0);
    analogWrite(TRDled, 225);
    Serial.println("HIGH3");
  }


  else  {
    digitalWrite(FRSled, 0);
    digitalWrite(SCDled, 0);
    digitalWrite(TRDled, 0);
    Serial.println("LOWAF");
  }

}
