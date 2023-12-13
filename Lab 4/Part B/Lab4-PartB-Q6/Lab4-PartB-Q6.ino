int buttons[2] = {10, 11};
int button1 = 10;
int button2 = 11;
int green = 7;
int leds[3] = {7, 6, 5};

int buttonState1 = 0;
int buttonState2 = 0;
int prevButtonState1 = 0;
int prevButtonState2 = 0;

int lowerBrightness = 255;
int raiseBrightness = 0;


void setup() {
  /*
  for(int i = 0; i < 3; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button, INPUT);
  */
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(green, OUTPUT);
  Serial.begin(9600);
}
// part of the solution was to do the code that was implemented for the first 
// question of part B
void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  // if buttons are pressed down raise or lower the brightness,
  // the code is the same one as used in part A of lab 3
  if(buttonState1 == HIGH)
  {
    lowerBrightness = 255;
    if(raiseBrightness > 255){
      raiseBrightness = 255;
    }
    analogWrite(green, raiseBrightness);

    raiseBrightness++;
  }

  if(buttonState2 == HIGH)
  {
    raiseBrightness = 0;
    if(lowerBrightness < 0){
      lowerBrightness = 0;
    }
    analogWrite(green, lowerBrightness);

    lowerBrightness--;
  }
  delay(30);
}
