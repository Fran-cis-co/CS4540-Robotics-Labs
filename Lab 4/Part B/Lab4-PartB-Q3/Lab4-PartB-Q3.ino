const int buttonPin = 10;
const int ledPin = 4;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH)
  {
    digitalWrite(ledPin, LOW);
  } else
  {
    digitalWrite(ledPin, HIGH);
  }

}