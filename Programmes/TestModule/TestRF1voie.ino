int val1 = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
val1=pulseIn(6, HIGH, 3000);
if (val1 >0) {
Serial.print(" Chanel 1 = ");
Serial.println(val1);
}
delay(1);
}
