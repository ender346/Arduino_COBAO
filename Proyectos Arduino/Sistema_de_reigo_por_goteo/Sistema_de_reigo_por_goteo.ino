#include <LiquidCrystal.h>
#include <DHT.h>

//pins
const int bombaAgua = 0;
const int sensor = 9;
const int boton = 10;

//objects
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
DHT dht(sensor, DHT11);

void setup() {
  lcd.begin(16, 2);

  pinMode(bombaAgua, OUTPUT);
  pinMode(boton, INPUT);
  
  dht.begin();
}

void loop() {
  int temp = dht.readTemperature();
  int hum = dht.readHumidity();
  int estadoBoton = digitalRead(boton);

  lcd.setCursor(0, 0);
  lcd.print("Temperature: " + String(temp) + " °C");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: " + String(hum) + " %");

  if (temp >= 25 && hum <= 20) {
    digitalWrite(bombaAgua, LOW);

    lcd.setCursor(0, 0);
    lcd.print("Watering...");
    lcd.setCursor(0, 1);
    lcd.print("           ");
    delay(500);
  } 
  else if (estadoBoton == HIGH) {
    digitalWrite(bombaAgua, LOW);

    lcd.setCursor(0, 0);
    lcd.print("Watering...");
    lcd.setCursor(0, 1);
    lcd.print("           ");
    delay(1000);
  } 
  else {
    digitalWrite(bombaAgua, HIGH);
  }

  if (temp == 0 && hum == 0) {
    lcd.setCursor(0, 0);
    lcd.print("Error: No sensor");
    lcd.setCursor(0, 1);
    lcd.print("       connected");
    delay(1000);
  }
}
