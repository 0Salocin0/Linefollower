#include "BluetoothSerial.h" // Bibliotheek voor Bluetooth-communicatie
BluetoothSerial SerialBT;     // Maak een instantie voor Bluetooth

void setup() 
{
  Serial.begin(9600);              // Start seriële monitor voor debuggen
  SerialBT.begin("ESP32_Test");      // Geef je ESP32 een naam die zichtbaar is op je telefoon
  Serial.println("Bluetooth gestart! Verbinding maken met telefoon mogelijk.");
}

void loop() 
{

  if (Serial.available()) 
    {
     SerialBT.write(Serial.read());     
    }

// Verstuur een bericht via Bluetooth
  if (SerialBT.available()) 
    {
      Serial.write(SerialBT.read()); 
    } 
}