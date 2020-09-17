#include <DHT.h> // Gọi thư viện DHT22
 
const int DHTPIN = A0; //Đọc dữ liệu từ DHT22 ở chân A0 trên mạch Arduino
const int DHTTYPE = DHT22; //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22

const char* ssid = "UIT Public";
const char* password = "";
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup()
{
    Serial.begin(9600);
    dht.begin(); // Khởi động cảm biến
}
 
void loop()
{
    float h = dht.readHumidity(); //Đọc độ ẩm
    float t = dht.readTemperature(); //Đọc nhiệt độ
 
    Serial.println("Arduino.vn");
    Serial.print("Nhiet do: ");
    Serial.println(t); //Xuất nhiệt độ
    Serial.print("Do am: ");
    Serial.println(h); //Xuất độ ẩm
 
    Serial.println(); //Xuống hàng
}
