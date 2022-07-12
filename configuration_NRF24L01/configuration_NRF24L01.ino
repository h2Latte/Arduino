#include <SPI.h>
#include <RF24.h>

#define pinCE   7             // On associe la broche "CE" du NRF24L01 à la sortie digitale D7 de l'arduino
#define pinCSN  8             // On associe la broche "CSN" du NRF24L01 à la sortie digitale D8 de l'arduino
RF24 radio(pinCE, pinCSN);   

void setup() {
  radio.begin();
  radio.setChannel(10); 
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);  
}

void loop() {
  // put your main code here, to run repeatedly:

}
