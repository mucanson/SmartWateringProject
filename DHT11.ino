#include "DHT.h"
#define DHTPIN 5  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE); 
void setup() {
   Serial.begin(115200); 
   dht.begin(); 
}
void loop() { 
   delay(2000);
   float t = dht.readTemperature(); 
   if (isnan(t))
       t=-1;
   float h = dht.readHumidity();
   if (isnan(h))
       h=-1;
   Serial.println(""); Serial.print("Temperature: "); Serial.println(t); Serial.print("Humidity: "); Serial.println(h);
}
