//Bismillahirrohamanirrohim MPS SORTING BASED ARDUINO

/*
  LOW COST MPS SORTING BASED ARDUINO
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#define mainButton 52
#define ir_stack 30
#define ir_s1 34
#define ir_s2 36
#define ir_s3 38

#define ser1 3
#define ser2 5
#define ser3 4
#define motor_in1 22
#define motor_in2 24
#define motor_en 2

#define S0 25
#define S1 48
#define S2 42
#define S3 44
#define tcs_out 40
#define led 46

#include<Servo.h>
Servo servoStack, servo_s1, servo_s2;

int frequency = 0;
int warna = 0;
int latch = 0;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(mainButton, INPUT_PULLUP);
  pinMode(ir_stack, INPUT);
  pinMode(ir_s1, INPUT);
  pinMode(ir_s2, INPUT);
  pinMode(ir_s3, INPUT);
  pinMode(tcs_out, INPUT);

  pinMode(motor_in1, OUTPUT);
  pinMode(motor_in2, OUTPUT);
  pinMode(motor_en, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(led, OUTPUT);

  pinMode(49, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(53, OUTPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  digitalWrite(led, LOW);

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
      Serial.println("Sistem akan mulai berjalan");
      delay(1000);
      if (latch >= 2) {
        latch = 0;
      }
    }

    switch (latch) {
      case 1 :
        Serial.println("Workpiece Masuk");
        servoStack.write(150);
        delay(1200);
        servoStack.write(100);
        delay(2000);
        servoStack.write(70);
        delay(3500);
        servoStack.write(100);
        delay(1000);
        //-----------------------------------------------------------------------------------------------------------------------------------
        warna = cekWarna();
        switch (warna) {
          case 1:
            Serial.println('1');
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
          case 2:
            Serial.println('2');
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
          //--------------------------------------------------------------------------------------------------------------------------------------
          case 3:
            Serial.println('3');
            if (counter3 >= 3) {
              latch = 0 ;
            }
            else {
              while (digitalRead(ir_s3) == 1) {
                digitalWrite(motor_in1, LOW);
                digitalWrite(motor_in2, HIGH);
                analogWrite(motor_en, 80);
              }
              //-------------------------------------------------------------------------------------------------------------------------------------
              counter3++;
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
        Serial.print("CNT1= ");
        Serial.print(counter1);
        Serial.print(" CNT2= ");
        Serial.print(counter2);
        Serial.print(" CNT3= ");
        Serial.println(counter3);
        delay(500);
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

int cekWarna() {
  Serial.println("Scan Warna");
  digitalWrite(led, HIGH);
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequency = pulseIn(tcs_out, LOW);
  int R = frequency;
  Serial.print("R=  ");
  Serial.print(R);
  delay(50);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(tcs_out, LOW);
  int G = frequency;
  Serial.print(" G= ");
  Serial.print(G);
  delay(50);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequency = pulseIn(tcs_out, LOW);
  int B = frequency;
  Serial.print(" B= ");
  Serial.print(B);
  delay(50);
  digitalWrite(led, LOW);

  if (R < B && B < G) {
    Serial.println("  : Merah");
    warna = 1;
  }
  if (G < B && B < R) {
    Serial.println("  : Hijau");
    warna = 2;
  }
  if (B < G && G < R && B < 200) {
    Serial.println("  : Biru");
    warna = 3;
  }
  if (R > 200 && G > 200 && B > 200) {
    Serial.println("  : Unknown");
  }
  return warna;
}
