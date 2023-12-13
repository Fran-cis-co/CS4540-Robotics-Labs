/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  randomSeed(analogRead(0)); // start the random number generator
  myservo.write(pos); // set the default position
  Serial.begin(9600);
}

void loop() {
  int degree = random(20,30); // create random degree number between 20-30 degrees  
  myservo.write(pos + degree); // move the servo to a random direction in the certain degree
  delay(1000);

  // get the current position and print it out to see where the current position is
  // this is to check if it gets close to the original position
  int currentPosition = myservo.read(); // get the current position
  Serial.print("Current position: ");
  Serial.print(currentPosition);
  Serial.print("\n");
}

