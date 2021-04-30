String Ola= "Olá Monitor Serial";


void setup() {
 Serial.begin(9600);
 int a = 2 ;
 int b = 2 ;
 int c = a + b ;
 
 Serial.println(Ola);
 Serial.println(c);

}

void loop() {
  // put your main code here, to run repeatedly:

}
