void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(13, OUTPUT);
  //pinMode(12, OUTPUT);
  //pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<=255; i+=10) {
    analogWrite(11, i);
    delay(100);
    Serial.println(i);
  }
  for(int i = 250; i >= 0; i-=10) {
    analogWrite(11, i);
    delay(100);
    Serial.println(i);
  }
  
  for(int i=0; i<=255; i+=10) {
    analogWrite(9, i);
    delay(100);
  }
  for(int i = 250; i >= 0; i-=10) {
    analogWrite(9, i);
    delay(100);
  }

  for(int i=0; i<=255; i+=10) {
    analogWrite(5, i);
    delay(100);
  }
  for(int i = 250; i >= 0; i-=10) {
    analogWrite(5, i);
    delay(100);
  }
}
