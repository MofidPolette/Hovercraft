  #include <SoftwareSerial.h>
  #include <Wire.h>
  #include <OneWire.h>
  #include <DallasTemperature.h>
 
// ----------------------------------------------------------- SENSOR CONNECTION

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
double temp;

// ------------------------------------------------------------ SETUP SECTION

  void setup() {
   Serial.begin(115200);
   Serial.println("Interfacfing Arduino with ESP32");
   swSerial.begin(115200);
#ifdef USE_DS18B20
  temp_sensor.begin();
#endif
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
   Serial.println("<T" + SerialData + ">");
   delay(1500);
   
  }
