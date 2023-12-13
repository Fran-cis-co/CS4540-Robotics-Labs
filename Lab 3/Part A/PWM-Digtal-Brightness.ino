const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}
// use the analoguewrite function to set the PMW value and simulate a fading effect of a LED going dim to bright
void loop() {
  // Dim to bright
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(10); //simulate the fading
  }

  // Bright to dim
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(10);
  }
}