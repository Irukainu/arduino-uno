#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN 10
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHT22);

LiquidCrystal_I2C lcd(0x27,20,4);
int chk;
float hum;
float temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Papan Informasi");
  lcd.setCursor(2,1);
  lcd.print("  Kualitas Air");
  lcd.setCursor(8,2);
  lcd.print("Oleh");
  lcd.setCursor(2,3);
  lcd.print("   kelompok 7");
  delay(3000);
  lcd.clear();
  
}

void loop() {
 
 hum = dht.readHumidity();
 temp = dht.readTemperature();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Papan Informasi");
  lcd.setCursor(3,1);
  lcd.print("Kualitas Air");
  //suhu
  lcd.setCursor(0,2);
  lcd.print("Suhu       :");
  lcd.setCursor(13,2);
  lcd.print(temp);
  lcd.setCursor(19,2);
  lcd.print("C");
  //ph
  lcd.setCursor(0,3);
  lcd.print("pH         :");
  lcd.setCursor(13,3);
  lcd.print(hum);
  lcd.setCursor(19,3);
  lcd.print("%");
  //delay(500);
  //lcd.clear();
}
