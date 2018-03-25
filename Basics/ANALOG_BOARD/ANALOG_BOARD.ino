#include<TimerOne.h>
void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(500000);
  Timer1.attachInterrupt(readBoard);
  Serial.begin(9600);
}

void readBoard(void) {
  Serial.println(analogRead(0)+analogRead(1));
}

void loop() {
  // put your main code here, to run repeatedly:
}
