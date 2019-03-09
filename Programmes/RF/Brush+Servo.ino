//Fait fonctionner le brushless et le servomoteur par RF//

#include <Servo.h> 
Servo esc;   // Création de l'objet permettant le contrôle de l'ESC 
Servo monServo;
float ESC = 0;
float positionduServo = 0;
 

int V_chanel_1 = 0, V_chanel_2 = 0, V_chanel_3 = 0;
int chanel_1 = 14, chanel_3 = 15; // connecter les pin des voies 1 et 3 de la carte radio aux entrées analogiques 14 et 15
int lecture= 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   pinMode(chanel_1, INPUT);
   pinMode(chanel_3, INPUT);
   esc.attach(9); // On attache l'ESC au port numérique 9 (port PWM obligatoire)
   monServo.attach(3);
   monServo.write(positionduServo);
   delay(15);
   
    
   // Initialisation de l'ESC
   //  (certains ESC ont besoin d'une "procédure d'initialisation"
   //   pour devenir opérationnels - voir notice)
   Serial.println(" Initialisation ESC ");
   esc.write(0);
   delay(1000);
   esc.write(180);
   delay(1000);
   esc.write(0);
   delay(2000);
   Serial.println(" ESC = 40");
   esc.write(40); // nécessaire au démarrage du brushless
   delay(4000);
   Serial.println(" ESC = 45");
   esc.write(45); // on impose une vitesse initiale pour les tests mais non nécessaire 
   delay(2000);   
}

void loop() {
// si on dépasse le temps d'attente 3ms, PulseIn renvoit la valeur 0 qu'il ne faut pas prendre en compte

lecture = pulseIn(chanel_1, HIGH, 3000);  // lecture de l'impulsion envoyée par la voie 1
if (lecture >0) {
  V_chanel_1=lecture;
}
delay(10);
Serial.print(" Chanel 1 = ");
Serial.print(V_chanel_1);

 positionduServo = (-0.106*V_chanel_1)+215; //équation permettant de transformer l'impulsion envoyée en degrés (selon l'intervalle voulu)
Serial.print("   positionduServo =  ");
Serial.println(positionduServo);
monServo.write(positionduServo);

//******************************************
lecture = pulseIn(chanel_3, HIGH, 3000); // lecture de l'impulsion envoyée par la voie 3
if (lecture >0) {
  V_chanel_3=lecture;
}
delay(10);
Serial.print("   Chanel 3 = ");
Serial.print(V_chanel_3);

ESC = (-0.081*V_chanel_3)+180;
Serial.print("   ESC = ");
Serial.println(ESC);



if ((ESC >40)&(ESC<110)){ // mesure de sécurité : on envoie à l'esc que des valeurs comprises entre 40 et 110 pur éviter la surchauffe du moteur
     esc.write(ESC);  }

}
