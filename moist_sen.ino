
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define SensorPin A0 
#define FIREBASE_HOST "https://iot-smart-watering.firebaseio.com"
#define FIREBASE_AUTH "SJJQ0yBwdnYOmiGRn7i98nvaQp6JaqAN6XBl3IAA"


// WiFi
const char* ssid = "UIT Public";
const char* wifi_password = "";


float m = 0; 


void setup() { 
 Serial.begin(9600); 
 WiFi.begin(ssid, wifi_password);
 
 while (WiFi.status() != WL_CONNECTED) 
   {
    delay(500);
    Serial.println("Connecting to WiFi..");
    }
 
  Serial.println("Connected to the WiFi network");

  FirebaseData firebaseData;

   Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   Firebase.reconnectWiFi(true);
   Firebase.setReadTimeout(firebaseData, 1000 * 60);
   Firebase.setwriteSizeLimit(firebaseData, "tiny");
 
} 


void loop() { 
 for (int i = 0; i <= 100; i++) 
 { 
   m = m + analogRead(SensorPin); 
   delay(1); 
 } 
 m = m/100.0; 
 Serial.println(m); 
 delay(30); 
   FirebaseData firebaseData;

 Firebase.pushFloat(firebaseData,"/SoilMoisture", m);     
} 
