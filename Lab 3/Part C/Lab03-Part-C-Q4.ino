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
// Ascii art was created seperately and put into an array to randomly draw out and index
String ascii1 =  
" /\\ /\\ \n" 
"((ovo)) \n"
"():::() \n"
  "  VVV \n";

String ascii2 =
"  ______\n"
" /|_||_\`.__\n"
"(   _    _ _\\\n"
"`-(_)--(_)-'\n";

String ascii3 = 
"  /~\\\n"
" C oo\n"
" _( ^)\n"
"/   ~\\\n";

String ascii4 =
"            _____ \n"
"         .-'.  ':'-. \n"
"       .''::: .:    '. \n"
"      /   :::::'      \ \n"
"     ;.    ':' `       ; \n"
"     |       '..       | \n"
"     ; '      ::::.    ; \n"
"      \       '::::   / \n"
"       '.      :::  .' \n"
"jgs      '-.___'_.-' \n";

String ascii5 =
"   __.-._ \n"
"   '-._"7' \n"
"    /'.-c \n"
"    |  /T \n"
"snd_)_/LI \n";

String asciis[5] = {ascii1, ascii2, ascii3, ascii4, ascii5};

void loop() {
// Code that was left from the provided code just to have it here
if(ledState == HIGH) {
ledState = LOW;
}
else {
ledState = HIGH;
}
digitalWrite(LED_BUILTIN, ledState);
digitalWrite(LED_BUILTIN, ledState);

// create random number from 0-5 to grab random ascii from array to print
int random = (rand() & (6 - 0 + 1)) + 0;
Serial.print(asciis[random]);
Serial.print("\n");

delay(500);
}