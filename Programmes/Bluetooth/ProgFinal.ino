//Fait tout fonctionner par bluetooth//

#include <Servo.h>
#include <SoftwareSerial.h>
#include <Stepper.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define USE_DS18B20
#define RX 10
#define TX 11
SoftwareSerial BlueT(RX,TX);
char Data;

Servo monServo;
Servo esc;
Stepper monMoteur(nombrePas, 2, 4, 6, 5);

int positionduServo = 0;
const int nombrePas = 32*64;
int val = 0;

#ifdef USE_DS18B20
  #define ONE_WIRE_BUS 7
  OneWire oneWire(ONE_WIRE_BUS);
  DallasTemperature temp_sensor(&oneWire);
#endif

double temp;

void setup() {
  // put your setup code here, to run once:
  esc.attach(9); // On attache l'ESC au port numérique 9 (port PWM obligatoire)
  delay(15);
  
  Serial.begin(115200);
  delay(15);
  
  Serial.println("Salut, je suis prêt pour l'AT !");
  BlueT.begin(9600);
  delay(500);
  
  Serial.println("Interfacfing Arduino with ESP32");
  delay(15);
  
  monMoteur.setSpeed(10);
  delay(500);
  
  monServo.attach(3);
  monServo.write(positionduServo);
  delay(500);
  
  #ifdef USE_DS18B20
    temp_sensor.begin();
  #endif
  delay(500);
  
}

void loop() {
  #ifdef USE_DS18B20
    temp_sensor.requestTemperatures();  
    temp = temp_sensor.getTempCByIndex(0);
  #endif
  String SerialData;
  SerialData = String(temp,1);
  
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
  Data=BlueT.read();
  }
  
  if (Data == 'U') {
  monMoteur.step(3734);
  delay(500);
  Data=BlueT.read();
  }
  
  
  if (Data=='B'){
    esc.attach(9);
    val = BlueT.parseInt();
    Serial.println(val);
    esc.write(val);
    delay(15);
    Data=BlueT.read();
    }
  

   if (Data == 'T') {
    Serial.println("<Temperature : " + SerialData + ">");
    BlueT.print("*D"+String(SerialData)+"*");
    Data=BlueT.read();
  }
}
