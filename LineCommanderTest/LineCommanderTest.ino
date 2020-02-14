#include "LineCommander.h"
LineCommander sen = LineCommander(200,0,0,0);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sen.SetL_D(51,52,53);
  sen.SetR_D(49,48,47);
  sen.SetF_A(A8,A9);
  sen.SetB_A(A10,A11);
  /*
  for(int i = 0; i < 200; i++){
    sen.Print();
    Serial.println();
    delay(50);
  }
  */
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(F("deg"));
  Serial.print(sen.Angle(),4);
  Serial.print(F("    distans"));
  Serial.println(sen.Distance(),4);
  delay(50);
  
//  sen.Print();

}
