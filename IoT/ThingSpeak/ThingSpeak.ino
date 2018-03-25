#include <ArduinoCloud.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

/////// Wifi Settings ///////
const char * apiKey = "B39JDE2N8SYUZ0IY";
char ssid[] = "Xperia XZs_dab2";
char pass[] = "e73c2ca48aed";
unsigned long channelID=459200;
const int ledPin=2;

WiFiClient sslClient;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  pinMode(ledPin,OUTPUT);
  while (WiFi.status() != WL_CONNECTED) {
    // unsuccessful, retry in 4 seconds
    Serial.print("failed ... ");    
    Serial.println("retrying ... ");
    delay(1000);
  }  
  ThingSpeak.begin(sslClient);
}

void loop() {
        int h = analogRead(0);
        float fV = map(h,0,1023,0,320)/100.0f;
        int d = digitalRead(ledPin);
        ThingSpeak.setField(1,fV);
        ThingSpeak.setField(2,d);    
        ThingSpeak.writeFields(channelID,  apiKey);
        digitalWrite(ledPin,!digitalRead(ledPin));
        Serial.println(fV);
        delay(5000);
}
