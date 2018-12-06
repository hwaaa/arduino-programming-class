#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

int trig_pin = 2;
int echo_pin = 3;
int btn1 = digitalRead(12);
int btn2 = digitalRead(13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.home();
  if (btn1 == HIGH) {
    lcd.print("distance value : ");
    lcd.setCursor(0, 1);
    lcd.print(getDistance(trig_pin, echo_pin));
  } else if (btn2 == HIGH) {
    lcd.print("Light : ");
    lcd.setCursor(0, 1);
    lcd.print(analogRead(A0));
  } else {
    lcd.print("select button");
  }
  
}

int getDistance(int aTrig_pin, int aEcho_pin) {
  digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);
  long duration = pulseIn(aEcho_pin, HIGH); 
  long distance = duration / 58.2;
  Serial.println(distance);
  delay(100);

  return distance;
}
