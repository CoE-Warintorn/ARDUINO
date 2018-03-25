int iCount;
int iMode;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(iCount=8; iCount<=11; iCount++){
    pinMode(iCount, OUTPUT);
    digitalWrite(iCount, HIGH);
  }
    
  iCount = 8;
  iMode = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("iMode = ");
  Serial.print(iMode);
  Serial.print(" iCount = ");
  Serial.println(iCount);
  if(iMode<100){
    digitalWrite(iCount, LOW);
    digitalWrite((iCount - 1 < 8)? 11:iCount - 1 , HIGH);
    iCount = (iCount == 11)? 8 : iCount + 1;
    delay(100);
  }
  else{
    for(int i=8; i<12; i++)
      digitalWrite(i, (iMode%2)?LOW:HIGH);
    delay(30);
  }
  iMode = (iMode == 200)?0:iMode+1;
}
