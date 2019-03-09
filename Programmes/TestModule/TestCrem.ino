#include <Stepper.h>
#include <SoftwareSerial.h>
#define RX 10
#define TX 11
char Data ;
SoftwareSerial BlueT(RX, TX);
const int nombrePas = 32*64;
Stepper monMoteur(nombrePas, 2, 4, 3, 5);

void setup() {
  Serial.begin(9600);
  monMoteur.setSpeed(5);
  delay(500);
}

void loop() {
  monMoteur.step(-100);
  delay(500);
  monMoteur.step(100);
}
