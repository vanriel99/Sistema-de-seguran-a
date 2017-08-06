#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup ()
   {  
  lcd.begin(16,2); //config do lcd 
 
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(A3, INPUT);  
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT); 
  pinMode(A2, INPUT);  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT); 
  pinMode(A1, INPUT);  
  pinMode (10, OUTPUT);
  pinMode(A0, INPUT); 
  }

 
void loop ()
   {
  // mesagem no lcd 
  if (digitalRead (A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0)==0) lcd.clear();
  lcd.setCursor(4,0);  //posiciona cursor na coluna 4 linha 1 do LCD.
  if (digitalRead (A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0)==0) lcd.print ("OPERANDO");
  lcd.home();
   
  //codigos que acendem os leds 
  digitalWrite(1, digitalRead (A3));
  digitalWrite(1, digitalRead (A3)+ digitalRead(A1)+ digitalRead (A2)+ digitalRead (A0) >=2);   
  digitalWrite(0,!digitalRead (A3));
              
  digitalWrite(6, digitalRead (A2));
  digitalWrite(6, digitalRead (A3)+ digitalRead(A1)+ digitalRead (A2)+ digitalRead (A0)>=2);   
  digitalWrite(7,!digitalRead (A2));
  
  
  digitalWrite(8, digitalRead (A1));
  digitalWrite(8, digitalRead (A3)+ digitalRead(A1)+ digitalRead (A2)+ digitalRead (A0)>=2);     
  digitalWrite(9,!digitalRead (A1));
  
  
  digitalWrite (10, digitalRead(A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0)>=2);
  
  
  if ( digitalRead (A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0)>=1) lcd.clear();
  lcd.setCursor(4,0);  
   if ( digitalRead (A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0)>=1) lcd.print ("ATENCAO");  
     lcd.home();
      for (int x=0; x < 1000; x++) {     // Wait for 1 second
      delay(1);
       }

  if ( digitalRead (A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0)>=1) lcd.clear(); 
  lcd.setCursor(7,0); 
   if ( digitalRead (A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0)>=1) lcd.print ( digitalRead (A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0));
    lcd.home();
  
  lcd.setCursor(4,1);  //posiciona cursor na coluna 4 linha 2 do LCD.
   if ( digitalRead (A3)+ digitalRead (A2)+ digitalRead (A1)+digitalRead (A0)>=1) lcd.print ("PESSOAS");
    lcd.home();
     for (int x=0; x < 1000; x++) {     // Wait for 1 second
      delay(1);
       }
  }
