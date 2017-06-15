#include "BridgeH.h"
#include "Counter.h"
#include "Ultra.h"
#define TURN_SIZE 4

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
  test();
}

void pruebas() {
  Serial.println(uFront.getD());
  Serial.println(uRight.getD());
  Serial.println(uLeft.getD());
  Serial.println();
}

void count() {
  Serial.println(c.getCount());
  c.sum();
}
void test2(){
  turnRight();
  delay(2000);
  turnLeft();
  delay(2000);
}
void test(){
  if(uRight.getD()<2){
    correctLeft();
  }
  if(uLeft.getD()<2){
    correctRight();
  }
}
void turnRight(){
  int count=c.getCount();
  while(count+TURN_SIZE>c.getCount()){
    bh.right();
  }
  bh.stopH();
}
void turnLeft(){
  int count=c.getCount();
  while(count+TURN_SIZE>c.getCount()){
    bh.left();
    
  }
  bh.stopH();
}
void correctRight(){
  int count=c.getCount();
  while(count+1>c.getCount()){
    bh.right();
  }
  bh.fordward();
}
void correctLeft(){
  int count=c.getCount();
  while(count+1>c.getCount()){
    bh.left();
  }
  bh.fordward();
}
