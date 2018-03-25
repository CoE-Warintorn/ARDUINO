#define ledPin 13
#define interruptPin  2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), ISRpin2, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, LOW);
  Serial.println("Normal work");
}

void ISRpin2(){
 digitalWrite(ledPin, HIGH);
 for(int i=0; i<100; i++){
  Serial.print(i);
  Serial.println(" Interrupt active");
 }
}

