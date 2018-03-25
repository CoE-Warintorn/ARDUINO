#define SW1 2
#define LED 3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SW1, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool bSW1;
  bSW1 = digitalRead(SW1);
  digitalWrite(LED, bSW1);
  Serial.println(bSW1);
}
