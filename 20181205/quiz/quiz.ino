int trig_pin = 2;
int echo_pin = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);
  long distance = duration / 58.2;
  
  int value = digitalRead(8);
  if (distance < 10 && distance >= 5) {
    if (value == HIGH) {
     digitalWrite(13, HIGH);
     Serial.println("press!");
    } else {
    digitalWrite(13, LOW);
    }
  }
  
  Serial.println(distance);
}
