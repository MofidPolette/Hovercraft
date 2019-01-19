// programme test à adapter //
#include <Stepper.h>
int nombredepas = 48*64;
Stepper monmoteur(nombredepas,9,11,10,6);
void setup() {
  // put your setup code here, to run once:
monmoteur.setSpeed(9);
}

void loop() {
  // put your main code here, to run repeatedly:
monmoteur.step(-500);
delay(1000);
monmoteur.step(1000);
}
