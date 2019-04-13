/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

// include the library code:
#include <LiquidCrystal.h>
#include <dht.h>
#include <Servo.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

dht DHT;
#define DHT21_PIN 6     // DHT 22  (AM2302) - what pin we're connected to

Servo servoAgua;
#define servo 9

//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value

void mostrarHumTemp(){
    //no se que hace read21 pero esta ahi
  int chk = DHT.read21(DHT21_PIN);
    //Read data and store it to variables hum and temp
    hum = DHT.humidity;
    temp= DHT.temperature;
     // set the cursor to column 0, line 1
     // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 0);
    lcd.print("Hum: ");
    lcd.print(hum);
     lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.println("C");
    delay(2000); //Delay 2 sec.
  }
 void activarRiego(){
  if (hum < 55){
    servoAgua.write(45);
     delay(1000);
  }else{ 
    servoAgua.write(180);
      delay(1000);}
  }
void setup() {
  lcd.begin(16, 2);
  servoAgua.attach(servo);
  servoAgua.write(45);
  delay(1000);
}

void loop() {
 
  mostrarHumTemp();
  activarRiego();
  
}
