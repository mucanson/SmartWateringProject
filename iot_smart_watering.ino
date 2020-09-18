
#include <DHT.h>
#include "WiFi.h"
#include <FirebaseESP32.h>


#define FIREBASE_HOST "https://iot-smart-watering.firebaseio.com"
#define FIREBASE_AUTH "SJJQ0yBwdnYOmiGRn7i98nvaQp6JaqAN6XBl3IAA"
#define DHTPIN 5  
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE); 


const char* ssid = "UIT Public";
const char* password =  "";

//String path ="/ESP82_Device";

FirebaseData firebaseData;
FirebaseJson json;
String epochTime;
String path;

void setup() {
   Serial.begin(115200); 
   dht.begin(); 

   WiFi.begin(ssid, password);
   
   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   Firebase.reconnectWiFi(true);
   Firebase.setReadTimeout(firebaseData, 1000 * 60);
   Firebase.setwriteSizeLimit(firebaseData, "tiny");

   while (WiFi.status() != WL_CONNECTED) 
   {
    delay(500);
    Serial.println("Connecting to WiFi..");
    }
 
  Serial.println("Connected to the WiFi network");



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
   Firebase.getFloat(firebaseData,"/Humidity", h);          
   Firebase.getFloat(firebaseData,"/Temperature", t);

}
