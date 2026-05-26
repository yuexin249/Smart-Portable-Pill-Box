#include <ESP32Servo.h>

#define PIN_SERVO 23             
Servo servo;

void setup() {
  servo.setPeriodHertz(50);
  servo.attach(PIN_SERVO, 500, 2500); 
  servo.write(90);  
}

void loop() {
 
  servo.write(0);   
  delay(10000);     
  
  servo.write(180); 
  delay(10000);     
}