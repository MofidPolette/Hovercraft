#include <Servo.h>
#include <SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;
Servo monServo;
int positionduServo = 0;

void setup() {
  // put your setup code here, to run once:
  monServo.attach(3);
  monServo.write(positionduServo);
  delay(500);  
}

void loop() {
  Data=BlueT.read();
  
  if (Data=='A'){ 
    // change la position du servomoteur à l'aide d'un slider le slider est 
    // programmé de 25 à ainsi la position "0" correspond à un angle de 81
    positionduServo=BlueT.parseInt(); 
    Serial.println(positionduServo); 
    monServo.write(positionduServo); 
    delay(15);
    Data=BlueT.read();
  }
}
