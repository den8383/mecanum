#ifndef LineSensor_H
#define LineSensor_H

#include "DegSensor.h"

class LineSensor{
  public:
  LineSensor(int);
  
  template<class...Args>
  void SetR_D(Args...args){
   sen->SetR_D(args...);
  }
  
  template<class...Args>
  void SetL_D(Args...args){
   sen->SetL_D(args...);
  }
  
  template<class...Args>
  void SetF_D(Args...args){
   sen->SetF_D(args...);
  }
  
  template<class...Args>
  void SetB_D(Args...args){
   sen->SetB_D(args...);
  }






  
  template<class...Args>
  void SetR_A(Args...args){
   sen->SetR_A(args...);
  }
  
  template<class...Args>
  void SetL_A(Args...args){
   sen->SetL_A(args...);
  }
  
  template<class...Args>
  void SetF_A(Args...args){
   sen->SetF_A(args...);
  }
  
  template<class...Args>
  void SetB_A(Args...args){
   sen->SetB_A(args...);
  }

  
  void Trace();
  float Angle();
  float Distance();
  void Print();
  
  private:
  int TraceHold;
  DegSensor  *sen;
};
#endif
