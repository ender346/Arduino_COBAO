int LEDROJO = 9;    // pin 9 a anodo LED rojo
int LEDVERDE = 10;    // pin 10 a anodo LED verde
int LEDAZUL = 11;   // pin 11 a anodo LED azul

void setup(){
  pinMode(LEDROJO, OUTPUT); // todos los pines como salida
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
}

void loop(){
  analogWrite(LEDROJO, 255);  // rojo
  analogWrite(LEDVERDE, 0);
  analogWrite(LEDAZUL, 0);
  delay(2000);      // demora de 2 seg.

  analogWrite(LEDROJO, 0);  // verde
  analogWrite(LEDVERDE, 255);
  analogWrite(LEDAZUL, 0);
  delay(2000);      // demora de 2 seg.

  analogWrite(LEDROJO, 0);  // azul
  analogWrite(LEDVERDE, 0);
  analogWrite(LEDAZUL, 255);
  delay(2000);      // demora de 2 seg.
  
}