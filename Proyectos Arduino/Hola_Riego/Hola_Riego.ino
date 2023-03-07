#include <LiquidCrystal.h>  //Librerias
#include <DHT.h>
#include <DHT_U.h>

//pines

int bombaAgua = 9; //Pines donde van conectados
int sensorTemp = 12;    //DHT11 sin resistencia

//variables
int temp;
int hum;

//objetos
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //Cambio de pines si se altera el circuito
DHT dht(sensorTemp, DHT11);

void setup() {
  lcd.begin(16, 2);  //pantalla

  pinMode(bombaAgua, OUTPUT);// Libreria de la bomba de agua

  dht.begin(); //sensor dht11
  
}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print("Temp:     " + String(temp) +" C");   //lo que aparece en la pantalla
  lcd.setCursor(0,1);
  lcd.print("Humidity: "+ String(hum) +" %   "); //lo que aparece  en la pantalla

  if(temp>=25&&hum<=20){   //si
     digitalWrite(bombaAgua, LOW);

     lcd.setCursor(0,0);
     lcd.print("*****Regando*****");
     lcd.setCursor(0,1);
     lcd.print("*****************");
     delay(500);
     
  }else { //Variable si no
    digitalWrite(bombaAgua, HIGH);
  }

  if(temp==0&&hum==0){  //NO
    lcd.setCursor(0,0);
    lcd.print("*****ERROR*****");
    lcd.setCursor(0,1);
    lcd.print("***NO SENSOR***");
    delay(1000);
    
  }
}
