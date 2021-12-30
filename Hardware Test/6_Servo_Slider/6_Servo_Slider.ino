/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#include<Servo.h>
Servo tesServo;

#define motorServo 4 //pilih pin servo sesuai yang akan dicoba (lihat list dibawah)

/*
  Servo Motor  = 4 : Servo Slider 1 -- Buka = 62 | Tutup = 9
                 5 : Servo Slider 2 -- Buka = 60 | Tutup = 3
*/

void setup() {
  Serial.begin(9600);
  tesServo.attach(motorServo);
  tesServo.write(60);
  Serial.println("Tes Servo Slider");
  delay(1000);
}

void loop() {
  tesServo.write(3);
  delay(5000);
  tesServo.write(60);
  delay(5000);
}
