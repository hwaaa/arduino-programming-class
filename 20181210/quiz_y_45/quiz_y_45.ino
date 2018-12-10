#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
int y_angle = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  mpu6050.update();
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.println();

  y_angle = mpu6050.getAngleY();
  
  if(y_angle > 45) {
    tone(8, 262, 250);
  } else if (y_angle < -45) {
    tone(8, 262, 250);
  } else {
    noTone(8);
  }
  delay(1000);
}
