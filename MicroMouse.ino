#include "BridgeH.h"
#include "Counter.h"
#include "Ultra.h"
#define TURN_SIZE 1

BridgeH bh(5, 6, 9, 10);//1-4
Counter c(2);
Ultra uRight(4, 3);
Ultra uFront(11, 12);
Ultra uLeft(7, 8);

void setup() {
  interrupts();
  attachInterrupt(digitalPinToInterrupt(2), count, FALLING);
  pinMode(13,INPUT_PULLUP);
  Serial.begin(9600);
  delay(5000);
}
void loop() {
  delay(50);
  if(uFront.getD()<5){
    bh.stopH();
    delay(50);
    if(uRight.getD()<uLeft.getD()<uFront.getD()<4){
      turnLeft();
      delay(100);
      bh.fordward();
    }else if(uRight.getD()>uLeft.getD()){
    turnRight();
    delay(100);
    }else{
      turnLeft();
      delay(1000);
    }
  }else
  bh.fordward();
  bh.fordward();  
  //measure()
  //control();
  //move();
  //test();
}

void measure() {
  int rightDistance = uRight.getD();
  int frontDistance = uFront.getD();
  int leftDistance = uLeft.getD();

  if ((rightDistance > 0 ) && (frontDistance > 0) && (leftDistance > 0)) {
    if ((bh.getObstacle()) && (frontDistance > FRONT_MIN_DISTANCE)) {
      bh.setObstacle(false);
    }
    if ((frontDistance <= FRONT_MIN_DISTANCE) && (frontDistance > 0)) {
      bh.next(leftDistance, rightDistance);
      bh.setObstacle(true);
    }
  }
};

void control() {
  if ((bh.getStatus() == STOPPED) && (!bh.getObstacle())) {
    bh.setStatus(GO_FORWARD);
  }
  if ((bh.getStatus() == GO_FORWARD) && (bh.getObstacle())) {
    switch (bh.getNextStep()) {
      case NEXT_LEFT:
      bh.setStatus(TURN_LEFT);
      break;
      case NEXT_RIGHT:
      bh.setStatus(TURN_RIGHT);
      break;
    }
  }
};

void move() {
  switch (bh.getStatus()) {
    case STOPPED:
    bh.stopH();
    break;
    case GO_FORWARD:
    bh.fordward();
    break;
    case TURN_RIGHT:
    bh.right();
    break;
    case GO_BACK:
    bh.reverse();
    break;
    case TURN_LEFT:
    bh.left();
    break;
  }
}
void count() {
  c.sum();
}
void testUltra(){
  Serial.print(uLeft.getD());
  Serial.print(" ");
  
  Serial.print(uFront.getD());
  Serial.print(" ");
  
  Serial.print(uRight.getD());
  Serial.println("");
}
void test(){
  if(uFront.getD()<3)
  bh.turnLeft(&c);
  else
  bh.stopH();
}
void test2(){
  turnRight();
  delay(2000);
  turnLeft();
  delay(2000);
}
void test3(){
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
