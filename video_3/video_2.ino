int LED = 12;
int Switch1 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(Switch1, INPUT);
  
}

void loop() {
  if(digitalRead(Switch1) == 1) { 
    digitalWrite(LED, HIGH); //5V TO LED WHEN SWITCH ON   
  }
  else {
    digitalWrite(LED, LOW); //GROUND TO LED WHEN SWITCH OFF
  }
  }
