#include <Wire.h>                
#include <LiquidCrystal_I2C.h>  
LiquidCrystal_I2C lcd(0x3F, 16, 2); 

int sound_pin = A0;
int next = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("(^^)");
}

void loop() {
  // put your main code here, to run repeatedly:

  int sound_value = analogRead(sound_pin);
  int light_value = map(sound_value, 0, 1023, 0, 255);

  Serial.print("sound value : ");
  Serial.println(sound_value);

  Serial.print("light value : ");
  Serial.println(light_value);

  if (sound_value >= 50) {
    lcd.clear();
    next++;
    lcd.setCursor(next,0);
    lcd.print("(^^)");
  }
  delay(200);
}
