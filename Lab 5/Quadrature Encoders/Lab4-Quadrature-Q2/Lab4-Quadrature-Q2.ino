/*
quadrature encoder to serial monitor
by richard kj cross 2023-10-07
*/

// starter code was provided by professor Cross
// For this Exercise a variable with a number will be used
// this will be the delay the led movement will get
// if moved clockwise, it will speed up
// if moved counter-clockwise, it will slow down and pushing will reset it
// default wait value will be a second
const byte pinA = 2;
const byte pinB = 3;
const int pinC = 4;

int wait = 1000;
int direction = 0;
const int leds[5] = { 13, 12, 11, 10, 9 };
int count = 0;
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
  pinMode(pinC, INPUT);
  pinA_read = digitalRead(pinA);
  pinB_read = digitalRead(pinB);
  pinA_previous = pinA_read;
  pinB_previous = pinB_read;

  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  pinA_read = digitalRead(pinA);
  pinB_read = digitalRead(pinB);
  pinC_state = digitalRead(pinC);

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

  if (pinC_state == LOW) {
    wait = 1000;
    Serial.println("pushed");
  }

  // if 0 it goes left/right depending on the angle you view
  // 1 goes the opposite direction
  if (direction == 0) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(leds[i], HIGH);
      delay(wait);
      digitalWrite(leds[i], LOW);
      delay(wait);
    }
  } else if (direction == 1) {
    for (int i = 4; i >= 0; i--) {
      digitalWrite(leds[i], HIGH);
      delay(wait);
      digitalWrite(leds[i], LOW);
      delay(wait);
    }
  }
}

static void lightLED() {
  if (bCW) {
    wait -= 300;
    direction = 0;
  } else {
    wait -= 300;
    direction = 1;
  }

  if (wait < 150) {
    wait = 150;
  }

}