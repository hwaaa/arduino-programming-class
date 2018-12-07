#include <dht11.h>
#include <Wire.h>                
#include <LiquidCrystal_I2C.h>  

int DHT11PIN = A0;
dht11 DHT11;
LiquidCrystal_I2C lcd(0x3F, 16, 2); 

float temp = DHT11.temperature;
float humid = DHT11.humidity;
float unpleasant = 9/5*temp-0.55*(1-humid)*(9/5*temp)+32;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  
  int chk = DHT11.read(DHT11PIN);
  
  lcd.print((float)DHT11.temperature);
  lcd.print("/");

  lcd.print((float)DHT11.humidity);
  lcd.print("/");

  lcd.print(unpleasant);
  
}


void loop() {
  // put your main code here, to run repeatedly:

  Serial.print("Temp: ");
  Serial.print((float)DHT11.temperature);
  Serial.print(" C ");

  Serial.print("/ RelF: ");
  Serial.print((float)DHT11.humidity);
  Serial.print(" % ");

  Serial.println();
  delay(2000);
}
