int sensorA = A9; // Pino analógico do sensor na porta A9
int sensorD = 4; // Pino digital do sensor na porta Digital 4
int buzzer = 3; // Buzzer na porta 3
int led = 2; // LED na porta 2

int analogico;
int digital;

void setup() {
 // Definindo componentes como entradas ou saída
 
 pinMode(sensorA, INPUT);
 pinMode(sensorD, INPUT);
 pinMode(led, OUTPUT); 
 pinMode(buzzer, OUTPUT); 
}
void loop() {

 digital = digitalRead(sensorD); // lendo pino digital do sensor 
 analogico = analogRead(sensorA); // lendo pino analógico do sensor
 
 if (digital == 0){ // Se o Sensor detectar fumaça ou gás
  
  digitalWrite(buzzer, HIGH); // Buzzer emite som
  digitalWrite(led, HIGH); //  LED acende 
 
 }else{ // Se não 

  digitalWrite(buzzer, LOW); // Buzzer permanece desligado
  digitalWrite(led, LOW); // LED permanece desligado 
  delay(500);
 }
}
