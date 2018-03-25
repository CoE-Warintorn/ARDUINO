#define interruptPin 0
volatile byte interruptCounter = 0;
int numberOfInterrupts = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);
}

void handleInterrupt(void) {
  interruptCounter++;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(interruptCounter>0) {
    interruptCounter--;
    numberOfInterrupts++;
    Serial.print("An interrupt has occured. Total: ");
    Serial.println(numberOfInterrupts);
  }
}
