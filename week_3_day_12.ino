#include <Key.h>
#include <Keypad.h>

int buzzer = 10;

const byte ROWS = 4;
const byte COLS = 4;

char buttons[ROWS][COLS] ={
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},  
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

int tones[ROWS][COLS] = {
    {31, 93, 147, 208},
    {247, 311, 370, 440},
    {523, 587, 698, 880},
    {1397, 2637, 3729, 4978}
};


Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, 4, 4);


void setup() {
  pinMode(buzzer, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int toneFreq = 0; 
  
  char customKey = customKeypad.getKey();

  if(customKey) {
    Serial.println(customKey);
    Serial.print(": ");
    for (byte j=0; j<ROWS; j++) {
        for (byte i=0; i< COLS; i++) {
           if (customKey == buttons[j][i]) {
              toneFreq=tones[j][i];
              break;
           }
        }
    }

      tone(buzzer, toneFreq, 500);
      delay(500);
      noTone(buzzer);
  }
}
