//#include <PS3BT.h>
#include <PS3USB.h>
#include <usbhub.h>
#include "PS3Con.h"
#include "Motor.h"
#include "Mecanum.h"
#include "ShagaiArm.h"
#include "GeregeArm.h"
#include "InjectionMachine.h"
#include "LineCommander.h"
#include "AIR.h"

USB Usb;
//BTD Btd(&Usb);
//PS3BT PS3(&Btd);
PS3USB PS3(&Usb);
PS3Con ps3con = PS3Con();
Mecanum mecanum = Mecanum(  5, 4, 9, 6, 46, 45, 3, 2,  1.3);
//ShagaiArm armS = ShagaiArm(31, 32, 33, 0);
ShagaiArm armS = ShagaiArm(49, 22, 24, 0);
GeregeArm armG = GeregeArm(36, 37, 38, 39, 0);
InjectionMachine IM = InjectionMachine(40, 41, 0);
LineCommander sen = LineCommander(200,10, 0, 0, 0);
AIR air = AIR(32);
Motor motor = Motor(42,43,0);

void setup() {
  Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));



  sen.SetL_D(29, 30, 31);
  sen.SetR_D(27, 26, 25);
  sen.SetF_A(A8, A9);
  sen.SetB_A(A10, A11);

}
void loop() {
  Usb.Task();
  if (PS3.PS3Connected) {
    if (PS3.getButtonClick(PS)) { //各ボタンの中にモーターを動かしたりトランジスタを動かしたりサーボを動かす処理をかいてください
      Serial.print(F("\r\nPS"));
    }
    else {
    }

    if (PS3.getButtonPress(TRIANGLE)) {
      Serial.print(F("\r\nTraingle"));
//      armG.Bend();
      motor.onF();
    }
    else if (PS3.getButtonPress(CIRCLE)) {
      Serial.print(F("\r\nCircle"));
      armS.Grab();
    }
    else if (PS3.getButtonPress(CROSS)) {
      Serial.print(F("\r\nCross"));
//      armG.Stretch();
      motor.onR();
    }
    else if (PS3.getButtonPress(SQUARE)) {
      Serial.print(F("\r\nSquare"));
      armS.Release();
    }
    else if (PS3.getButtonPress(UP)) {
      Serial.print(F("\r\nUp"));
      armS.Stretch();
    }
    else  if (PS3.getButtonPress(RIGHT)) {
      Serial.print(F("\r\nRight"));

    }
    else  if (PS3.getButtonPress(DOWN)) {
      Serial.print(F("\r\nDown"));
      armS.Bend();
    }
    else  if (PS3.getButtonPress(LEFT)) {
      Serial.print(F("\r\nLeft"));

    }
    else if (PS3.getButtonPress(L1)) {
      Serial.print(F("\r\nL1"));
      mecanum.TurnL();
      mecanum.Print();
    } else if (PS3.getButtonPress(L2)) {
      Serial.print(F("\r\nL2"));
      Serial.print(F("auto:"));
      Serial.print(F("deg "));
      Serial.print(sen.Angle(), 4);
      Serial.print(F("    distans "));
      Serial.print(sen.Distance(), 4);
      Serial.print(F("  "));
      mecanum.Rotation(225,sen.Rotate()+9);
      if(sen.Angle() > -15 && sen.Angle() < 15){
        mecanum.Front();
      }else{
        
        mecanum.Go(100*sen.Distance(),sen.Angle()+90);
      }
      mecanum.Print();
      Serial.println();
    }
    else if (PS3.getButtonPress(L3)) {
      Serial.print(F("\r\nL3"));
    }
    else if (PS3.getButtonPress(R1)) {
      Serial.print(F("\r\nR1"));
      mecanum.TurnR();
      mecanum.Print();
    }
    else if (PS3.getButtonPress(R2)) {
      Serial.print(F("\r\nR2"));
      Serial.print(F("auto:"));
      Serial.print(F("deg "));
      Serial.print(sen.Angle(), 4);
      Serial.print(F("    distans "));
      Serial.print(sen.Distance(), 4);
      Serial.print(F("  "));
      mecanum.Print();
      Serial.println();
    }
    else if (PS3.getButtonPress(R3)) {
      Serial.print(F("\r\nR3"));
    }
    else if (PS3.getButtonPress(SELECT)) {
      Serial.print(F("\r\nSelect"));
      air.OFA();
    }
    else if (PS3.getButtonPress(START)) {
      Serial.print(F("\r\nStart"));
//      IM.Inject();
      air.ONA();
    }
    else {
      //    my_left_analog_pad(ps3con.AnalogPadDirection(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)));
      motor.off();
      mecanum.Go(ps3con.AnalogPadDistance(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)), ps3con.AnalogPadAngle(PS3.getAnalogHat(LeftHatX), PS3.getAnalogHat(LeftHatY)));
      mecanum.Print();
      Serial.println(F("\r"));
    }
  }

}





void my_left_analog_pad(int n) {
  switch (n) {
    case ps3con.AnaFront:
      Serial.print(F("\r\nfront"));
      mecanum.Front();
      break;
    case ps3con.AnaFRight:
      Serial.print(F("\r\nfront_right"));
      mecanum.FRight();
      break;
    case ps3con.AnaRight:
      Serial.print(F("\r\nright"));
      mecanum.Right();
      break;
    case ps3con.AnaBRight:
      Serial.print(F("\r\nback_right"));
      mecanum.BRight();
      break;
    case ps3con.AnaBack:
      Serial.print(F("\r\nback"));
      mecanum.Back();
      break;
    case ps3con.AnaBLeft:
      Serial.print(F("\r\nback_left"));
      mecanum.BLeft();
      break;
    case ps3con.AnaLeft:
      Serial.print(F("\r\nleft"));
      mecanum.Left();
      break;
    case ps3con.AnaFLeft:
      Serial.print(F("\r\nfront_left"));
      mecanum.FLeft();
      break;
    case ps3con.AnaNeutral:
      Serial.print(F("\r\nstop"));
      mecanum.Stop();
      break;
    default:
      Serial.print(F("\r\nstop1"));
  }
}
