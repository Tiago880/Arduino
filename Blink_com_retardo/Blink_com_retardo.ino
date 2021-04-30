
#define ledPin 13
int delayPeriod = 50;

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin,OUTPUT);

}

void loop() {
  digitalWrite(ledPin,HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin,LOW);
   delay(delayPeriod);
   delayPeriod +=100;

   if(delayPeriod > 1500){
    delayPeriod = 100;
    }
}
