#include<TimerOne.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
float fVolt;
int an0;
void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(250000);
  Timer1.attachInterrupt(Update);
  lcd.begin(16, 2);
}

void Update(void) {
  lcd.clear();
  lcd.setCursor(0, 0);
  an0 = analogRead(0);
  lcd.print(an0);
  lcd.setCursor(0, 1);
  fVolt = map(an0, 0, 1023, 0, 500)/100.0f;
  lcd.print(fVolt);
}

void loop() {
  // put your main code here, to run repeatedly:
}
