//Fait fonctionner le moteur pas à pas par bluetooth

#include <Stepper.h>
#include <SoftwareSerial.h>
#define RX 10
#define TX 11
char Data ;
SoftwareSerial BlueT(RX, TX);
const int nombrePas = 32*64;
Stepper monMoteur(nombrePas, 6, 4, 3, 5);

void setup() {
  Serial.begin(9600);
  monMoteur.setSpeed(10);
  delay(500);
  Serial.println("Salut, je suis prêt pour l’AT !");
  BlueT.begin(9600);
  delay(500);
}

void loop() { 
  Data = BlueT.read();
  
  if (Data == 'D') { // correspond à un bouton "down" sur l'application
    monMoteur.step(-3734); //tourne assez pour faire descendre la crémaillère
    delay(1000);
    }
    
  if (Data == 'U') { // correspond à un bouton "up" sur l'application
  monMoteur.step(3734);//tourne assez pour faire monter la crémaillère
  delay(1000);
  }
  
}
