#ifndef CrSensor_h
#define CrSensor_h

class CrSensor
{
  public:
  CrSensor(int ReadPin);
  float TraceD();
  int TraceA();
  int TraceV(int TraceHold);
  void PrintA();
  void PrintD();

  private:
  int m_ReadPin;
  int m_mode;
  int m_TrValueD;
  int m_TrValueA;
  float m_TrValueV;
};

#endif
