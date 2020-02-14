#ifndef Sensors_H
#define Sensors_H

#include "Tmp.h"
#include "CrSensor.h"



class Sensors{
  public:
  template<class...Args>
  Sensors(Args...args){
    tmp = new Tmp(args...);
    MakeSensor();
    m_val.resize(tmp->Size());
  }
  float Trace(int, int);
  
  void Print();
  std::vector<int> val;
  float MAX();
  private:
  Tmp *tmp;
  std::vector<int> m_val;
  std::vector<CrSensor> crsen;
  void MakeSensor();
  float CalSum();
  float POWSum;
  int mode;
  //CrSensor crsen;
};

#endif
