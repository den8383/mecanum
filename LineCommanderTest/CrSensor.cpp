#include "Arduino.h"
#include "CrSensor.h"

CrSensor::CrSensor(int ReadPin)
{
  m_ReadPin = ReadPin;
  pinMode(m_ReadPin,INPUT);
}

float CrSensor::TraceD()
{
  m_TrValueD = 1 - digitalRead(m_ReadPin);
  return m_TrValueD;
}

int CrSensor::TraceV(int TraceHold)
{
  m_TrValueV = analogRead(m_ReadPin);
  if(m_TrValueV >= TraceHold)
  {
    m_TrValueV = 0;
  }
  else
  {
    m_TrValueV =1;
  }
  return m_TrValueV;
}
int CrSensor::TraceA(){
  return 1023 - analogRead(m_ReadPin);
}

void CrSensor::PrintD()
{
  Serial.print(F("TrValuD = "));
  Serial.print(m_TrValueD);
  Serial.print(F(";"));
}

void CrSensor::PrintA()
{
  Serial.print(F("TrValuA = "));
  Serial.print(m_TrValueA);
  Serial.print(F(";"));
}

