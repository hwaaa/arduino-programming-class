int sound_pin = A0;
int yled_pin = 11;
int rled_pin = 10;
int gled_pin = 9;

int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(yled_pin, OUTPUT);
  pinMode(rled_pin, OUTPUT);
  pinMode(gled_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  int light_value = map(sound_value, 0, 1023, 0, 255);

  Serial.print("sound value : ");
  Serial.println(sound_value);

  Serial.print("light value : ");
  Serial.println(light_value);

  if (sound_value == 1023) {
    cnt++;
  }
  Serial.println(cnt);
  if (cnt >= 0 && cnt < 5) {
      analogWrite(gled_pin, light_value);
    } else if (cnt >= 5 && cnt < 10) {
      analogWrite(yled_pin, light_value);
    } else if (cnt >= 10 && cnt < 20) {
      analogWrite(rled_pin, light_value);
    }
  
  delay(200);
}
