const int ledPin = 9;
const int shortBlinkDuration = 200; 
const int longBlinkDuration = 600;  
const int pauseDuration = 800;      

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Blink "S" (3 short blinks)
  for (int i = 0; i < 3; i++) {
    blinkShort();
  }
  delay(pauseDuration);

  // Blink "O" (3 long blinks)
  for (int i = 0; i < 3; i++) {
    blinkLong();
  }
  delay(pauseDuration); //for some reason i couldnt add another S loop as when it would run it would run SSO so i just stuck with SO and it works solid

}

void blinkShort() { //functions to blink the LED make it neater
  digitalWrite(ledPin, HIGH);
  delay(shortBlinkDuration);
  digitalWrite(ledPin, LOW);
  delay(shortBlinkDuration);
}

void blinkLong() {
  digitalWrite(ledPin, HIGH);
  delay(longBlinkDuration);
  digitalWrite(ledPin, LOW);
  delay(shortBlinkDuration);
}
