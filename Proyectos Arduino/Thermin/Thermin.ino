//Thermin
#define LDR 0
#define ZUMBADOR 4

 //por encima de este valor no emite sonido
 #define SILENCIO 800
   //frecuencia maxima de sonido a emitir
 #define F_MAX 1500
     //frecuencia minima  de sonido a emtir
 #define F_MIN 200

 int valor_ldr, frecuencia;
 
void setup() {
}

void loop() {
     //Lectura LDR
   valor_ldr = analogRead(LDR);

   if (valor_ldr <=SILENCIO)
   {
    //Ajustamos el valor leido al rango de frecuencias
    frecuencia = map(valor_ldr, 0, SILENCIO, F_MIN, F_MAX);

          //emtimos el sonido
       tone(ZUMBADOR,frecuencia);
   }
   else
   {
    // si la mano no esta sobre el LDR no se emite sonido
   }
   }
