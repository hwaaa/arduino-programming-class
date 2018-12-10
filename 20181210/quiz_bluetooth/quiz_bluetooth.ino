#include <SoftwareSerial.h>   // 시리얼통신 라이브러리 호출
#include <Servo.h>    // 서보모터 라이브러리

Servo myservo;
SoftwareSerial bluetooth(2, 3);  // 아두이노의 3번 TX, 2번 RX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  myservo.attach(11);
  myservo.write(0);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char val = bluetooth.read();
  if(bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if(val == 'a') {
    myservo.write(120);
    delay(15);
  }
  
}
