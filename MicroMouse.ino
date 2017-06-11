#include "BridgeH.h"
#include "Counter.h"
#include "Ultra.h"

BridgeH bh(5,6,9,10);//1-4

Counter c(2);

Ultra u(11,12);

void setup() {
  //interrupts();
  //attachInterrupt(digitalPinToInterrupt(2), count, RISING);
  //pinMode(3,INPUT_PULLUP);
  Serial.begin(9600);
}
void loop() {
  Serial.println(u.getD());
  //bh.right();
  if(u.getD() > 4){
    bh.fordward();
  }else{
    bh.stopH();
  }
}

void count(){
  c.sum();
}
