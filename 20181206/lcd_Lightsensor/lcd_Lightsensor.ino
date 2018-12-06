#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  lcd.begin();
  lcd.backlight();

  lcd.print("light value: ");
}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  Serial.println(light);

  lcd.setCursor(0, 1);
  lcd.print(light);

  delay(1000);
}
