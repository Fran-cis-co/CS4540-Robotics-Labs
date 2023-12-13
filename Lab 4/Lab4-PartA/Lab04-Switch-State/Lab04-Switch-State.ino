const int PIN = 10; // have this pin just because

// have value & lastValue to check if the button is pressed or released and ensures
// the count is put in the right variable (buttonPressed or buttonReleased)
int value = 0;
int lastValue = 0;
int buttonPressed = 0;
int buttonReleased = 0;

void setup() {
  // Set pin as input
  pinMode(PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // this gets the current value and also saves the last value at the end
  // if it's not the same as the previous value, it means the button was pressed or released.
  // if the value is HIGH, add 1 to buttonPressed
  // otherwise, add 1 to buttonReleased
  value = digitalRead( PIN );

  if( value != lastValue){
    if(value == HIGH){
      buttonPressed++;
      Serial.println("Number of times button pressed: ");
      Serial.println(buttonPressed);
    } else {
      buttonReleased++;
      Serial.println("Number of times button released: ");
      Serial.println(buttonReleased);
    }
  }

  lastValue = value;
}
