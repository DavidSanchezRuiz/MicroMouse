#include "BridgeH.h"
#include "Counter.h"
#include "Ultra.h"
BridgeH bh(5,6,9,10);//1-4
Counter c(2);
Ultra u(11,12);
void setup() {
  interrupts();
  attachInterrupt(digitalPinToInterrupt(2), count, RISING);
  pinMode(3,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  if(u.getD()>3){
    bh.fordward();
  }
}
void count(){
  c.sum();
}
