#include <LiquidCrystal.h> //Incluindo biblioteca 
  
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
  
void setup (){  
 lcd.begin(16,2); 
 lcd.setCursor(0,0);
 lcd.print("Apertou a Tecla:"); 
}  

void loop (){  

 lcd.setCursor(0,1);

 if ((analogRead(0)) < 80) {  // Se a leitura for menor que 80
  lcd.print ("    Direita    "); // escreve na tela 
 }  

 else if ((analogRead(0)) < 200) { // Se a leitura for menor que 200
  lcd.print ("      Cima     ");  // escreve na tela 
 }  

 else if ((analogRead(0)) < 400){   // Se a leitura for menor que 400
  lcd.print ("     Baixo     ");  // escreve na tela 
 }  
 else if ((analogRead(0)) < 600){  // Se a leitura for menor que 600
  lcd.print ("    Esquerda   "); // escreve na tela 
 }  
 else if ((analogRead(0)) < 800){  // Se a leitura for menor que 800
  lcd.print ("     Select   "); // escreve na tela 
 }  
}
