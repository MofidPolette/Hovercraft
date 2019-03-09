#include <Servo.h> 
Servo monServo;

float positionduServo = 0;
 

int V_chanel_1 = 0;
int chanel_1 = 14;
int lecture= 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   pinMode(chanel_1, INPUT);
   monServo.attach(3);
   monServo.write(positionduServo);
   delay(15);
   
    
}

void loop() {
// si on dépasse le temps d'attente 3ms, PulsIn renvoit la valeur 0 qu'il ne faut pas prendre en compte

lecture = pulseIn(chanel_1, HIGH, 3000); 
if (lecture >0) {
  V_chanel_1=lecture;
}
delay(10);
Serial.print(" Chanel 1 = ");
Serial.print(V_chanel_1);

 positionduServo = (-0.106*V_chanel_1)+215; //formule 1 : depend quelle est la droite/gauche pour hydro
//positionduServo = (0.106*V_chanel_1)-85; // formule 2 
Serial.print("   positionduServo =  ");
Serial.println(positionduServo);
monServo.write(positionduServo);

}
