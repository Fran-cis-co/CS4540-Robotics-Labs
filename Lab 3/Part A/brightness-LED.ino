const int ledPin = 9;  
const int totalTime = 2000; 

void setup() {
  pinMode(ledPin, OUTPUT);
}
// better to use for loops for this to itterate the brightness going from 0-100% and 100%-0%
void loop() {
  // Brighten the LED
  for (int brightness = 0; brightness <= 100; brightness++) {
    digitalWrite(ledPin, HIGH); 
    delay((brightness * totalTime / 100) / 40); //the higher the divsion the more slower it lights up
    digitalWrite(ledPin, LOW);
    delay(((100 - brightness) * totalTime / 100) / 40); //for the top
  }

  // Keep the LED on at maximum brightness for a while
  delay(1000);

  // Dim the LED
  for (int brightness = 100; brightness >= 0; brightness--) {
    digitalWrite(ledPin, HIGH); 
    delay((brightness * totalTime / 100) / 40); 
    digitalWrite(ledPin, LOW); 
    delay(((100 - brightness) * totalTime / 100) / 40); 
  }
}