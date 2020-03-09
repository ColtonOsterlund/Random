#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
SoftwareSerial BlueTooth(8, 10); // (TXD, RXD) of HC-06

char BT_input; // to store input character received via BT.
String BT_output;
int lm35Pin = A0;
LiquidCrystal lcd(12,11,5,4,3,2);


void setup()  
{
  Serial.begin(9600);
  analogWrite(6,20);
  lcd.begin(16,2);
  BlueTooth.begin(9600);  
}

void loop() 
{
int analogValue;
int temperature;
analogValue = analogRead(lm35Pin);
temperature = int((float(analogValue) / 1023) * 500);
  
  if (BlueTooth.available())
 
  {
    BT_input=(BlueTooth.read());
    if (BT_input=='a')
    {
      delay(1000);
      char c;
      int index = 0;
      for(int i = 0; i < 2; i++){
        for(int j = 0; j < 16; j++){
          c = BlueTooth.read();
          lcd.setCursor(j,i);
            lcd.print(c);
        }
      }
    }
    else if(BT_input == 'c'){
      BlueTooth.write(temperature);
    }
  }
}
