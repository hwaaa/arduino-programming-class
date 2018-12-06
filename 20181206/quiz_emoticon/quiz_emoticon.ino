#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
// 좌: "(^o^) @ (^_-)"
// 우: "(-_^) @ (^o^)"
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("(^o^) @ (^_-)");
  //delay(500);
  delay(1000);
  lcd.home();
  lcd.clear();
  //lcd.setCursor(8, 0);
  lcd.print("(-_^) @ (^o^)");
  delay(1000);
  lcd.home();
  lcd.clear();
}
