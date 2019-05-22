#include<Servo.h>

Servo myServo;

const byte tempSensorPin=A0;
const byte dcMotorPin=11;
const byte servoPin=9;
const byte highTempC=30;
const byte lowTempC=25;
float temperature;
int rawSensorValue;

void setup(){
  Serial.begin(9600);
  pinMode(tempSensorPin, INPUT);
  pinMode(dcMotorPin, OUTPUT);
  myServo.attach(servoPin, 1000, 2000);
}

void loop(){
  float temp = getTemperature();
  digitalWrite(dcMotorPin, LOW);
  delay(1);
  if (temp > highTempC){ 
    Serial.println("Open Window + Fan");
    myServo.write(180); // Open window
    digitalWrite(dcMotorPin, HIGH); // start fan
  } else if (temp < lowTempC){
    Serial.println("Close Window + Fan");
    myServo.write(0); // close window
    digitalWrite(dcMotorPin, LOW); // stop fan
  } 
  delay(2000);
}

float getTemperature(){
  rawSensorValue = analogRead(tempSensorPin);
  temperature = convertToTemperature(rawSensorValue);
/*
  Serial.print("Sensor Value: ");
  Serial.print(rawSensorValue);
  Serial.print("\t");
  */
  Serial.print("Temperature(C): ");
  Serial.print(temperature);
  Serial.println();

  return temperature;
}

float convertToTemperature(int rawSensorValue){
  float AREF = 5.0;
  float calculatedVolts;
  float tempC;
  calculatedVolts = rawSensorValue * AREF / 1023;
  tempC = 100 * calculatedVolts - 50; 
  return tempC;
  
}
