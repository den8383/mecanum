#include "LineCommander.h"

LineCommander::LineCommander(int traceHold,float targetAngle,float targetDistance,float targetRotate){
  TraceHold = traceHold;
  TargetAngle = targetAngle;
  TargetDistance = targetDistance;
  TargetRotate = targetRotate;
  sen = new LineSensor(TraceHold);
}

float LineCommander::Angle(){
  angle = sen->Angle();
  return angle - TargetAngle;
}

float LineCommander::Distance(){
  distance = sen->Distance();
  return distance - TargetDistance;
}

float LineCommander::Rotate(){
  rotate = -angle;
  return rotate + TargetRotate;
}

