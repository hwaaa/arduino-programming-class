int led_pin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  int hertz = map(light, 0, 500, 31, 4978);
}
