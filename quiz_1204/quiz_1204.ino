void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(300);
  
  digitalWrite(12, HIGH);
  delay(300);
  
  digitalWrite(8, HIGH);
  delay(300);
}
