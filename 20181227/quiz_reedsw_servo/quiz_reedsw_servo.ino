#include <Servo.h>
Servo myservo;

int pin_sensor = 3;
int pin_led = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_sensor, INPUT);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reedSW = digitalRead(pin_sensor);
  if(reedSW == LOW) {
    digitalWrite(pin_led, HIGH);
    myservo.write(90);
    delay(15);
  } else {
    digitalWrite(pin_led, LOW);
    myservo.write(0);
    delay(15);
  }
  Serial.print("reed: ");
  Serial.println(reedSW);
  delay(1000);
}
