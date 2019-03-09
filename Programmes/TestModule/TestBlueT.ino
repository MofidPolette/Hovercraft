// test de la connexion bluetooth//
#include<SoftwareSerial.h>
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(500);
  Serial.println("Salut prêt pour commande");
  BlueT.begin(9600);
  delay(500);
}

void loop() { //des commandes comme AT+NAME peuvent être rentrées et le module y répondra 
  // put your main code here, to run repeatedly:
while(BlueT.available()){
  Serial.print(char(BlueT.read()));}
  while(Serial.available()){
    BlueT.write(char(Serial.read()));}

}
