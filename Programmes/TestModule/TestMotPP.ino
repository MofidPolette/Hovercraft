#include <Stepper.h>

const int nombrePas = 32*64;//dfifférent selon les modèles
Stepper monMoteur(nombrePas, 2, 4, 3, 5);//faire attention à l'ordre des pin : (IN1, IN3, IN2, IN4)

void setup() {
  monMoteur.setSpeed(10);
}

void loop() { //fait des mouvements dans les 2 sens
  monMoteur.step(10000);
  delay(5000);

  monMoteur.step(-nombrePas);
  delay(500);
}
