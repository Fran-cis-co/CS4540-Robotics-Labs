int green = 13;
int yellow = 9;
int red = 6;
int blue = 4;
int arr[4];
int leds[4] = {green, yellow, red, blue};

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  for(int i = 0; i < 16; i++)
  {
    decimalToBinary(i);
    delay(1000);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
  }

  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  delay(3000);

  for(int i = 15; i > -1; i--)
  {
    decimalToBinary(i);
    delay(1000);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
  }
}

void decimalToBinary(int number)
{
  int i = 0;
  while(number != 0)
  {
    arr[i] =  number % 2;
    i++;
    number = number / 2;
  }

  for(int i = 0; i < 4; i++)
  {
    if(arr[i] == 1)
    {
      digitalWrite(leds[i], HIGH);
    }
  }
}