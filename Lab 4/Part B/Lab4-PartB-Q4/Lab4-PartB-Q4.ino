const int buttonPin = 10;
const int ledPin = 4;
int buttonState = 0;

int prevButtonState = LOW;
bool led = true;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // have a current button state and a previous button state
  // this is to ensure when the button is no longer pressed the led doesn't change its state
  buttonState = digitalRead(buttonPin);
  if(buttonState != prevButtonState)
  {
    prevButtonState = buttonState;
    if(buttonState == LOW)
    {
      if(led)
      {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
      led = !led;
    }
  }
}
