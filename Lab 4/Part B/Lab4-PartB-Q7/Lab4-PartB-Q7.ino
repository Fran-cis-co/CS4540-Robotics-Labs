int buttons[3] = {13, 12, 11};
int leds[5] = {7, 6, 5, 4, 3};
int buttonStates[3] = {0, 0, 0};
int previousStates[3] = {0, 0, 0};
int direction = 0; // if 0 then left, else 1 is right
int wait = 1000; // default delay value
// used a value for a delay and depending on the button press, this value will go up or down or reset

int prevButtonState = LOW;

void setup() {
  for(int i = 0; i < 3; i++)
  {
    pinMode(buttons[i], INPUT);
  }
  for(int i = 0; i < 5; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  buttonStates[0] = digitalRead(buttons[0]);
  buttonStates[1] = digitalRead(buttons[1]);
  buttonStates[2] = digitalRead(buttons[2]);

  // depending on the button held, it will speed up and change the direction or reset the speed
  if(buttonStates[0] == HIGH)
  {
    wait -= 300;
    direction = 0;
    Serial.print(wait);
  }
  if(buttonStates[1] == HIGH)
  {
    wait -= 300;
    direction = 1;
    Serial.print(wait);
  }
  if(buttonStates[2] == HIGH)
  {
    wait = 1000;
    Serial.print(wait);
  }


  if(wait < 150)
  {
    wait = 150;
  }


  // if the direction is 0 the leds will go to the left
  // if 1 the leds will go right, depending on the point of view you are looking at them
  if(direction == 0)
  {
    for(int i = 0; i < 5; i++)
      {
        digitalWrite(leds[i], HIGH);
        delay(wait);
        digitalWrite(leds[i], LOW);
        delay(wait);
      }
  } else if (direction == 1)
  {
      for(int i = 4; i >= 0; i--)
      {
        digitalWrite(leds[i], HIGH);
        delay(wait);
        digitalWrite(leds[i], LOW);
        delay(wait);
      }
  }
}
