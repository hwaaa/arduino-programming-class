#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

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
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" angleZ : ");
  Serial.print(mpu6050.getAngleZ());
  Serial.println();
}
