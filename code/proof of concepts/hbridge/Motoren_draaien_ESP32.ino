int Led = 2; 
int Motor1 = 19; // Dat is de rechte motor gekeken vanuit de microcontroller
int Motor2 = 5; // Dat is de linker motor gekeken vanuit de microcontroller
int PosMotor1 = 18; 
int NegMotor1 = 4; 
int PosMotor2 = 23; 
int NegMotor2 =  22; 
int richting = -1; // Verander richting (1 = vooruit, -1 = achteruit)
unsigned long vorigeTijd = 0;  // Variabele om de tijd bij te houden
const long interval = 20;  // Verander de snelheid elke 50 milliseconden (pas aan voor trager of sneller)
int snelheid = 0; 


void setup() 
{
Serial.begin(9600); // Start de seriële communicatie
pinMode(Motor1, OUTPUT); 
pinMode(Motor2, OUTPUT); 
pinMode(PosMotor1, OUTPUT); 
pinMode(NegMotor1, OUTPUT); 
pinMode(PosMotor2, OUTPUT); 
pinMode(NegMotor2, OUTPUT);
pinMode(Led, OUTPUT);
}
void writeToMultiplePins(int value, int pin1, int pin2) 
{
  analogWrite(pin1, constrain(value, 0, 255)); // Zorg ervoor dat waarde tussen 0-255 blijft
  analogWrite(pin2, constrain(value, 0, 255));
}
 
void loop() 
{
unsigned long huidigeTijd = millis(); // Haal de huidige tijd op 
if (huidigeTijd - vorigeTijd >= interval)
{
  vorigeTijd = huidigeTijd; // Update de tijd voor de volgende stap
  switch (richting) 
  {
    case -1: // Vooruit
      digitalWrite(Motor1, HIGH);
      digitalWrite(Motor2, LOW); 
      richting = 0; 
    break;

    case -2: // Achteruit
      digitalWrite(Motor1, LOW); 
      digitalWrite(Motor2, HIGH); 
      richting = 0;
    break;

    case 0: // Rechter motor naar voren
      snelheid++;  
        writeToMultiplePins(snelheid, PosMotor1, PosMotor2);  
        writeToMultiplePins(0, NegMotor1, NegMotor2); 
        Serial.println(snelheid);
        digitalWrite(Led, HIGH); 
        if (snelheid >= 255) // Als maximale snelheid bereikt is
        {  
          richting = 1;  
        }
    break;

    case 1: // Rechter motor langzaam stoppen 
      snelheid--;  
      writeToMultiplePins(snelheid, PosMotor1, PosMotor2);  
      writeToMultiplePins(0, NegMotor1, NegMotor2);
      Serial.println(snelheid); 
        digitalWrite(Led, LOW); 
      if (snelheid <= 0) // Als snelheid 0 is
      {
        richting = 2;  
      }
    break;

    case 2: // Rechter motor achteruit
      snelheid++; // Snelheid verhogen (achteruit)
      writeToMultiplePins(0, PosMotor1, PosMotor2);  
      writeToMultiplePins(snelheid, NegMotor1, NegMotor2);
      Serial.println(snelheid); 
        digitalWrite(Led, HIGH); 
      if (snelheid >= 255)
      {
        richting = 3; // Maximaal achterwaarts snelheid bereikt
      }
    break;

    case 3: // Rechter motor terug naar stilstand (achteruit)
      snelheid--; // Snelheid verlagen
      writeToMultiplePins(0, PosMotor1, PosMotor2);  
      writeToMultiplePins(snelheid, NegMotor1, NegMotor2);
      Serial.println(snelheid);
        digitalWrite(Led, LOW); 
      if (snelheid <= 0)
      {
        if (digitalRead(Motor2) == HIGH) // Je had hier 'rechtsmotor', maar dat is niet gedefinieerd
        {
          richting = -1; 
        }
        else 
        {
          richting = -2; 
        }
      }
    break;
  }
}
}