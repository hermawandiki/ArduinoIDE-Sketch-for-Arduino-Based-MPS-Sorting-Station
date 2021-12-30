/*Program for Hardware Test
  Trainer MPS Sorting Based Arduino
  Mechatronics Engineering 2nd Generation
  Vocational High School 2 Bojonegoro
*/

#define S0 25
#define S1 48
#define S2 42
#define S3 44
#define led 46
#define tcs_out 40
int frequency = 0;

void setup() {
  Serial.begin(9600);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(tcs_out, INPUT);
  Serial.println("Tes Sensor Warna");
  delay(1000);

  digitalWrite(led, LOW);
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {
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
  }
  if (G < B && B < R) {
    Serial.println("  : Hijau");
  }
  if (B < G && G < R && B < 200) {
    Serial.println("  : Biru");
  }
  if (R > 200 && G > 200 && B > 200) {
    Serial.println("  : Unknown");
  }
}
