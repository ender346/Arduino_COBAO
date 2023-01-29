#include <LiquidCrystal.h>
#include <DHT.h>
#include <DHT_U.h>

int sensorTemp = 8;
int temp;
int hum;

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
DHT dht(sensorTemp, DHT11);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}
void loop() {
  int temp = dht.readTemperature();
  int hum = dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temp: " + String(temp) +" °C");
  lcd.setCursor(0,1);
  lcd.print("Humedad: "+ String(hum) +" % ");

}
