
int sensorPin = A0; 
int onboardLED = 13;
int sensorValue = 0;
unsigned int batteryCapacity = 50000; 
unsigned int batteryLevel = 0;

// RGB LED PINS


int blue = 9;
int green = 10;
int red = 11;

double getBatteryPercentage() {
  return (((double)batteryLevel / (double)batteryCapacity)*100);
}

void RGB_color(int red_value, int green_value, int blue_value){
    analogWrite(red, red_value);
    analogWrite(green, green_value);
    analogWrite(blue, blue_value); 

}

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  batteryLevel += sensorValue; // adding sensor value to batter level 
  
  double percentage = getBatteryPercentage();
 
  if(percentage >= 100) {
    Serial.println("Battery Fully Charged");
    RGB_color (0, 125, 0); //GREEN  
    batteryLevel = batteryCapacity;
    percentage = 100;
  }
  
  else if (percentage <= 75 && percentage >50) {
    RGB_color(0, 125, 125); //BLUE 
  }

 else if (percentage <= 50 && percentage > 25) {
    RGB_color(125, 80, 0); //YELLOW
  }

 else if (percentage <= 25) {
    RGB_color(125, 0, 0);  //RED
  }

  Serial.print(percentage);
  Serial.println ("%");

  delay(100);
}
