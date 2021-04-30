
#define ledPin 13
#define delayPeriod 100
#define Pausa 3000
int count = 0;

void setup() {
  pinMode(ledPin,OUTPUT);

}

void loop() {


digitalWrite(ledPin,HIGH);
delay(delayPeriod);
digitalWrite(ledPin,LOW);
delay(delayPeriod);
count ++;

    if(count == 20 ){
    count = 0;
    delay(Pausa);

  }
}

// LOOP DO MESMO PROGRAMA USANDO COMANDO DE REPETIÇÃO FOR
//void loop() {
//  int repetir = 20;
//  int contador = 0;
//  for(contador ; contador < repetir ; contador ++){
//    digitalWrite(ledPin,HIGH);
//    delay(delayPeriod);
//    digitalWrite(ledPin,LOW);
//    delay(delayPeriod);
//    
//    }
//
//    if(contador >= 19 ){
//    delay(Pausa);
//
//  }
//}
