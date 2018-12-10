#include <SoftwareSerial.h>   // 시리얼통신 라이브러리 호출
#include <Wire.h>                
#include <LiquidCrystal_I2C.h>  
LiquidCrystal_I2C lcd(0x3F, 16, 2); 
SoftwareSerial bluetooth(2, 3);  // 아두이노의 3번 TX, 2번 RX

int next = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("(^^)");
}

void loop() {
  // put your main code here, to run repeatedly:
  char val = bluetooth.read();
  if(bluetooth.available()) {
    Serial.write(bluetooth.read());
  }
  if (val == 'r') {
    lcd.clear();
    next++;
    lcd.setCursor(next,0);
    lcd.print("(^^)");
  }
  if (val == 'l') {
    lcd.clear();
    next--;
    lcd.setCursor(next,0);
    lcd.print("(^^)");
  }
  delay(200);
}
