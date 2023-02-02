#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>

//pines

int bombaAgua = 0;
int sensor = 9;
int boton = 10;

//variables
int temp;
int sensorTemp;
int eatadoBoton;

//objetos
LiquidCrystal lcd(7,6,5,4,3,2);
DHT dht(sensorTemp, DHT11);

void setup() {
  lcd.begin(16, 2);

  pinMode(bombaAgua, OUTPUT);

  dht.begin();

  pinMode(boton, INPUT);
  
}

void loop() {
  int temp = dht.readTemperature();
  int hum = dht.readHumidity();
  int estadoBoton=digitalRead(boton);

  lcd.setCursor(0,0);
  lcd.print("Temperatura" + String(temp) +" °C");
  lcd.setCursor(0,1);
  lcd.print("Humedad: "+ String(hum) +" %    ");

  if(temp>=25&&hum<=20){
     digitalWrite(bombaAgua, LOW);

     lcd.setCursor(0,0);
     lcd.print("*****Regando*****");
     lcd.setCursor(0,1);
     lcd.print("*****************");
     delay(500);
     
  } else if(estadoBoton==HIGH){
    digitalWrite(bombaAgua, LOW);

     lcd.setCursor(0,0);
     lcd.print("*****Regando*****");
     lcd.setCursor(0,1);
     lcd.print("*****************");
     delay(1000);
      
  } else {
    digitalWrite(bombaAgua, HIGH);
  }

  if(temp==0&&hum==0){
    lcd.setCursor(0,0);
    lcd.print("*****ERROR*****");
    lcd.setCursor(0,1);
    lcd.print("***NO SENSOR***");
    delay(1000);
    
  }
}
