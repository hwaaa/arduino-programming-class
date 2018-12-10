#include <SoftwareSerial.h>   // 시리얼통신 라이브러리 호출

int blueTx = 2;
int blueRx = 3;
SoftwareSerial mySerial(blueTx, blueRx);  // 시리얼 통신을 위한 객체 선언

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // 시리얼모니터
  mySerial.begin(9600);  // 블루투스 시리얼
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()) {
    Serial.write(mySerial.read());  // 블루투스측 내용을 시리얼모니터에 출력
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());  // 시리얼모니터 내용을 블루투스측에 write
  }
}