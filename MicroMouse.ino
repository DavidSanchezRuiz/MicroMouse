#include "BridgeH.h"
#include "Counter.h"
BridgeH bh(5,6,9,10);//1-4
Counter c(2);
void setup() {
  interrupts();
  pinMode(2,INPUT);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), count, RISING);
}
void loop() {
  bh.fordward();
}
void count(){
  c.sum();
}

