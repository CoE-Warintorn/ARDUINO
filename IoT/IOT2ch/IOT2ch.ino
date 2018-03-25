#include <ArduinoCloud.h>
#include <ESP8266WiFi.h>

/////// Wifi Settings ///////
String apiKey = "48PQ3BTQEV66B1M2";
char ssid[] = "Xperia XZs_dab2";
char pass[] = "e73c2ca48aed";
const char server[] = "api.thingspeak.com";
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
}

void loop() {
        int h = analogRead(0);
        float fV = map(h,0,1023,0,320)/100.0f;
        bool d = digitalRead(ledPin);
        if (sslClient.connect(server,80)) {
          String postStr = apiKey;
          postStr +="&field1=";
          postStr += String(fV);
          postStr +="&field2=";
          postStr += String(d);
          postStr += "\r\n\r\n";
           
          sslClient.print("POST /update HTTP/1.1\n");
          sslClient.print("Host: api.thingspeak.com\n");
          sslClient.print("Connection: close\n");
          sslClient.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
          sslClient.print("Content-Type: application/x-www-form-urlencoded\n");
          sslClient.print("Content-Length: ");
          sslClient.print(postStr.length());
          sslClient.print("\n\n");
          sslClient.print(postStr);
          Serial.println(postStr);
          }        
        sslClient.stop();
        digitalWrite(ledPin,!digitalRead(ledPin));
        delay(1000);
}
