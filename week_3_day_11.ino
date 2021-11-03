#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS =4;

char buttons[ROWS][COLS] ={
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},  
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};


Keypad customKeypad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  char customKey = customKeypad.getKey();

  if(customKey) {
    Serial.println(customKey);
  }
}
