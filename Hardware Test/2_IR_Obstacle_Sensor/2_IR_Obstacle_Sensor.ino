/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#define obstacleSensor 34 //pilih pin sesuai pin sensor yang akan dicoba (lihat list dibawah)

/*
  Sensor IR Obstacle  = 30 : IR Stack Magazine
                        32 : IR Conveyor
                        34 : IR Slider 1
                        36 : IR Slider 2
                        38 : IR Slider 3
*/

void setup() {
  Serial.begin(9600);
  pinMode(obstacleSensor, INPUT);
  Serial.println("Tes Infrared Sensor");
  delay(1000);
}

void loop() {
  int value = digitalRead(obstacleSensor);
  Serial.print("value = ");
  Serial.println(value);
  delay(100);
  //nilai value akan berbeda antara sensor mendeteksi halangan atau tidak mendeteksi halangan
}
