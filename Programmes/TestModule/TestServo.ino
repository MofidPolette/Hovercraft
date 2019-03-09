//le servomoteur effectue une rotation de 0° à 180° puis de 180° à 0°//
#include <Servo.h>
Servo monServo;
int positionduServo = 0;

void setup() {
  // put your setup code here, to run once:
  monServo.attach(3);
  monServo.write(positionduServo);
}

void loop() {
 // // put your main code here, to run repeatedly:
 for(positionduServo = 0; positionduServo <= 40; positionduServo++){
  monServo.write(positionduServo);
  delay(15);}
  delay(1000);
  
  for(positionduServo = 40; positionduServo <= 80; positionduServo++){
  monServo.write(positionduServo);
  delay(15);}
  delay(1000);
  
  for(positionduServo = 80; positionduServo >=45; positionduServo--){
  monServo.write(positionduServo);
  delay(15);}
  delay(1000);
  
  for(positionduServo = 45; positionduServo >0; positionduServo--){
  monServo.write(positionduServo);
  delay(15);}
  delay(1000);
 }
 
