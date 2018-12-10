#include <dht11.h>
#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
int DHT11PIN = 4;
dht11 DHT11; 
int blueTx=2;   
int blueRx=3;   
SoftwareSerial bluetooth(blueTx, blueRx);  //시리얼 통신을 위한 객체선언


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //시리얼모니터
  bluetooth.begin(9600); //블루투스 시리얼
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT11.read(DHT11PIN);

  char val = bluetooth.read();
  if(bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  
  if(val == 'temperation') {
    Serial.print("Temp: ");
    Serial.print((float)DHT11.temperature);
    Serial.print(" C ");
    bluetooth.write(Serial.read());
  }

  if(val == 'humidity') {
    Serial.print("/ RelF: ");
    Serial.print((float)DHT11.humidity);
    Serial.print(" % ");
    bluetooth.write(Serial.read());
  }
  
  Serial.println();
  delay(2000);
}
