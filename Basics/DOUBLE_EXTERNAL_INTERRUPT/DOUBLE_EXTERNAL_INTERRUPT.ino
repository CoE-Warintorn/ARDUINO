#define ledPin 13
#define interruptPin2  2
#define interruptPin3  3
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin2, INPUT);
  pinMode(interruptPin3, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), ISRpin2, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin3), ISRpin3, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, LOW);
  Serial.println("Normal work");
}

void ISRpin2(){
 digitalWrite(ledPin, HIGH);
 for(int i=0; i<100; i++){
  Serial.print(" Interrupt active pin 2:");
  Serial.println(i);
 }
}

void ISRpin3(){
 digitalWrite(ledPin, HIGH);
 for(int i=0; i<100; i++){
  Serial.print(" Interrupt active pin 3:");
  Serial.println(i);
 }
}

