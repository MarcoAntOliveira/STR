#include <Arduino.h>

#define LED PC13

void setup() {
    pinMode(LED, OUTPUT); 
    Serial.begin(115200);
}

void loop() {
    digitalWrite(LED, LOW);  
    delay(500);                
    digitalWrite(LED, HIGH);  
    delay(500);
    Serial.println("OI");                   
}
