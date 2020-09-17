#include <Arduino_JSON.h>

#include <FirebaseESP8266.h>
//#include <FirebaseFS.h>
//#include <FirebaseJson.h>

#include <ESP8266WiFi.h>
//#include <FirebaseArduino.h>
#define TRIG_PIN 4
#define ECHO_PIN 5
#define FIREBASE_HOST "iot-smart-watering.firebaseio.com"
#define FIREBASE_AUTH ""  
#define WIFI_SSID "UIT Public"
#define WIFI_PASSWORD ""
FirebaseData firebase;
long duration;
float distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  pinMode (TRIG_PIN, OUTPUT);
  pinMode (ECHO_PIN, INPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration*0.034/2;
  Serial.print("Khoảng cách mực nước: ");
  Serial.print(distance);
  Serial.println(" cm");
  firebase.pulseIn(FirebaseData,"/Khoảng cách",distance);

  delay(500);
  
}
