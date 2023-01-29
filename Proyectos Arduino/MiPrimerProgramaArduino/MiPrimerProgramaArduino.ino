#include <DHT.h> // importa la Librerias DHT
#include <DHT_U.h>

int SENSOR = 2; // pin DATA de DHT22 a pin digital 2
int TEMPERATURA;
int HUMEDAD;

DHT dht(SENSOR, DHT11); // creacion del objeto, cambiar segundo parametro
        // por DHT11 si se utiliza en lugar del DHT22
void setup(){
  Serial.begin(9600); // inicializacion de monitor serial
  dht.begin(); // inicializacion de sensor
}

void loop(){
  TEMPERATURA = dht.readTemperature(); // obtencion de valor de temperatura
  HUMEDAD = dht.readHumidity(); // obtención de valor de humedad
  Serial.print("Temperatura: "); // escritura en monitor serial de los valores
  Serial.print(TEMPERATURA);
  Serial.print(" Humedad: ");
  Serial.println(HUMEDAD);
  delay (500);
}
