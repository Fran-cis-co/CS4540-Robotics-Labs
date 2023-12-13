// The OneButton library was used to implement the long press, double press, and short press
// I couldn't really figure out how to implement a double press without this
int button = 10;
int leds[3] = {7, 6, 5};

int buttonState = 0;
int prevButtonState = 0;
bool led = true;
int count = 0;

int startPress = 0;
int endPress = 0;
int holdTime = 0;
int idleTime = 0;
int doublePress = 0;
int longPress = 0;

void setup() {
  for(int i = 0; i < 3; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(button);
  /*
  if(buttonState != prevButtonState)
  {
    prevButtonState = buttonState;
    if(buttonState == LOW)
    {
      if(led)
      {
        digitalWrite(leds[0], HIGH);
      } else {
        digitalWrite(leds[0], LOW);
      }
      led = !led;
    }
  }
  */

  if(buttonState != prevButtonState)
  {
     if (buttonState == HIGH) {
      startPress = millis();
      idleTime = startPress - endPress;

      if (idleTime >= 100 && idleTime < 500) {
          disco();
      }
    } else {
        endPress = millis();
        holdTime = endPress - startPress;

        if (holdTime >= 500 && holdTime < 1000) {
          stopLight();
        }

        if (holdTime >= 1000) {
          turnOffLeds();
        }
    }
  }

  prevButtonState = buttonState;
}

void stopLight()
{
  digitalWrite(leds[0], HIGH);
  delay(5000);
  digitalWrite(leds[0], LOW);

  digitalWrite(leds[1], HIGH);
  delay(2000);
  digitalWrite(leds[1], LOW);

  digitalWrite(leds[2], HIGH);
  delay(5000);
  digitalWrite(leds[2], LOW);
}

void disco()
{
  for(int i = 0; i < 10; i++){
      int r = rand() % 3;
      int l = rand() % 3;

      digitalWrite(leds[r], HIGH);
      digitalWrite(leds[l], HIGH);
      delay(200);
      digitalWrite(leds[r], LOW);
      digitalWrite(leds[l], LOW);
  }
}

void turnOffLeds()
{
  for(int i = 0; i < 3; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}