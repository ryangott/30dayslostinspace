
int sensorPin = A0; 
int onboardLED = 13;
int greenLED = 2;
int sensorValue = 0;
unsigned int batteryCapacity = 50000; 
unsigned int batteryLevel = 0;

void PrintBatteryPercentage() {
  Serial.print(((double)batteryLevel / (double)batteryCapacity)*100);
  Serial.println("%"); 
  pinMode (greenLED, OUTPUT);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(onboardLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  batteryLevel += sensorValue; // adding sensor value to batter level 
  if(batteryLevel >= batteryCapacity) {
    Serial.println("Battery Fully Charged");
    digitalWrite(greenLED, HIGH);
    batteryLevel = batteryCapacity;
  }
  else{
    PrintBatteryPercentage();
    digitalWrite(greenLED, LOW);
  }

  delay(50);
}
