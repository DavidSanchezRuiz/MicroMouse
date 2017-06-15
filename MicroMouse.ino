#include "BridgeH.h"
#include "Counter.h"
#include "Ultra.h"

BridgeH bh(5, 6, 9, 10);//1-4

Counter c(2);

Ultra uRight(11, 12);
Ultra uFront(7, 8);
Ultra uLeft(13, 4);

void setup() {
  //interrupts();
  //attachInterrupt(digitalPinToInterrupt(2), count, RISING);
  //pinMode(3,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  Serial.println(uFront.getD());
  //bh.right();
  // if(uFront.getD() > 4) {
  //   bh.fordward();
  // }else{
  //   bh.stopH();
  // }
}

void count() {
  c.sum();
}
