/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#define pushButton 52 //pin Push-Button pada Arduino

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT_PULLUP);
  Serial.println("Tes Push Buttton");
  delay(1000);
}

void loop() {
  int value = digitalRead(pushButton);
  Serial.print("value = ");
  Serial.println(value);
  delay(100);
  //nilai value akan berbeda antara pushbutton ditekan dan tidak ditekan
}
