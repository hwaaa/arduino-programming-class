#include <Servo.h>
Servo myservo;

int pin_sensor = 3;
int pin_alcohol = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_sensor, INPUT);
  myservo.attach(12);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reedSW = digitalRead(pin_sensor);
  int alcohol = analogRead(pin_alcohol);
  int result = map(alcohol, 0, 1023, 0, 255);

  
  Serial.println("~~~~~~~~~~~~~~~~");
  Serial.print("alcohol: ");
  Serial.println(result);
  Serial.print("raw data: ");
  Serial.println(alcohol);
  
  if(reedSW == LOW) {
    myservo.write(90);
    delay(15);

    // 사용자가 음주했나?
    if(alcohol <= 300) {  // 음주 no
      // 박스 연다
      myservo.write(0);
      Serial.println("UNLOCK");
      delay(15);
    } else {  // 음주 yes
      // 박스 열지 않는다
      myservo.write(90);
      Serial.println("LOCK");
    }
    
  } else {
    myservo.write(0);
    delay(15);
  }
  Serial.print("reed: ");
  Serial.println(reedSW);
  delay(1000);
}
