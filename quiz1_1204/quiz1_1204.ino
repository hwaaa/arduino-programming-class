int a;
int b;
int c;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(4, INPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(7);
  b = digitalRead(4);
  c = digitalRead(2);
  
  if(a == HIGH) {
    digitalWrite(13, 255);
    delay(100);
    Serial.println("a 누름");
  } 
    
  if(b == HIGH) {
    digitalWrite(12, 255);
    delay(100);
  } 
  
  if(c == HIGH) {
    digitalWrite(8, 255);
    delay(100);
  } 
}
