#ifndef LineCommander_H
#define LineCommander_H

#include "LineSensor.h"

class LineCommander{
  public:
  LineCommander(int ,float ,float ,float);
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
  float Angle();
  float Distance();
  float Rotate();
  private:
  int TraceHold;
  float TargetAngle;
  float TargetDistance;
  float TargetRotate;
  float angle;
  float distance;
  float rotate;
  LineSensor *sen;
  
};

#endif
