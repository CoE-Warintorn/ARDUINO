#include<TimerOne.h>
const int led = 13;
int ledState = LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Timer1.initialize(500000);
  Timer1.attachInterrupt(blinkLed);
  Serial.begin(9600);
}

void blinkLed() {
   ledState = (ledState==LOW?HIGH:LOW);
   digitalWrite(led, ledState);
   Serial.println(ledState);
}

void loop() {
  // put your main code here, to run repeatedly:

}
