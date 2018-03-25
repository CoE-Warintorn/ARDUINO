#include <ArduinoCloud.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <Ticker.h>

/////// Wifi Settings ///////
const char * apiKey = "B39JDE2N8SYUZ0IY";
char ssid[] = "Xperia XZs_dab2";
char pass[] = "e73c2ca48aed";
unsigned long channelID=459200;
const int ledPin=2;
const int countPin=0;

WiFiClient sslClient;
Ticker flipper;
bool upDate;
int count;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  pinMode(ledPin,OUTPUT);
  pinMode(countPin,INPUT);
  upDate = false;
  count = 0;
  while (WiFi.status() != WL_CONNECTED) {
    // unsuccessful, retry in 4 seconds
    Serial.print("failed ... ");    
    Serial.println("retrying ... ");
    delay(1000);
  }  
  attachInterrupt(countPin,isrCounting,FALLING);
  ThingSpeak.begin(sslClient);  
  flipper.attach(20, flip);
}
void isrCounting(){
   count = count+1;
}
void flip() {
  upDate = true;  
}

void loop() {
  if(upDate){
        int h = analogRead(0);
        float fV = map(h,0,1023,0,320)/100.0f;
        ThingSpeak.setField(1,fV);
        ThingSpeak.setField(2,count);    
        if(ThingSpeak.writeFields(channelID,  apiKey)==OK_SUCCESS){
          Serial.print("Trig count:");
          Serial.print(count);
          Serial.println(" Update OK");
          count=0;   
        }
        else{
          Serial.println("Update not-OK");
        }
        digitalWrite(ledPin,!digitalRead(ledPin));
        upDate=false;
  }
}
