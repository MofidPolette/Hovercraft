#include <Servo.h> 
Servo esc;   // Création de l'objet permettant le contrôle de l'ESC 
float ESC = 0;
 

int V_chanel_3 = 0;
int chanel_3 = 15;
int lecture= 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   pinMode(chanel_3, INPUT);
   esc.attach(9); // On attache l'ESC au port numérique 9 (port PWM obligatoire)
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
   esc.write(40);            // 
   delay(4000);
   Serial.println(" ESC = 45");
   esc.write(45);            // 
   delay(2000);   
}

void loop() {
// si on dépasse le temps d'attente 3ms, PulseIn renvoit la valeur 0 qu'il ne faut pas prendre en compte

lecture = pulseIn(chanel_3, HIGH, 3000);
if (lecture >0) {
  V_chanel_3=lecture;
}
delay(10);
Serial.print("   Chanel 3 = ");
Serial.print(V_chanel_3);

ESC = (-0.081*V_chanel_3)+180;
Serial.print("   ESC = ");
Serial.println(ESC);



if ((ESC >40)&(ESC<110)){
     esc.write(ESC);  }

}
