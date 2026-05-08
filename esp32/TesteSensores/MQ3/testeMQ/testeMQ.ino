#define MQ3PIN 34 

void setup() {
  Serial.begin(115200);
  Serial.println(F("[DIAGNOSTIC] Testing MQ-3 Gas Sensor..."));
  

  analogReadResolution(12);
}

void loop() {
  int rawValue = analogRead(MQ3PIN);
  

  float voltage = (rawValue / 4095.0) * 3.3;

  Serial.print(F("MQ-3 Raw Value: "));
  Serial.print(rawValue);
  Serial.print(F(" | Voltage: "));
  Serial.print(voltage);
  Serial.println(F("V"));


  if (rawValue > 3000) {
    Serial.println(F(">> ALERT: High Gas Concentration Detected!"));
  }

  delay(500); 
}