int trigPin = 6;
int echoPin = 7;
int leds[5] = { 13, 12, 11, 10, 9 };
int lightLeds[5] = { 0, 0, 0, 0, 0 };

int distance = 0;
long duration;

void setup() {
  // have trig as output and echo as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Set leds as output
  for (int i = 0; i < 5; i++) {
    pinMode(leds[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {


  digitalWrite(trigPin, LOW);
  delay(2);

  // releases sound wave with a delay of 10 milliseconds
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  // returns the sound wave travel time
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;  // calculates distance in cm
  Serial.println(distance);
  Serial.print("cm");

  // use switch case
  // for every 20 cm a led will light up
  // 5 leds lit up will equate to 100cm

  // use seperate array and in the switch case set the leds that light up to 1 and those
  // that should be off to 0
  // the code will check if it's 1 or 0 to light up the leds
  if (distance >= 0 && distance < 20) {
    for (int i = 0; i < 5; i++) {
      lightLeds[i] = 0;
    }
  } else if (distance >= 20 && distance < 40) {
    for (int i = 0; i < 5; i++) {
      if (i == 0) {
        lightLeds[i] = 1;
      } else {
        lightLeds[i] = 0;
      }
    }
  } else if (distance >= 40 && distance < 60) {
    for (int i = 0; i < 5; i++) {
      if (i >= 0 && i <= 1) {
        lightLeds[i] = 1;
      } else {
        lightLeds[i] = 0;
      }
    }
  } else if (distance >= 60 && distance < 80) {
    for (int i = 0; i < 5; i++) {
      if (i >= 0 && i <= 2) {
        lightLeds[i] = 1;
      } else {
        lightLeds[i] = 0;
      }
    }
  } else if (distance >= 80 && distance < 100) {
    for (int i = 0; i < 5; i++) {
      if (i >= 0 && i <= 3) {
        lightLeds[i] = 1;
      } else {
        lightLeds[i] = 0;
      }
    }
  } else if (distance >= 100) {
    for (int i = 0; i < 5; i++) {
      lightLeds[i] = 1;
    }
  }
  led();
  delay(500);
}

void led() {
  for (int i = 0; i < 5; i++) {
    if (lightLeds[i] == 1) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}