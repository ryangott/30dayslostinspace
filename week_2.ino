
int sensorPin = A0; 
int onboardLED = 13;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(onboardLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);

  digitalWrite(onboardLED, HIGH);
  delay(sensorValue);
  digitalWrite(onboardLED, LOW);
  delay(sensorValue);
  Serial.println(sensorValue);

}
