#include "Arduino.h"
#include "Sensors.h"



float Sensors::Trace(int Mode, int TraceHold){
  mode = Mode;
  if(mode == 1){
    for(int i = 0; i < tmp->Size(); i++){
      m_val[i] = crsen[i].TraceV(TraceHold);
    }
  }else if(mode == 0){
    for(int i = 0; i < tmp->Size(); i++){
      m_val[i] = crsen[i].TraceD();
    }
  }
  return CalSum();
}


void Sensors::MakeSensor(){ 
  for(int i = 0; i < tmp->Size(); i++){
    crsen.push_back(CrSensor(tmp->Arg[i]));
  }
}

float Sensors::CalSum(){
  int mult;
  int sum = 0;
  int POW = 1;
  POWSum = 0;
  float NormalizedSum;
  for(int i = 0; i < tmp->Size(); i++){
    if(i != 0){
      POW *= 2;
    }
    POWSum += POW;
    mult = m_val[i]*POW;
    sum += mult;
  }
  NormalizedSum = sum/POWSum;
//  return sum;
  return NormalizedSum;
  
}

void Sensors::Print(){
  
  for(int i = 0; i < tmp->Size(); i++){
    Serial.print(F("s["));
    Serial.print(i);
    Serial.print(F("]:"));
    Serial.print(crsen[i].TraceA());
    Serial.print(F(" "));
  }
  
}

float Sensors::MAX(){
  return POWSum;
}

