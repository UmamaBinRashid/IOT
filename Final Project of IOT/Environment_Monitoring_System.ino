#include <ESP8266WiFi.h>
#include <DHT.h>
#include <ESP8266HTTPClient.h>
const int flameSensorPin = A0;
const int earthquake = D1;
const int alarm = D4;
const int rain = D0;
DHT dht(D5, DHT11);
WiFiClient wifiClient;

String host = "api.thingspeak.com";
int httpPort = 80;
String url1 = "/update?api_key=DX3QCPBGWN2BVUWN&field1=0";
String url2 = "/update?api_key=DX3QCPBGWN2BVUWN&field2=0";
String url3 = "/update?api_key=DX3QCPBGWN2BVUWN&field3=0";
String url4 = "/update?api_key=DX3QCPBGWN2BVUWN&field4=0";
String url5 = "/update?api_key=DX3QCPBGWN2BVUWN&field5=0";
HTTPClient http;

void setup() {
  Serial.begin(9600);
  WiFi.begin("Enter Your USERNAME", "Enter Your PASSWORD");
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  dht.begin();
  pinMode(flameSensorPin, INPUT);
  pinMode(D7,OUTPUT);//Alarm
  pinMode(earthquake,INPUT);
  pinMode(alarm,OUTPUT);
  pinMode(rain,INPUT);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.println("Temperature: " + String(t));
  Serial.println("Humidity: " + String(h));

  url1 = url1 + String(t);
  http.begin(wifiClient, host, httpPort, url1);
  int httpCode = http.GET();
  Serial.println(httpCode);
  delay(2000);

  url2 = url2 + String(h);
  http.begin(wifiClient, host, httpPort, url2);
  httpCode = http.GET();
  Serial.println(httpCode);
  delay(2000);
  //-------------------------------------------------------------------------------------------------------
  int value = analogRead(flameSensorPin); // Read the flame sensor value
   Serial.print("Value of Flame: ");
   Serial.println(value);
  if (value <=100) { // Flame is detected
    digitalWrite(D7, HIGH); // Turn on the Alarm
    Serial.println("Flame detected");
  } else { // Flame is not detected
    digitalWrite(D7, LOW); // Turn off the Alarm
    Serial.println("Flame not detected");
  }
  url3 = url3 + String(value);
  http.begin(wifiClient, host, httpPort, url3);
  httpCode = http.GET();
  Serial.println(httpCode);
  delay(1000); // Delay for stability and to avoid rapid changes
  //-------------------------------------------------------------------------------------------------------
  int earthquake_detection = digitalRead(earthquake);
  Serial.print("EARTHQUAKE VALUE:");
    Serial.println(earthquake_detection);
  if (earthquake_detection == HIGH) {
    digitalWrite(alarm,HIGH);
    Serial.print("Earthquake Detected.....");
  } 
  else {
    Serial.print("Earthquake not Detected.....");
    digitalWrite(alarm,LOW);  
  } 
  url4 = url4 + String(earthquake_detection);
  http.begin(wifiClient, host, httpPort, url4);
  httpCode = http.GET();
  Serial.println(httpCode);
  delay(1000); // Delay for stability and to avoid rapid changes  
  //-------------------------------------------------------------------------------------------------------
  int rainState = digitalRead(rain);
  Serial.print("rainState:");
    Serial.println(rainState);
  if (rainState == 0) {
    digitalWrite(alarm,HIGH);
    Serial.print("Rain Detected.....");
  } 
  else {
    Serial.print("Rain not Detected.....");
    digitalWrite(alarm,LOW); 
  }
   url5 = url5 + String(rainState);
  http.begin(wifiClient, host, httpPort, url5);
  httpCode = http.GET();
  Serial.println(httpCode);
  delay(1000); 
    
}
