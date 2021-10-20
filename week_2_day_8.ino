int blue = 9;
int green = 10;
int red = 11;

void RGB_color(int red_value, int green_value, int blue_value){
    analogWrite(red, red_value);
    analogWrite(green, green_value);
    analogWrite(blue, blue_value); 
    delay(500);
}

void setup() {
  // put your setup code here, to run once:
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  pinMode (red, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  RGB_color(125, 0, 0); //RED
  RGB_color(0, 125, 0); //GREEN
  RGB_color(0, 0, 125); // BLUE
  RGB_color(0, 125, 125); // YELLOW
  RGB_color(125, 0, 125); // PURPLE
  RGB_color(125, 125, 125); // WHITE
}
