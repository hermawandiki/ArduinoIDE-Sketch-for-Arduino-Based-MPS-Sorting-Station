/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#define inductiveProximity 50 //pin sensor induktif pada Arduino

void setup() {
  Serial.begin(9600);
  pinMode(inductiveProximity, INPUT);
  Serial.println("Tes Sensor Induktif");
  delay(1000);
}

void loop() {
  int value = digitalRead(inductiveProximity);
  Serial.print("value = ");
  Serial.println(value);
  delay(100);
  //nilai value akan berbeda antara sensor mendeteksi benda logam atau non-logam
}
