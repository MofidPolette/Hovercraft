//Test du moteur pas à pas avec le bluetooth//


#include <Stepper.h>
#include <SoftwareSerial.h>
#define RX 10
#define TX 11
char Data ;
SoftwareSerial BlueT(RX, TX);
const int nombrePas = 32*64; //dfifférent selon les modèles
Stepper monMoteur(nombrePas, 2, 4, 3, 5); //faire attention à l'ordre des pin : (IN1, IN3, IN2, IN4)

void setup() {
  Serial.begin(9600);
  monMoteur.setSpeed(5);
  delay(500);
}

void loop() { //fait des mouvements dans les 2 sens
  monMoteur.step(-100); 
  delay(500);
  monMoteur.step(100);
}
