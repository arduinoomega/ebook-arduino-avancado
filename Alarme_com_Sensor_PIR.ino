int sensor = 2; // O pino do sensor está na porta digital 2
int buzzer = 3; // O buzzer está na porta digital 3
int led = 4 ; // O LED está na porta digital 4

int valorSensor = 0; 

void setup() { 
  
pinMode(sensor,INPUT); // Define o Sensor como entrada
pinMode(buzzer,OUTPUT); // Define o Buzzer como saída
pinMode(led,OUTPUT); // Define o Led como saída 
}

void loop() {  
  
  valorSensor = digitalRead(sensor); // Lendo o Sensor de movimentos 
   
  if (valorSensor == 1) { // Se o sensor detectar movimentos 

    // Alarme Liga

     digitalWrite(led, HIGH); // Liga o LED
     tone(buzzer,1000); // Ativa o Buzzer 
     delay(5000); // tempo de 5 segundos para desligar o Alarme
     
  } else { // Se caso o Alarme não detectar movimentos 

     digitalWrite(led, LOW); // LED fica desligado
     noTone(buzzer); // Buzzer fica desligado
 
  }    
}
