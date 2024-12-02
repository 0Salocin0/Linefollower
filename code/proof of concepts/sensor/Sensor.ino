int sensorValue1;
int sensorValue2;
int sensorValue3;
int sensorValue4;
int sensorValue5;
int sensorValue6;
int sensorValue7;
int sensorValue8;

int sensorPin1 = 12;
int sensorPin2 = 14;
int sensorPin3 = 27;
int sensorPin4 = 26;
int sensorPin5 = 25;
int sensorPin6 = 33;
int sensorPin7 = 32;
int sensorPin8 = 35;



void setup() 
{
  Serial.begin(9600);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);  
  pinMode(sensorPin3, INPUT);  
  pinMode(sensorPin4, INPUT);  
  pinMode(sensorPin5, INPUT);  
  pinMode(sensorPin6, INPUT);  
  pinMode(sensorPin7, INPUT);  
  pinMode(sensorPin8, INPUT);  
}

void loop() {
  sensorValue1 = map(analogRead(sensorPin1), 0, 4095, 4095, 0);
  sensorValue2 = map(analogRead(sensorPin2), 0, 4095, 4095, 0);
  sensorValue3 = map(analogRead(sensorPin3), 0, 4095, 4095, 0);
  sensorValue4 = map(analogRead(sensorPin4), 0, 4095, 4095, 0);
  sensorValue5 = map(analogRead(sensorPin5), 0, 4095, 4095, 0);
  sensorValue6 = map(analogRead(sensorPin6), 0, 4095, 4095, 0);
  sensorValue7 = map(analogRead(sensorPin7), 0, 4095, 4095, 0);
  sensorValue8 = map(analogRead(sensorPin8), 0, 4095, 4095, 0);



  Serial.print("Sensorwaarden: ");
  Serial.print(sensorValue1); Serial.print(" ");
  Serial.print(sensorValue2); Serial.print(" ");
  Serial.print(sensorValue3); Serial.print(" ");
  Serial.print(sensorValue4); Serial.print(" ");
  Serial.print(sensorValue5); Serial.print(" ");
  Serial.print(sensorValue6); Serial.print(" ");
  Serial.print(sensorValue7); Serial.print(" ");
  Serial.print(sensorValue8); Serial.println();

  delay(300);
}