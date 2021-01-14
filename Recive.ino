#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9,10); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

}
void loop() {
  if (radio.available()) {
    int text[5] ;
    radio.read(&text, sizeof(text));
    Serial.print(text[0]);
    Serial.print(",");
    Serial.print(text[1]);
    Serial.print(",");
    Serial.println(text[2]);
   /* Serial.print(",");
    Serial.print(text[3]);
    Serial.print(",");
    Serial.println(text[4]);*/

 
    
  }
  //Serial.println("B");
}
