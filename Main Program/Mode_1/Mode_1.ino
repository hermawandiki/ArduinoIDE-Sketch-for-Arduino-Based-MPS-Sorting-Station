//Bismillahirrohamanirrohim MPS SORTING BASED ARDUINO

/*
  LOW COST MPS SORTING BASED ARDUINO
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#define mainButton 52
#define ir_stack 30
#define ir_cek 32
#define ir_s1 34
#define ir_s2 36
#define ir_s3 38
#define prox_cek 50

#define ser1 3
#define ser2 5
#define ser3 4
#define motor_in1 22
#define motor_in2 24
#define motor_en 2

#include<Servo.h>
Servo servoStack, servo_s1, servo_s2;

int warna = 0;
int latch = 0;
int counter1 = 0;
int counter2 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(mainButton, INPUT_PULLUP);
  pinMode(ir_stack, INPUT);
  pinMode(ir_cek, INPUT);
  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);
  pinMode(ir_s3, INPUT);
  pinMode(prox_cek, INPUT);

  pinMode(motor_in1, OUTPUT);
  pinMode(motor_in2, OUTPUT);
  pinMode(motor_en, OUTPUT);

  pinMode(49, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(53, OUTPUT);

  servoStack.attach(ser1);
  servo_s1.attach(ser2);
  servo_s2.attach(ser3);
  servo_s1.write(62);
  servo_s2.write(60);
}

void loop() {
  int stok = digitalRead(ir_stack);
  if (stok == 1) {
    Serial.println("Stok Tersedia");
    digitalWrite(49, LOW);
    digitalWrite(51, LOW);
    digitalWrite(53, HIGH);
    //--------------------------------------------------------------------------------------------------------------------------------------
    int button = digitalRead(mainButton);
    if (button == 0) {
      latch++;
      delay(500);
      digitalWrite(49, LOW);
      digitalWrite(51, HIGH);
      digitalWrite(53, LOW);
      Serial.println("Sistem akan segera berjalan");
      delay(1000);
      if (latch >= 2) {
        latch = 0;
      }
    }
    //--------------------------------------------------------------------------------------------------------------------------------------
    switch (latch) {
      case 1 :
        Serial.println("Workpiece Masuk");
        servoStack.write(150);
        delay(1200);
        servoStack.write(102);
        delay(2000);
        servoStack.write(70);
        delay(3500);
        servoStack.write(100);
        delay(1000);
        //------------------------------------------------------------------------------------------------------------------------------------
        warna = digitalRead(ir_cek);
        Serial.println("Scan Warna");
        //--------------------------------------------------------------------------------------------------------------------------------------
        switch (warna) {
          case 0:
          Serial.println('0');
            if (counter1 >= 3) {
              latch = 0 ;
            }
            else {
              servo_s1.write(9);
              //--------------------------------------------------------------------------------------------------------------------------------------
              while (digitalRead(ir_s1) == 1) {
                digitalWrite(motor_in1, LOW);
                digitalWrite(motor_in2, HIGH);
                analogWrite(motor_en, 80);
              }
              //-------------------------------------------------------------------------------------------------------------------------------------
              counter1++;
              delay(300);
            }
            break;
          //-------------------------------------------------------------------------------------------------------------------------------------
          case 1:
          Serial.println('1');
            if (counter2 >= 3) {
              latch = 0 ;
            }
            else {
              servo_s2.write(3);
              //--------------------------------------------------------------------------------------------------------------------------------------
              while (digitalRead(ir_s2) == 1) {
                digitalWrite(motor_in1, LOW);
                digitalWrite(motor_in2, HIGH);
                analogWrite(motor_en, 80);
              }
              //-------------------------------------------------------------------------------------------------------------------------------------
              counter2++;
              delay(300);
            }
            break;
        }
        //--------------------------------------------------------------------------------------------------------------------------------------
        digitalWrite(motor_in1, LOW);
        digitalWrite(motor_in2, LOW);
        analogWrite(motor_en, 0);
        //-------------------------------------------------------------------------------------------------------------------------------------
        servo_s1.write(62);
        servo_s2.write(60);
        //-------------------------------------------------------------------------------------------------------------------------------------
        Serial.print("Counter 1 = ");
        Serial.print(counter1);
        Serial.print(" & Counter 2 = ");
        Serial.println(counter2);
        delay(1000);
    }
  }
  else {
    idle();
  }
}

void idle() {
  Serial.println("Sistem Standby");
  digitalWrite(motor_in1, LOW);
  digitalWrite(motor_in2, LOW);
  analogWrite(motor_en, 0);
  servo_s1.write(62);
  servo_s2.write(60);
  servoStack.write(100);
  digitalWrite(49, HIGH);
  digitalWrite(51, LOW);
  digitalWrite(53, LOW);
  latch = 0;
}
