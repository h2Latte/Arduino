
int myPins[] = {44, 46, 47, 48, 49, 50, 51};

void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < 7; i = i + 1) {
    pinMode(myPins[i], OUTPUT);
    digitalWrite(myPins[i], LOW);
  }
   
}

void loop() {
  setTo1();
  delay(1000);
  setTo2();
  delay(1000);
  setTo3();
  delay(1000);
}


void setTo1() {
   digitalWrite(44, LOW);
   digitalWrite(46, LOW);
   digitalWrite(47, HIGH);
   digitalWrite(48, LOW);
   digitalWrite(49, HIGH);
   digitalWrite(50, LOW);
   digitalWrite(51, LOW);
   }

 void setTo2() {
   digitalWrite(44, HIGH);
   digitalWrite(46, HIGH);
   digitalWrite(47, LOW);
   digitalWrite(48, HIGH);
   digitalWrite(49, HIGH);
   digitalWrite(50, LOW);
   digitalWrite(51, HIGH);
   }


    void setTo3() {
   digitalWrite(44, HIGH);
   digitalWrite(46, LOW);
   digitalWrite(47, HIGH);
   digitalWrite(48, HIGH);
   digitalWrite(49, HIGH);
   digitalWrite(50, LOW);
   digitalWrite(51, HIGH);
   }
