void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("1 And 0 =");
  Serial.println(B1 & B0);

  Serial.print("1 Or 0 =");
  Serial.println(B1 | B0);

  Serial.print("1 XOR 0 =");
  Serial.println(B1 ^ B0);
  delay(1000);
}
