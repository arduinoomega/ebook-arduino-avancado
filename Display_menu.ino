#include <LiquidCrystal.h>
#include <dht.h>
dht DHT; 
 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
 
int Menu = 0; 
int estado = 0; 

void setup () {

 lcd.begin(16, 2);
 clearPrintTitle();
}
 
void loop () {
 MenuPrincipal();
}
 
void MenuPrincipal() {
 int ValEstado = 0; 
 int x = analogRead (0);
 lcd.setCursor(0,0); 
 
 if (x < 80) {
 } 
 else if (x < 200) {
 ValEstado = 1;
 } 
 else if (x < 400){ 
 ValEstado = 2;
 }
 else if (x < 600){ 
 } 
 else if (x < 800){ 
 ValEstado = 3;
 }
 
 if (Menu < 0 || Menu > 3) {
 Menu = 0; 
 }
 
 if (ValEstado != estado) {
 if (ValEstado == 1) {
 Menu = Menu - 1; 
 displayMenu(Menu);
 } else if (ValEstado == 2) {
 Menu = Menu + 1; 
 displayMenu(Menu);
 } else if (ValEstado == 3) {
 selectMenu(Menu); 
 }
 estado = ValEstado;
 } 
 delay(5);
}
void displayMenu(int x) {
 switch (x) {
 case 1:
 clearPrintTitle();
 lcd.print ("> Temperatura "); 
 break;
 case 2:
 clearPrintTitle();
 lcd.print (">  Umidadade"); 
 break;
 case 3:
 clearPrintTitle();
 lcd.print ("> Temp + Umid"); 
 break;
 
 }
}
 
void clearPrintTitle() {
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("   Selecione: ");
 lcd.setCursor(0,1); 
}
 
void selectMenu(int x) {
 switch (x) {
 case 1:
 clearPrintTitle();

DHT.read11(A8);

    lcd.setCursor(0,0);
    lcd.print("Temp. = ");
    lcd.print(DHT.temperature);
    lcd.write(B11011111); 
    lcd.print("C");

 break;
 
 case 2:
 clearPrintTitle();
     DHT.read11(A8); 
    lcd.setCursor(0,0); // Define o cursor na posição de início
    lcd.print("Umid.= ");
    lcd.print(DHT.humidity);
    lcd.print(" %");
  
 break;

case 3: 

 clearPrintTitle();
 
 DHT.read11(A8);

 lcd.setCursor(0,1);
    lcd.print("Umid. = ");
    lcd.print(DHT.humidity);
    lcd.print(" %");

    lcd.setCursor(0,0); 
    lcd.print("Temp. = ");
    lcd.print(DHT.temperature);
    lcd.write(B11011111); 
    lcd.print("C");
  
 }
}
