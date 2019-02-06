#include <Servo.h>
#include <SoftwareSerial.h>
#define RX 10
#define TX 11
char Data;
int anc_pos;
Servo monServo;
SoftwareSerial BlueT(RX,TX);
int positionduServo = 0;

void setup() {
  // put your setup code here, to run once:
  monServo.attach(3);
  //monServo.write(positionduServo);
  Serial.begin(9600);
  delay(500);
  Serial.println("Salut, je suis prêt pour l'AT !");
  BlueT.begin(9600);
  delay(500);
}

void loop() {

  Data=BlueT.read();
  if (Data=='A'){ 
    // change la position du servomoteur à l'aide d'un slider le slider est 
    // programmé de 25 à ainsi la position "0" correspond à un angle de 81
    
    positionduServo=BlueT.parseInt(); 
      Serial.println(positionduServo); 
      monServo.write(positionduServo); 
      delay(15);
      Data=BlueT.read();
  }

  
  anc_pos=positionduServo; // récupère l'ancienne position du servo
  Data=BlueT.read();
  if(Data=='d'){
    // change la position du servomoteur à l'aide d'un bouton, le bouton est 
    // programmé pour aller de l'ancienne position à un angle de 35
    // permettant au bateau de tourner à droite
  
    for(positionduServo = anc_pos; positionduServo >= 35; positionduServo--){
      Serial.println(positionduServo);
      monServo.write(positionduServo);
      delay(15);}
    Data=BlueT.read();
  }


  
  anc_pos=positionduServo;
  Data=BlueT.read();
  if(Data=='B'){
    // change la position du servomoteur à l'aide d'un bouton, le bouton est 
    // programmé pour aller de l'ancienne position à un angle de 81
    // permettant au bateau de continuer à avancer tout droit
    // ce bouton permet de continuer tout droit lorsque précedemment
    // le bateau était en train de tourner à droite
    
    for(positionduServo = anc_pos; positionduServo <= 81; positionduServo++){
      Serial.println(positionduServo);
      monServo.write(positionduServo);
      delay(15);}
    Data=BlueT.read();
  }

  
    anc_pos=positionduServo;
  Data=BlueT.read();
  if(Data=='G'){
    // change la position du servomoteur à l'aide d'un bouton, le bouton est 
    // programmé pour aller de l'ancienne position à un angle de 126
    // permettant au bateau de tourner à gauche
    
    for(positionduServo = anc_pos; positionduServo <=126; positionduServo++){
      Serial.println(positionduServo);
      monServo.write(positionduServo);
      delay(15);}
    Data=BlueT.read();
  }


  
  anc_pos=positionduServo;
  Data=BlueT.read();
  if(Data=='R'){
    // change la position du servomoteur à l'aide d'un bouton, le bouton est 
    // programmé pour aller de l'ancienne position à un angle de 81
    // permettant au bateau de continuer à avancer tout droit
    // ce bouton permet de continuer tout droit lorsque précedemment
    // le bateau était en train de tourner à gauche
    
    for(positionduServo = anc_pos; positionduServo >= 81; positionduServo--){
      Serial.println(positionduServo);
      monServo.write(positionduServo);
      delay(15);}
    Data=BlueT.read();
  }
 }
 
