#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
//connection in bettwen receiver and transmitter
static const int RXPin = 9, TXPin = 10;
static const uint32_t GPSBaud = 9600;

// using tiny gps library . This library helps to filter the data provided by gps sensor
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
 
     lcd.begin(16,2);
     lcd.print("Bus"); // Prints "Arduino" on the LCD 
 
     delay(1000); // 3 seconds delay 
     lcd.setCursor(2,2); // Sets the location at which subsequent text written to the LCD will be displayed 
     lcd.print("Location =^ ^="); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
      delay(1000); // 3 seconds delay 
      lcd.clear();
      
      
      
      Serial.begin(9600);
      ss.begin(GPSBaud);
}

void loop(){
 
    
   
  while (ss.available() > 0){
      
     
    gps.encode(ss.read());
    if (gps.location.isUpdated()){   //checks gps connection
          
     
     Serial.print("Latitude= "); 
     Serial.print(gps.location.lat(), 6); 

    
     Serial.print(" Longitude= "); 
     Serial.println(gps.location.lng(), 6);
      
      
    
      
     
     lcd.setCursor(0,0);
     lcd.print("  Location");
    
     
     lcd.print(" Lat="); 
     lcd.print(gps.location.lat(), 2);  //gets latitide data and prints in lcd
       
         
     lcd.print("Lng="); 
     lcd.print(gps.location.lng(), 2); //Gets longitude data and prints in lcd
     delay(1000); // 1 seconds delay 
    



    }
    
    
  }
   

 
}
