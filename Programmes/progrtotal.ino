#include <Servo.h>
#include <SoftwareSerial.h>
#include <Stepper.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;
Servo monServo;
Servo esc;
int positionduServo = 0;
int anc_pos;
const int nombrePas = 32*64;

Stepper monMoteur(nombrePas, 2, 4, 6, 5);

int val = 0;


void setup() {
  // put your setup code here, to run once:
  esc.attach(9); // On attache l'ESC au port numérique 9 (port PWM obligatoire)
  delay(15);
  Serial.begin(9600);
  delay(15);
  Serial.println("Salut, je suis prêt pour l'AT !");
  BlueT.begin(9600);
  delay(500);
  monMoteur.setSpeed(10);
  delay(500);
  monServo.attach(3);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  if (Data == 'D') {
  monMoteur.step(-3734);
  delay(500);
  }
  
  if (Data == 'U') {
  monMoteur.step(3734);
  delay(500);
  }
  Data=BlueT.read();
    if (Data=='B'){
      val = BlueT.parseInt();
      Serial.println(val);
      esc.write(val);
      delay(15);
      Data=BlueT.read();
    }
}
