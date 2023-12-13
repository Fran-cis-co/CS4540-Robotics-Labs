int green = 13;
int yellow = 9;
int red = 6;
int blue = 4;
int white = 2;
int leds[5] = {green, yellow, red, blue, white};

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(white, OUTPUT);
}

void loop() {
  int r = rand() % 5;
  int l = rand() % 5;

  digitalWrite(leds[r], HIGH);
  digitalWrite(leds[l], HIGH);
  delay(1000);
  digitalWrite(leds[r], LOW);
  digitalWrite(leds[l], LOW);
  
}

