//Fait fonctionner le moteur brushless par Bluetooth

#include <Servo.h>
#include <SoftwareSerial.h>
#define RX 10
#define TX 11
Servo esc;   // Création de l'objet permettant le contrôle de l'ESC
char Data;
SoftwareSerial BlueT(RX,TX);
int val = 0; // 
 
void setup() {
   esc.attach(9); // On attache l'ESC au port numérique 9 (port PWM obligatoire)
   delay(15);
   Serial.begin(9600);
   delay(15);
   Serial.println("Salut, je suis prêt pour l'AT !");
   BlueT.begin(9600);
   delay(500);
 
   // Initialisation de l'ESC
   //  (certains ESC ont besoin d'une "procédure d'initialisation"
   //   pour devenir opérationnels - voir notice)
   esc.write(0);
   delay(1000);
   esc.write(180);
   delay(1000);
   esc.write(0);
 
   // Quelques informations pour l'utilisateur
   Serial.println("Saisir un nombre entre 0 et 179");
   Serial.println("(0 = arret - 179 = vitesse maxi");
   Serial.println(" demarrage a partir de 44)");
   }
 
void loop() {

    Data=BlueT.read();
    if (Data=='M'){ // correspond à un slider sur l'application 
      val = BlueT.parseInt(); // récupère la valeur envoyée par le slider 
      Serial.println(val); // l'affiche sur le moniteur série
      esc.write(val);// l'envoie à l'esc
      delay(15);
      Data=BlueT.read();
    }






      
   }
