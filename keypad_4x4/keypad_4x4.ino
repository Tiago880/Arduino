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
    for (int ti = 3; ti<7; ti++)
    {
        //Alterna o estado dos pinos das linhas
        digitalWrite(LINHA_1, LOW);
        digitalWrite(LINHA_2, LOW);
        digitalWrite(LINHA_3, LOW);
        digitalWrite(LINHA_4, LOW);
        digitalWrite(ti, HIGH);
        //Verifica se alguma tecla da coluna 1 foi pressionada
        if (digitalRead(COLUNA_1) == HIGH)
        {
            imprime_linha_coluna(ti-2, 1);
            while(digitalRead(COLUNA_1) == HIGH){}
        }

        //Verifica se alguma tecla da coluna 2 foi pressionada
        if (digitalRead(COLUNA_2) == HIGH)
        {
            imprime_linha_coluna(ti-2, 2);
            while(digitalRead(COLUNA_2) == HIGH){};
        }

        //Verifica se alguma tecla da coluna 3 foi pressionada
        if (digitalRead(COLUNA_3) == HIGH)
        {
            imprime_linha_coluna(ti-2, 3);
            while(digitalRead(COLUNA_3) == HIGH){}
        }

        //Verifica se alguma tecla da coluna 4 foi pressionada
        if (digitalRead(COLUNA_4) == HIGH)
        {
            imprime_linha_coluna(ti-2, 4);
            while(digitalRead(COLUNA_4) == HIGH){}
        }
    }
    delay(10);
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