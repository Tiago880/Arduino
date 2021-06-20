//Programa: Display LCD 16x2 e modulo I2C
//Autor: Arduino e Cia
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LINHA_1 3
#define LINHA_2 4
#define LINHA_3 5
#define LINHA_4 6

#define COLUNA_1 8
#define COLUNA_2 9
#define COLUNA_3 10
#define COLUNA_4 11

//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);

struct TeclaPressionada{
  int linha;
  int coluna;
  char caractere;
};

TeclaPressionada tecla;

void setup()
{
    //Pinos ligados aos pinos 1, 2, 3 e 4 do teclado - Linhas
    pinMode(LINHA_1, OUTPUT);
    pinMode(LINHA_2, OUTPUT);
    pinMode(LINHA_3, OUTPUT);
    pinMode(LINHA_4, OUTPUT);

    //Pinos ligados aos pinos 5, 6, 7 e 8 do teclado - Colunas
    pinMode(COLUNA_1, INPUT);
    pinMode(COLUNA_2, INPUT);
    pinMode(COLUNA_3, INPUT);
    pinMode(COLUNA_4, INPUT);

    Serial.begin(9600);
    Serial.println("Aguardando acionamento das teclas...");
    Serial.println();
    lcd.init();
}

void loop()
{
    lcd.setBacklight(HIGH);
    tecla = le_teclado();

    if(tecla.linha >=0){
      imprime_caractere(tecla.caractere);
      imprime_linha_coluna(tecla.linha,tecla.coluna);
    }    
    delay(10);
}

TeclaPressionada le_teclado()
{
   static int LINHAS[4] = {LINHA_1,LINHA_2,LINHA_3,LINHA_4};
   static int COLUNAS[4] = {COLUNA_1,COLUNA_2,COLUNA_3,COLUNA_4};
   static char teclas[4][4] = {{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}};
   TeclaPressionada tecla;

   tecla.linha = -1;
   tecla.coluna = -1;

   for (int linhaEmTeste = 0; linhaEmTeste<4; linhaEmTeste++)
    {
      for(int colunaEmTeste =0;colunaEmTeste<4; colunaEmTeste++)
      {
        digitalWrite(LINHA_1, LOW);
        digitalWrite(LINHA_2, LOW);
        digitalWrite(LINHA_3, LOW);
        digitalWrite(LINHA_4, LOW);
        digitalWrite(LINHAS[linhaEmTeste], HIGH);
        
        if (digitalRead(COLUNAS[colunaEmTeste]) == HIGH)
        {
          tecla.linha = linhaEmTeste+1;
          tecla.coluna = colunaEmTeste+1;
          tecla.caractere = teclas[linhaEmTeste][colunaEmTeste];
          while(digitalRead(COLUNAS[colunaEmTeste]) == HIGH){}
          return tecla;
        }
      }
    }
    return tecla;
}

void imprime_caractere(char caractere)
{
    lcd.setCursor(13,0);
    lcd.print(caractere);
}

void imprime_linha_coluna(int x, int y)
{
    lcd.setCursor(0,0);
    lcd.print("- Linha : ");
    lcd.print(x);
    lcd.setCursor(0,1);
    lcd.print("| Coluna : ");
    lcd.setCursor(11,1);
    lcd.print(y);
}
