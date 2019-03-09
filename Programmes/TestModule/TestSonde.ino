  #include <SoftwareSerial.h>
  #include <Wire.h>
  #include <OneWire.h>
  #include <DallasTemperature.h>
 
// ----------------------------------------------------------- SENSOR CONNECTION

//------------------------------------------------------------ BLUETOOTH

 #define RX 10
 #define TX 11
 SoftwareSerial BlueT(RX,TX);
 char Data;
 
 


// DS18B20 
// Connect blue wire to pin ONE_WIRE_BUS


// ----------------------------------------------------------- SENSOR ACTIVATION SECTION
// comment to desactivate the sensor
  #define USE_DS18B20 // temp 
// ----------------------------------------------------------- SENSOR DEFINITION

#ifdef USE_DS18B20
  #define ONE_WIRE_BUS 4
  OneWire oneWire(ONE_WIRE_BUS);
  DallasTemperature temp_sensor(&oneWire);
#endif 



// ----------------------------------------------------------- GLOBAL VARIABLE DEFINITION
  double temp;
  //SoftwareSerial swSerial(2, 3); // RX, TX 
  //double temp = 15.0;
  //double weight = 43.0;
  //double humidity = 30.0;
  //double pressure = 1.0;
  //double light = 5.0;
  //String SerialData="";

// ------------------------------------------------------------ SETUP SECTION

  void setup() {
   Serial.begin(115200);
   Serial.println("Interfacfing Arduino with ESP32");
   //swSerial.begin(115200);
//#ifdef USE_BH1750   
   //Wire.begin();
   //lightMeter.begin();
//#endif
#ifdef USE_DS18B20
  temp_sensor.begin();
#endif
//#ifdef USE_HX711
  //scale1.set_scale(factor1);
  //scale2.set_scale(factor2);
  //scale3.set_scale(factor3);
  //scale4.set_scale(factor4);
  /*scale1.tare();
  scale2.tare();
  scale3.tare();
  scale4.tare();*/
//#endif

  BlueT.begin(9600);
  delay(500); 
  }

// ------------------------------------------------------------ LOOP SECTION
  void loop() {
    // Data sending by serial
    // start marker <
    // end marker >
    // data type marker T for temp, H for humidity...

#ifdef USE_DS18B20
   temp_sensor.requestTemperatures();  
   temp = temp_sensor.getTempCByIndex(0);
#endif

   String SerialData;
   SerialData = String(temp,1);
   Data = BlueT.read();
   if (Data == 'T') {
    Serial.println("<Temperature : " + SerialData + ">");
    
    BlueT.print("*D"+String(SerialData)+"*");
  }
   
   delay(1500);
   //SerialData = String(weight,1);
   //swSerial.println("<W" + SerialData + ">");
   //Serial.println("<W" + SerialData + ">");
   //delay(1500);
   //SerialData = String(humidity,1);
   //swSerial.println("<H" + SerialData + ">");
   //Serial.println("<H" + SerialData + ">");
   //delay(1500);
   //SerialData = String(pressure,1);
   //swSerial.println("<P" + SerialData + ">");
   //Serial.println("<P" + SerialData + ">");
   //delay(1500);
   //SerialData = String((double)light,1);
   //swSerial.println("<L" + SerialData + ">");
   //Serial.println("<L" + SerialData + ">");
   //delay(1500);
  }
