/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#include<Servo.h>
Servo tesServo;

#define motorServo 3 //pin servo linear actuator pada Arduino

void setup() {
  Serial.begin(9600);
  tesServo.attach(motorServo);
  Serial.println("Tes Servo Linear Actuator");
  delay(1000);

  servoStack.write(150);
  delay(1200);
  servoStack.write(102);
  delay(2000);
  servoStack.write(70);
  delay(3500);
  servoStack.write(100);
  delay(1000);
}

void loop() {

}
