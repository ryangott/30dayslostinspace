int LED = 10; //RED
int LED2 = 11; //YELLOW
int LED3 = 12; //GREEN
int Switch1 = 2;
int Switch2 = 3;
int Switch3 = 4;


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);  
  pinMode(Switch1, INPUT);
  pinMode(Switch2, INPUT);
  pinMode(Switch3, INPUT);
  
}

void loop() {
  //SWITCH/LED 1 ON/OFF
  if(digitalRead(Switch1) == 1) { 
    digitalWrite(LED, HIGH); //5V TO LED WHEN SWITCH ON   
  }
  else {
    digitalWrite(LED, LOW); //GROUND TO LED WHEN SWITCH OFF
  }
   //SWITCH/LED 2 ON/OFF
  if(digitalRead(Switch2) == 1) { 
    digitalWrite(LED2, HIGH); //5V TO YELLOW LED2 WHEN SWITCH ON   
  }
  else {
    digitalWrite(LED2, LOW); //GROUND TO YELLOW LED2 WHEN SWITCH OFF
  }
   //SWITCH/LED 3 ON/OFF
  if(digitalRead(Switch3) == 1) { 
    digitalWrite(LED3, HIGH); //5V TO GREEN LED3 WHEN SWITCH ON   
  }
  else {
    digitalWrite(LED3, LOW); //GROUND TO GREEN LED3 WHEN SWITCH OFF
  }
  }
