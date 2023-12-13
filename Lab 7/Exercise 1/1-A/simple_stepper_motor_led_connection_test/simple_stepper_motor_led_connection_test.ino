/*
   BYJ48 Stepper motor code
   Connect :
   IN1 >> D8
   IN2 >> D9
   IN3 >> D10
   IN4 >> D11
   VCC ... 5V Prefer to use external 5V Source
   Gnd
   written By :Mohannad Rawashdeh
  https://www.instructables.com/member/Mohannad+Rawashdeh/
     28/9/2013
  */

/*
  
  Run this modified test sketch to check that all four of the motor driver channels are working
  this also checks that they are wired correctly
  all 4 leds should light for 1 sec, then all 4 will go darkfor a 1/2 second
  then each individual led should light up in sequence
  the sequence should be in order
  they should light up one at a time starting at one end 
  and then each led will light up IN ORDER:
    all on -> all off -> A -> B -> C -> D -> all off -> repeat 
  or in this order
    all on -> all off -> D -> C -> B -> A -> all off -> repeat 

      richard kj cross 2023-10-12
*/

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
int Steps = 0;
boolean Direction = true; 
unsigned long last_time;
unsigned long currentMillis;
int steps_left = 4095;
long time;
void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // delay(1000);
}
void loop() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);

  delay(1000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(200);

  digitalWrite(IN1, HIGH);
  delay(500);
  digitalWrite(IN1, LOW);

  digitalWrite(IN2, HIGH);
  delay(500);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  delay(500);
  digitalWrite(IN3, LOW);

  digitalWrite(IN4, HIGH);
  delay(500);
  digitalWrite(IN4, LOW);

  delay(500);

  // comment the previous led code and uncomment the following code
  // to get the starter code in the sketch:
  // simple_stepper_motor_easy_control_direct.ino file

  // while (steps_left > 0) {
  //   currentMillis = micros();
  //   if (currentMillis - last_time >= 1000) {
  //     stepper(1);
  //     time = time + micros() - last_time;
  //     last_time = micros();
  //     steps_left--;
  //   }
  // }
  // Serial.println(time);
  // Serial.println("Wait...!");
  // delay(2000);
  // Direction = !Direction;
  // steps_left = 4095;
}

void stepper(int xw) {
  for (int x = 0; x < xw; x++) {
    switch (Steps) {
      case 0:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;
      case 1:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, HIGH);
        break;
      case 2:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break;
      case 3:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        break;
      case 4:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      case 5:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      case 6:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
      case 7:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        break;
      default:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        break;
    }
    SetDirection();
  }
}
void SetDirection() {
  if (Direction == 1) { Steps++; }
  if (Direction == 0) { Steps--; }
  if (Steps > 7) { Steps = 0; }
  if (Steps < 0) { Steps = 7; }
}
