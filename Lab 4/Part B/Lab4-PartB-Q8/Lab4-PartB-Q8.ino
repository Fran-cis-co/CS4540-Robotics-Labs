int buttons[3] = {13, 12, 11};
int leds[5] = {7, 6, 5, 4, 3};
int buttonStates[3] = {0, 0, 0};
int previousStates[3] = {0, 0, 0};
int arr[5];
// default count this program will go up to is 6
byte count = 1;

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

  // if a button is pressed it'll add 1 to the count or remove one or reset it to 0
  if(buttonStates[0] != previousStates[0])
  {
    previousStates[0] = buttonStates[0];
    if(buttonStates[0] == HIGH)
    {
      Serial.println("count up");
      turnOff();
      count++;
    }
  }
  if(buttonStates[1] != previousStates[1])
  {
    previousStates[1] = buttonStates[1];
    if(buttonStates[1] == HIGH)
    {
      Serial.println("count down");
      turnOff();
      count--;
    }
  }
  if(buttonStates[2] != previousStates[2])
  {
    previousStates[2] = buttonStates[2];
    if(buttonStates[2] == HIGH)
    {
      Serial.println("count to 0");
      turnOff();
      count = 1;
    }
  }
  // send the count to the method to light up the binary equivalent of the number
  decimalToBinary(count);
  delay(200);
  if(count < 1) count = 1;
  if(count > 5) count = 5;
}

// read the byte, if it's 1 light up the led
void decimalToBinary(byte number)
{
  for(int i = 0; i < 4; i++)
  {
    if(bitRead(number, i) == 1)
    {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}

void turnOff()
{
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}