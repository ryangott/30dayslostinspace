int LED = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH); // 5V
}

void loop() {
  digitalWrite(LED, LOW); // GROUND
  delay(1000);
  digitalWrite(LED, HIGH); // 5v
  delay(1000);
  
  // put your main code here, to run repeatedly:

}
