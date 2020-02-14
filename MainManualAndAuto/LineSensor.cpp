#include "LineSensor.h"
#include "Arduino.h"


LineSensor::LineSensor(int traceHold){
  TraceHold = traceHold;
  sen = new DegSensor();
}

void LineSensor::Trace(){
  sen->Trace(TraceHold);
}

float LineSensor::Angle(){
  return sen->TraceAng(TraceHold);
}
float LineSensor::Distance(){
  return sen->TraceDis(TraceHold);
}

void LineSensor::Print(){
  
  sen->Trace(TraceHold);
  Serial.print(F("R"));
  Serial.print(sen->DisR());
  Serial.print(F("  L"));
  Serial.print(sen->DisL());
  Serial.print(F("  F"));
  Serial.print(sen->DisF());
  Serial.print(F("  B"));
  Serial.println(sen->DisB());
}

