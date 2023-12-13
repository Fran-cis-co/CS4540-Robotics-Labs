/*
quadrature encoder to serial monitor
by richard kj cross 2023-10-07
*/

// starter code was provided by professor Cross
// For this exercise a similar approach will be used as the first LED light
// clockwise will increase the brightness while counter will dim it
const byte pinA = 2;
const byte pinB = 3;
const int led = 12;
int ledBrightness = 0;
int encoderPosCount = 0;
int buttonRead = 0;
int pinA_read;
int pinA_previous;
int pinB_read;
int pinB_previous;
int pinC_state = 0;

boolean bCW;

void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinA_read = digitalRead(pinA);
  pinB_read = digitalRead(pinB);
  pinA_previous = pinA_read;
  pinB_previous = pinB_read;

  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  pinA_read = digitalRead(pinA);
  pinB_read = digitalRead(pinB);

  if (pinA_read != pinA_previous and pinB_read != pinB_previous) {
    Serial.println("-- input error --");
  } else if (pinA_read != pinA_previous or pinB_read != pinB_previous) {

    if (pinA_read != pinA_previous) {  // pin A changed
      if (pinB_read != pinA_read) {    // after pin-A changes -> if A != B => CW
        encoderPosCount++;
        bCW = true;
      } else {  // Otherwise we're moving CCW
        encoderPosCount--;
        bCW = false;
      }
    } else {                         // pin B changed
      if (pinB_read == pinA_read) {  // after pin-B changes -> if A == B => CW
        encoderPosCount++;
        bCW = true;
      } else {  // Otherwise we're moving CCW
        encoderPosCount--;
        bCW = false;
      }
    }
    lightLED();

    pinA_read = digitalRead(pinA);
    pinB_read = digitalRead(pinB);
    pinA_previous = pinA_read;
    pinB_previous = pinB_read;
  }

  analogWrite(led, ledBrightness);
  Serial.println(ledBrightness);
  delay(20); // delay to simulate fading
}

static void lightLED() {
  // increase brightness if turned left, else decrease
  // ensures the number stays between 0 and 255
  if (bCW) {
    ledBrightness++;
    if(ledBrightness > 255) ledBrightness = 255;
  } else {
    ledBrightness--;
    if(ledBrightness < 0) ledBrightness = 0;
  }
}