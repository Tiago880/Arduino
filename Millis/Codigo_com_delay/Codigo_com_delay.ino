#define pinLedVd 10
#define pinLedVm 8
#define pinBotao 2

boolean estadoBotao = true;
boolean estado_anterior_Botao = true;
boolean estadoPisca = false;



void setup() {
pinMode(pinLedVd, OUTPUT);
pinMode(pinLedVm, OUTPUT);
pinMode(pinBotao, INPUT_PULLUP);

digitalWrite(pinLedVd, HIGH);
}

void loop() {
estadoBotao = digitalRead(pinBotao);
if(!estadoBotao && estado_anterior_Botao){
  estadoPisca = !estadoPisca;    
    
  }
  estado_anterior_Botao = estadoBotao;

  if(estadoPisca){
  digitalWrite(pinLedVm, HIGH);
  delay(500);
  digitalWrite(pinLedVm, HIGH);
  }
  delay(10);
  
}
