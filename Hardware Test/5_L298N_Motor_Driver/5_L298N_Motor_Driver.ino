/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
  2021
*/

#define IN1 22
#define IN2 24
#define ENA 2

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  Serial.println("Tes Motor Conveyor");
  delay(1000);
}

void loop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 80);
  delay(60000);
}
