#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

 LiquidCrystal_I2C lcd(0x27,2,16);

int pin_d = 7;   // Senseur DOUT (digitale)
int pin_a = A2; 

int niveau_senseur = 250;

void setup() {
  // put your setup code here, to run once:
lcd.init(); 
 pinMode(pin_d, INPUT);
  pinMode(pin_a, INPUT);
  Serial.begin(9600);
    lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int valeur_digital = digitalRead(pin_d);
  // Lecture de AOUT du senseur sur l'entree analogique
  int valeur_analogique = analogRead(pin_a);
    Serial.print("DOut : ");
  Serial.print(valeur_digital);
  Serial.print(" Aout : ");
  Serial.println(valeur_analogique);
  if (valeur_analogique > niveau_senseur)
  {
    // Passer en mode alarme (led rouge et buzzer)
 lcd.setCursor(0,0);
      lcd.print("ATTENTION  ");
      delay(1000);
    Serial.write('1');
  }
}
