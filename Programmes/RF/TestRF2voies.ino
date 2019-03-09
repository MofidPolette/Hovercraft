int val1 = 0, val2 = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(14, INPUT);
pinMode(15, INPUT);
Serial.println("Test voies 1 et 3");
delay(15);
Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
val1=pulseIn(14, HIGH, 3000);
delay(10);
val2=pulseIn(15, HIGH, 3000);
delay(10);

Serial.print(" Chanel 1 = ");
Serial.print(val1);
Serial.print("    Chanel 3 = ");
Serial.print(val2);



}
