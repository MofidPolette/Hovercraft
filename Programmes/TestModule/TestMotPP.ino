#include <Stepper.h>

const int nombrePas = 32*64;
Stepper monMoteur(nombrePas, 2, 4, 3, 5);

void setup() {
  monMoteur.setSpeed(10);
}

void loop() {
  monMoteur.step(10000);
  delay(5000);

  monMoteur.step(-nombrePas);
  delay(500);
}
