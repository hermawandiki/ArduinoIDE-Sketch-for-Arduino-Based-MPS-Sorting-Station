//Bismillahirrohmanirrohim MPS SORTING BASED ARDUINO

/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#include<Servo.h>
Servo ser1, ser2, ser3;

char masuk = 0;
int freq = 0;
int warna = 0;

void setup() {
  Serial.begin(9600);
  pinMode(30, INPUT);//ir stack
  pinMode(32, INPUT);//ir check
  pinMode(34, INPUT);//ir slider
  pinMode(36, INPUT);//ir slider
  pinMode(38, INPUT);//ir slider

  pinMode(52, INPUT_PULLUP);//button
  pinMode(50, INPUT);//proximity

  pinMode(3, OUTPUT);//servo stack
  pinMode(5, OUTPUT);//servo 1
  pinMode(4, OUTPUT);//servo 2
  pinMode(24, OUTPUT);//enable motor
  pinMode(2, OUTPUT);//motor speed

  pinMode(49, OUTPUT);//led red
  pinMode(51, OUTPUT);//led yellow
  pinMode(53, OUTPUT);//led green

  pinMode(40, INPUT);//sensor out
  pinMode(25, OUTPUT);//s0
  pinMode(48, OUTPUT);//s1
  pinMode(42, OUTPUT);//s2
  pinMode(44, OUTPUT);//s3
  pinMode(46, OUTPUT);//led

  Serial.println("Welcome !");
  delay(2000);
  ser1.attach(5);
  ser2.attach(4);
  ser3.attach(3);
  ser1.write(62);
  ser2.write(60);
  digitalWrite(25, HIGH);
  digitalWrite(48, LOW);
  digitalWrite(46, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    masuk = Serial.read();

    if (masuk == 'a') { //ir
      int ir1 = digitalRead(30);
      Serial.print(ir1);
      int ir2 = digitalRead(32);
      Serial.print(ir2);
      int ir3 = digitalRead(34);
      Serial.print(ir3);
      int ir4 = digitalRead(36);
      Serial.print(ir4);
      int ir5 = digitalRead(38);
      Serial.println(ir5);
      delay(50);
    }
    if (masuk == 'b') { //prox button
      int prox = digitalRead(50);
      Serial.print(prox);
      int button = digitalRead(52);
      Serial.println(button);
      delay(50);
    }
    if (masuk == 'c') { //servo stack
      ser3.write(150);
      delay(1000);
      ser3.write(102);
      delay(2000);
      ser3.write(70);
      delay(3500);
      ser3.write(100);
      delay(1000);
    }
    if (masuk == 'd') { //servo slider
      ser1.write(9);
      ser2.write(3);
      delay(1000);
      ser1.write(62);
      ser2.write(60);
      delay(1000);
    }
    if (masuk == 'e') { //conveyor
      digitalWrite(24, HIGH);
      analogWrite(2, 80);
      delay(3000);
      digitalWrite(24, LOW);
      analogWrite(2, 0);
      delay(3000);
    }
    if (masuk == 'f') { //led
      digitalWrite(53, LOW);
      digitalWrite(49, HIGH);
      delay(100);
      digitalWrite(49, LOW);
      digitalWrite(51, HIGH);
      delay(100);
      digitalWrite(51, LOW);
      digitalWrite(53, HIGH);
      delay(100);
    }
    if (masuk == 'g') { //color sensor
      digitalWrite(46, HIGH);
      digitalWrite(42, LOW);
      digitalWrite(44, LOW);
      freq = pulseIn(40, LOW);
      int R = freq;
      delay(50);
      digitalWrite(42, HIGH);
      digitalWrite(44, HIGH);
      freq = pulseIn(40, LOW);
      int G = freq;
      delay(50);
      digitalWrite(42, LOW);
      digitalWrite(44, HIGH);
      freq = pulseIn(40, LOW);
      int B = freq;
      delay(50);
      digitalWrite(46, LOW);

      if (R < B && B < G) {
        Serial.println('1');
      }
      if (G < B && B < R) {
        Serial.println('2');
      }
      if (B < G && G < R && B < 200) {
        Serial.println('3');
      }
      if (R > 200 && G > 200 && B > 200) {
        Serial.println('4');
      }
      delay(50);
    }
  }
  else {
    Serial.println("Sistem Standby");
    digitalWrite(24, LOW);
    analogWrite(2, 0);
    ser1.write(62);
    ser2.write(60);
    ser3.write(100);
    digitalWrite(49, LOW);
    digitalWrite(51, LOW);
    digitalWrite(53, LOW);
    delay(50);
  }
}
