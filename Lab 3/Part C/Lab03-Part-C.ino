void setup() {
// initialize both serial ports:
Serial.begin(9600);
Serial.print("-------------------\n");
Serial.print("Hello Arduino Land");
Serial.print("-------------------\n");
pinMode(LED_BUILTIN, OUTPUT);
}

int count = 0;
int ledState = HIGH;
String countString = String(count);

void loop() {
if(ledState == HIGH) {
ledState = LOW;
}
else {
ledState = HIGH;
}
digitalWrite(LED_BUILTIN, ledState);
digitalWrite(LED_BUILTIN, ledState);
//countString = String(count);
Serial.print(count);
if(count % 20 == 0 || count == 0){
  
  Serial.print("\n");
  Serial.print("-------------------------------");
  Serial.print("\n");
}
Serial.print("\n");
count ++;
delay(500);
}
