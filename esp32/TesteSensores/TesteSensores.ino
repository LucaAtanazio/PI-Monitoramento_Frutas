#include "DHT.h"

// Definições de Hardware
#define DHTPIN 19       
#define DHTTYPE DHT11
#define MQ3PIN 34      


DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200); 
  delay(1000); 
  
  Serial.println(F("\n===================================="));
  Serial.println(F("     SENSOR DIAGNOSTIC   "));
  Serial.println(F("===================================="));
  
  dht.begin();
  

  analogReadResolution(12);
}

void loop() {

  delay(2000);

  // Leitura DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Leitura MQ3
  int mq3Value = analogRead(MQ3PIN);


  Serial.print(F("[SYS] "));

  if (isnan(h) || isnan(t)) {
    Serial.print(F("DHT11: ERROR | "));
  } else {
    Serial.print(F("Hello World - DHT11 [T: "));
    Serial.print(t);
    Serial.print(F("C, H: "));
    Serial.print(h);
    Serial.print(F("%] | "));
  }

  Serial.print(F("Hello World - MQ3 [Raw: "));
  Serial.print(mq3Value);
  Serial.println(F("]"));
  

  if(mq3Value < 100) {
    Serial.println(F(" >> MQ3 em aquecimento... aguarde 60s."));
  }
}