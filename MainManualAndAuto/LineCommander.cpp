#include "LineCommander.h"

LineCommander::LineCommander(int traceHold,float sensitivity, float targetAngle,float targetDistance,float targetRotate){
  TraceHold = traceHold;
  Sensitivity = sensitivity;
  TargetAngle = targetAngle;
  TargetDistance = targetDistance;
  TargetRotate = targetRotate;
  sen = new LineSensor(TraceHold);

  
  angle = 0;
  distance = 0;
  rotate = 0;
  CorrectedAngle = 0;
  CorrectedDistance = 0;
  CorrectedRotate = 0;
}

float LineCommander::Angle(){
  angle = sen->Angle();
  CorrectedAngle += (angle - CorrectedAngle)*(Sensitivity/255);
  return CorrectedAngle - TargetAngle;
}

float LineCommander::Distance(){
  distance = sen->Distance();
  CorrectedDistance += (distance - CorrectedDistance)*(Sensitivity/255);
  return CorrectedDistance - TargetDistance;
}

float LineCommander::Rotate(){
  rotate = -angle;
  CorrectedRotate += (rotate - CorrectedRotate)*(Sensitivity/255);
  return CorrectedRotate + TargetRotate;
}

