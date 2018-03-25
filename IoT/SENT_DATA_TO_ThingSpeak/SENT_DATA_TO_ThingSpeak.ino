#include <ArduinoCloud.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include "DHTesp.h"

/////// Wifi Settings ///////
const char * apiKey = "B39JDE2N8SYUZ0IY";
char ssid[] = "Xperia XZs_dab2";
char pass[] = "e73c2ca48aed";
unsigned long channelID=459200;

WiFiClient sslClient;

/////// Sensor ///////
DHTesp dht;

void setup()
{
  Serial.begin(115200);
  
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    // unsuccessful, retry in 4 seconds
    Serial.print("failed ... ");    
    Serial.println("retrying ... ");
    delay(1000);
  }  
  ThingSpeak.begin(sslClient);
  
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");

  dht.setup(2); // Connect DHT sensor to GPIO 17
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  ThingSpeak.setField(3,humidity);
  ThingSpeak.setField(4,temperature);  
  if( ThingSpeak.writeFields(channelID,  apiKey) == OK_SUCCESS ) {
    Serial.print(dht.getStatusString());
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    Serial.print(dht.toFahrenheit(temperature), 1);
    Serial.print("\t\t");
    Serial.print(dht.computeHeatIndex(temperature, humidity, false), 1);
    Serial.print("\t\t");
    Serial.println(dht.computeHeatIndex(dht.toFahrenheit(temperature), humidity, true), 1);
  }
  else {
    Serial.println("Time out");
  }
  
}

