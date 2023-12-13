int trigPin = 6;
int echoPin = 7;
int buttonPin = 8;

int distanceCM;
int distanceInch;
// measurement variable changes with button press
// if false the distance will print out in cm, else if true it will be inches
bool measurement = false;
long duration;
int buttonState = 0;
int prevButtonState = 0;

void setup() {
  // have trig as output and echo as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);


  digitalWrite(trigPin, LOW);
  delay(2);

  // releases sound wave with a delay of 10 milliseconds
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  // returns the sound wave travel time
  duration = pulseIn(echoPin, HIGH);

  distanceCM = duration * 0.034 / 2;     // calculates distance in cm
  distanceInch = duration * 0.0133 / 2;  // calculates distnace in inches

  // if button is pressed change measurement value;

  if(buttonState != prevButtonState)
  {
    prevButtonState = buttonState;
    if(buttonState == LOW)
    {
      Serial.println("pressed");
      measurement = !measurement;
    }
  }

  // use switch case statement for cleaner code
  switch (measurement) {
    case false:
      Serial.print("Distance: ");
      Serial.print(distanceCM);
      Serial.print("cm\n");
      break;
    case true:
      Serial.print("Distance: ");
      Serial.print(distanceInch);
      Serial.print("in\n");
      break;
  }

  delay(500);
}
