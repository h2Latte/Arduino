#include <SPI.h>
#include <RF24.h>
#include "DHT.h"

// LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

// RF24
#define pinCE   7             // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN  8             // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
RF24 radio(pinCE, pinCSN);   

// DHT 
#define DHTPIN 37
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  lcd.begin(16, 2);
  
  radio.begin();
  radio.setChannel(10); 
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);  
}

void loop() {
  dhtLoop();
}

void dhtLoop() {
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  lcd.setCursor(0, 1);
  lcd.print(h);
  lcd.setCursor(5, 1);
  lcd.print("%");
  lcd.setCursor(0,0);
  lcd.print(t);
  lcd.setCursor(5,0);
  lcd.print("C");
  
  Serial.print(F("Heat index: "));
  Serial.print(hic);
  Serial.println(F("°C "));
  Serial.println("");
}
