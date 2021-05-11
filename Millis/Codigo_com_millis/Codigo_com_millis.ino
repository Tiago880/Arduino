#define pinLedVd 10
#define pinLedVm 8
#define pinBotao 2

boolean estadoBotao = true;
boolean estado_anterior_Botao = true;
boolean estadoPisca = false;

unsigned long delay1 = 0;

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
      if(millis() - delay1 >= 500){
        digitalWrite(pinLedVm, HIGH);
    }

    if((millis() - delay1 < 500)){
      digitalWrite(pinLedVm, LOW);
      
      }

    if((millis()- delay1) >= 1000 ){
       delay1 = millis();
      }
    
  }else{
    digitalWrite(pinLedVm, LOW);
    }

  
}
