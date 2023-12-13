/*
quadrature encoder to serial monitor
by richard kj cross 2023-10-07
*/

// starter code was provided by professor Cross
// the method for this is to use a count variable and light up the pin location [0-4] when the encoder is rotated
// when a rotation is detected, the count goes up or down
const byte pinA = 2;
const byte pinB = 3; 

const int leds[5] = {13, 12, 11, 10, 9};
int count = 0;
int encoderPosCount = 0;
int pinA_read;
int pinA_previous;
int pinB_read;
int pinB_previous;

boolean bCW;

void setup() {
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinA_read = digitalRead(pinA);
  pinB_read = digitalRead(pinB);
  pinA_previous = pinA_read;
  pinB_previous = pinB_read;

  for(int i = 0; i < 5; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
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


}

static void lightLED() {
  if (bCW) {
    count++;
    if(count > 4) count = 4;
  } else {
    count--;
    if(count < 0) count = 0;
  }

  for(int i = 0; i < 5; i++)
  {
    if(i == count)
    {
      digitalWrite(leds[i], HIGH);
    } else
    {
      digitalWrite(leds[i], LOW);
    }
  }
}
