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
  monMoteur.setSpeed(10);
  delay(500);
  Serial.println("Salut, je suis prêt pour l’AT !");
  BlueT.begin(9600);
  delay(500);
}

void loop() {
  Data = BlueT.read();
   if (Data == 'D') {
  monMoteur.step(-3734);
  delay(500);
  }
  
  if (Data == 'U') {
  monMoteur.step(3734);
  delay(500);
  }
}
