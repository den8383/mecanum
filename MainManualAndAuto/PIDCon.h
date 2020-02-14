#ifndef PIDCon_H
#define PIDCon_H

class PIDCon
{
public:
  PIDCon(float, float, float, float);
  void Input(float);
  void CalculationPID();
  float GetPID();
  float GetP();
  float GetI();
  float GetD();
  float Getdt();
  void Setdt(float);
  void SetTarget(float);

private:
  float New, Old;
  float PID;
  float P, I, D;
  float Kp, Ki, Kd;
  float Target;
  float Dt;
};

#endif
