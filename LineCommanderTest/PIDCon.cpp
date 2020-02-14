#include "PIDCon.h"

PIDCon::PIDCon(float target, float kp, float ki, float kd)
{
  Target = target;
  Kp = kp;
  Ki = ki;
  Kd = kd;
  P = 0;
  I = 0;
  D = 0;
  PID = 0;
  Old = 0;
  New = 0;
  Dt = 1;
}

void PIDCon::Input(float data)
{
  Old = P;
  New = data;
  CalculationPID();
  PID = Kp * P + Ki * I + Kd * D;
  if (PID > 255)
  {
    PID = 255;
  }
  else if (PID < -255)
  {
    PID = -255;
  }
}

void PIDCon::CalculationPID()
{
  P = New - Target;
  I += P * Dt;
  D = (P - Old) / Dt;
}

float PIDCon::GetPID()
{
  return PID;
}

float PIDCon::GetP()
{
  return P;
}

float PIDCon::GetI()
{
  return I;
}

float PIDCon::GetD()
{
  return D;
}

float PIDCon::Getdt()
{
  return Dt;
}

void PIDCon::Setdt(float dt)
{
  Dt = dt;
}

void PIDCon::SetTarget(float target)
{
  Target = target;
}