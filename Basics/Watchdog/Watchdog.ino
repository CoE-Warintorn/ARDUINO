#include<Arduino.h>
#include<avr/wdt.h>
#include<TimerOne.h>
#define onBoardLED 13
int ledState;
void setup() {
  // put your setup code here, to run once:
  int k;
  wdt_disable();
  pinMode(onBoardLED, OUTPUT);
  for(k=1; k<=20; k++){
    digitalWrite(onBoardLED, HIGH);
    delay(100);
    digitalWrite(onBoardLED, LOW);
    delay(100);
  }
  delay(1000);
  ledState = LOW;
  wdt_enable(WDTO_1S);
  Timer1.initialize(500000);
  Timer1.attachInterrupt(resetWatchdog);
}

void resetWatchdog(void) {
  ledState = (ledState == LOW)? HIGH:LOW;
 digitalWrite(onBoardLED, ledState);
 wdt_reset();
}
void loop() {
  // put your main code here, to run repeatedly:

}
