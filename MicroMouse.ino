#include "BridgeH.h"
#include "Counter.h"
#include "Ultra.h"

BridgeH bh(5, 6, 9, 10);//1-4

Counter c(2);

Ultra uRight(4, 3);
Ultra uFront(11, 12);
Ultra uLeft(7, 8);

void setup() {
  //interrupts();
  //attachInterrupt(digitalPinToInterrupt(2), count, RISING);
  //pinMode(3,INPUT_PULLUP);

  Serial.begin(9600);
  delay(5000);
}
void loop() {
  measure();
  control();
  move();
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
