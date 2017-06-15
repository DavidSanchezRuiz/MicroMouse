#include "BridgeH.h"
#include "Counter.h"
#include "Ultra.h"

BridgeH bh(5, 6, 9, 10);//1-4

Counter c(2);

Ultra uRight(4, 3);
Ultra uFront(11, 12);
Ultra uLeft(7, 8);

void setup() {
  interrupts();
  attachInterrupt(digitalPinToInterrupt(2), count, RISING);
  //pinMode(3,INPUT_PULLUP);

  Serial.begin(9600);
}
void loop() {

  turnRight();
  //int frontDistance = uFront.getD();
  //int rightDistance = uRight.getD();
  //int leftDistance = uLeft.getD();

  //if (frontDistance > FRONT_MIN_DISTANCE) {
    //bh.fordward();
    //uFront.setContinueWalk(true);
  //}
}

void pruebas() {
  Serial.println(uFront.getD());
  Serial.println(uRight.getD());
  Serial.println(uLeft.getD());
  Serial.println();
}

void count() {
  c.sum();
}
void turnRight(){
  int count=c.getCount();
  while(count+20>c.getCount()){
    bh.right();
  }
  bh.stopH();
}

