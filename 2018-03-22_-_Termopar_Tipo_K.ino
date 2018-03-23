// www.ladyada.net/learn/sensors/thermocouple
#include <Wire.h>

//#include "max6675.h"
#include <max6675.h>
 
//LCD
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address
 
//Pinos usados no Termopar
int thermoDO = 5;
int thermoCS = 6;
int thermoCLK = 7;
 
//Cria o objeto do Termopar e seta os Pinos Digitais
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
 
//Seta 5 Votls os pinos Digitais
int vccPin = 3;
int gndPin = 2;
 
//Numero de amostras
int amostragem = 10;
 
void setup() {
 
  Serial.begin(9600);
  // usa os Pinos Digitais como Power Pin
  pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
  pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);
 
  // inicializa o lcd de 16 caracters e 2 linhas
  //lcd.begin(16,2);
 
  // ------- Um breve blink de backlight (luz de fundo  -------------
    //liga
    //lcd.backlight();
    //delay(250);
    //desliga
    //lcd.noBacklight();
    //delay(250);
   
    //finaliza com a luz de fundo ligada
    //lcd.backlight();

  //Serial.println("Desenvolvido por Ricardo Cezar Volert."); 
  //Serial.println("Aquisitor de Temperatura Iniciado.");
  //Aguarda o chip MAX6675 estabilizar
  delay(500);
}
 
void loop() { 
   //Variavel que recebera os dados de leitura
   float temperatura = 0;
   
   //Inicia a leituira das amostra
   for(int index =0; index < amostragem; index++){
     temperatura = thermocouple.readCelsius() + temperatura;
     delay(200);
   }
   
   //Tira a media das leituras
   temperatura = temperatura / amostragem;
   
   //Imprime na Serial
   //Serial.print("C = ");
   Serial.println(temperatura);

   //Serial.print("F = ");
   //Serial.println(thermocouple.readFahrenheit());
   
   //Imprime no LCD os dados
   //lcd.setCursor(0,0);
   // Limpa o Display
   //lcd.clear();
   //Escreve
   //lcd.print("Temperatura :");
   //lcd.setCursor(0,1);
   //lcd.print(" ");
   //lcd.print(temperatura);
   //lcd.print(" Celsius");
   delay(10);
}

