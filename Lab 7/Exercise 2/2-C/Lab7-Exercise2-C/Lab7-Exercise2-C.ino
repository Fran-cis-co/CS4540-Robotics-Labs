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
}

void loop() {
  // First loops makes the servo go from position 0 to 180 to make a full rotation
  for (pos = 0; pos <= 180; pos += 1) { 
    myservo.write(pos);              
    delay(2); // have delay of 2 milliseconds to have fastest possible 180 degree turn               
  }
  // goes from 180 to 0 to return back to its original position
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(2);                       
  }
}

