const int ledVermelho = 13;  // Pino do LED vermelho
const int ledVerde = 2;      // Pino do LED verde
const int buzzerPin = 3;     // Pino onde o buzzer está conectado

char command;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.println("Arduino");
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    
    switch (command) {
      case '1':
        digitalWrite(ledVermelho, HIGH);  // Acende o LED vermelho
        digitalWrite(ledVerde, LOW);      // Apaga o LED verde
        tone(buzzerPin, 200, 500);        // Emite um som grave (200 Hz) por 500 ms
        break;
        
      case '0':
        digitalWrite(ledVermelho, LOW);   // Apaga o LED vermelho
        digitalWrite(ledVerde, HIGH);     // Acende o LED verde
        tone(buzzerPin, 2000, 500);       // Emite um som agudo (2000 Hz) por 500 ms
        break;
        
      case '2':
        digitalWrite(ledVermelho, LOW);   // Apaga o LED vermelho
        digitalWrite(ledVerde, LOW);      // Apaga o LED verde
        tone(buzzerPin, 1000, 500);       // Emite um som intermediário (1000 Hz) por 500 ms
        break;
        
      case 'R':
        tone(buzzerPin, 200, 500);        // Emite um som grave (200 Hz) por 500 ms para o som vermelho
        break;
        
      case 'V':
        tone(buzzerPin, 2000, 500);       // Emite um som agudo (2000 Hz) por 500 ms para o som verde
        break;
        
      case 'S':
        tone(buzzerPin, 1500, 500);       // Emite um som intermediário (1500 Hz) por 500 ms para o som de apagar
        break;
    }
  }
}