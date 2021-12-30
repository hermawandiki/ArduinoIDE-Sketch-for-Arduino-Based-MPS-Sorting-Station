/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#define ledGreen 53
#define ledYellow 51
#define ledRed 49

void setup() {
  Serial.begin(9600);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledRed, OUTPUT);
  Serial.println("Tes LED Indikator");
  delay(1000);
}

void loop() {
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, HIGH);
  delay(3000);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, HIGH);
  delay(1000);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(5000);
}
