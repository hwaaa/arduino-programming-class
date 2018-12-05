void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  int hertz = map(light, 0, 500, 31, 4978);
  tone(8, hertz, 100);
  delay(100);
  noTone(8);
  Serial.println(light);
  Serial.println(hertz);
  delay(200);
}
