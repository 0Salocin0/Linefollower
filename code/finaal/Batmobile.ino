#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

// Motor pinnen
int motorA = 19; 
int motorB = 5; 
int motorA_IN1 = 18;
int motorA_IN2 = 4;
int motorB_IN1 = 23;
int motorB_IN2 = 22;

// Sensor pinnen (8 sensoren)
const int sensorPins[8] = {12, 14, 27, 26, 25, 33, 32, 35};
int LedOn = 13; 

// PID parameters
float Kp = 50;
float Ki = 0;
float Kd = 20;
float integral = 0;
float lastError = 0;

// Motor snelheidsinstellingen
int baseSpeed = 50;
int maxSpeed = 90;
int leftMotorSpeed;
int rightMotorSpeed;

// Sensorwaarden en gewichten
int sensorValues[8];
int weights[8] = {-6, -5, -4, -3, 3, 4, 5, 6};

void setup() {
  Serial.begin(115200);
  SerialBT.begin("LineNico"); // Bluetooth naam
  Serial.println("Bluetooth gestart. Wacht op verbinding...");

  pinMode(motorA_IN1, OUTPUT);
  pinMode(motorA_IN2, OUTPUT);
  pinMode(motorB_IN1, OUTPUT);
  pinMode(motorB_IN2, OUTPUT);
  pinMode(motorA, OUTPUT); 
  pinMode(motorB, OUTPUT); 
  pinMode(LedOn, OUTPUT); 

  for (int i = 0; i < 8; i++) {
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  digitalWrite(motorA, HIGH); 
  digitalWrite(motorB, HIGH); 
  digitalWrite(LedOn, HIGH); 
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n');
    processCommand(command);
  }

  // Lees de sensoren en bepaal de fout
  int totalWeight = 0;
  int totalActive = 0;

  for (int i = 0; i < 8; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
    if (sensorValues[i] > 512) { // Drempelwaarde voor lijn detectie
      totalWeight += weights[i] * sensorValues[i];
      totalActive += sensorValues[i];
    }
  }

  int error = (totalActive > 0) ? totalWeight / totalActive : 0;

  // PID berekening
  integral += error;
  float derivative = error - lastError;
  float pidOutput = Kp * error + Ki * integral + Kd * derivative;

  // Stel motor snelheden in
  leftMotorSpeed = baseSpeed - pidOutput;
  rightMotorSpeed = baseSpeed + pidOutput;

  leftMotorSpeed = constrain(leftMotorSpeed, 0, maxSpeed);
  rightMotorSpeed = constrain(rightMotorSpeed, 0, maxSpeed);

  // Motoren aansturen
  analogWrite(motorA_IN1, leftMotorSpeed);
  digitalWrite(motorA_IN2, LOW);
  analogWrite(motorB_IN1, rightMotorSpeed);
  digitalWrite(motorB_IN2, LOW);

  lastError = error;
  delay(5);
}

void processCommand(String command) {
  if (command.startsWith("Kp")) {
    Kp = command.substring(2).toFloat();
    SerialBT.println("Kp set to: " + String(Kp));
    Serial.println("Kp set to: " + String(Kp));
  } else if (command.startsWith("Ki")) {
    Ki = command.substring(2).toFloat();
    SerialBT.println("Ki set to: " + String(Ki));
    Serial.println("Ki set to: " + String(Ki));
  } else if (command.startsWith("Kd")) {
    Kd = command.substring(2).toFloat();
    SerialBT.println("Kd set to: " + String(Kd));
    Serial.println("Kd set to: " + String(Kd));
  } else if (command.startsWith("baseSpeed")) {
    baseSpeed = command.substring(9).toInt();
    SerialBT.println("Base Speed set to: " + String(baseSpeed));
    Serial.println("Base Speed set to: " + String(baseSpeed));
  } else if (command.startsWith("maxSpeed")) {
    maxSpeed = command.substring(8).toInt();
    SerialBT.println("Max Speed set to: " + String(maxSpeed));
    Serial.println("Max Speed set to: " + String(maxSpeed));
  } else if (command.startsWith("getPID")) {
    SerialBT.println("Current PID: Kp=" + String(Kp) + " Ki=" + String(Ki) + " Kd=" + String(Kd));
  } else if (command.startsWith("getSpeed")) {
    SerialBT.println("Current Speeds: Base=" + String(baseSpeed) + " Max=" + String(maxSpeed));
  } else {
    SerialBT.println("Unknown command: " + command);
  }
}




/*#include "SerialCommand.h"

#define SerialPort Serial
#define Baudrate 115200

SerialCommand sCmd;
bool debug;
unsigned long previous;
void setup()
{
  SerialPort.begin(Baudrate);
  
  sCmd.addCommand("set", onSet);
  sCmd.setDefaultHandler(onUnknownCommand);

  SerialPort.println("ready");
}

void loop()
{
  sCmd.readSerial();  // Luistert naar seriële commando's
  unsigned long current = micros();
  if (current - previous >= 1000000)  // Iedere seconde
  {
    previous = current;
    if (debug) 
      SerialPort.println("loop still running");
  }
}

void onUnknownCommand( const char *command)
{
  SerialPort.print("unknown command: \"");
  SerialPort.print(command);
  SerialPort.println("\"");
}

void onSet()
{
  char* param = sCmd.next();
  char* value = sCmd.next();

  if (strcmp(param, "debug") == 0)
  {
    if (strcmp(value, "on") == 0) debug = true;
    else if (strcmp(value, "off") == 0) debug = false;
  }
}*/