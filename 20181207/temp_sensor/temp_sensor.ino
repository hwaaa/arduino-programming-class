#include <dht11.h>
int DHT11PIN = A0;
dht11 DHT11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT11.read(DHT11PIN);

  Serial.print("Temp: ");
  Serial.print((float)DHT11.temperature);
  Serial.print(" C ");

  Serial.print("/ RelF: ");
  Serial.print((float)DHT11.humidity);
  Serial.print(" % ");

  Serial.println();
  delay(2000);
}
