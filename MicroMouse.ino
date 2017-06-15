#include "BridgeH.h"
#include "Counter.h"
#include "Ultra.h"

// BridgeH bh(5, 6, 9, 10);//1-4
//
// Counter c(2);

// Ultra uRight(4, 3);
// Ultra uFront(11, 12);
// Ultra uLeft(7, 8);

Ultra uPruebas(2, 3);

void setup() {
  //interrupts();
  //attachInterrupt(digitalPinToInterrupt(2), count, RISING);
  //pinMode(3,INPUT_PULLUP);

  Serial.begin(9600);
}
void loop() {

//   int frontDistance = uFront.getD();
//   int rightDistance = uRight.getD();
//   int leftDistance = uLeft.getD();
//
// if (frontDistance > FRONT_MIN_DISTANCE) {
//
// }

//  if(pared_adelante>10) {//si la distancia en
// pared_adelante es mayor a 10, el robot
// avanza hacia adelante
//  mas_adelante=true; //se vuelve verdadera
// esta variable para que cuando elija un giro el
// robot, avance un poco más antes de realizar
// el cambio de dirección

  // Serial.println(uFront.getD());
  // bh.fordward();
  // if(uFront.getD() > 4) {
  //   bh.fordward();
  // }else{
  //   bh.stopH();
  // }
}

void pruebas() {
    Serial.println(uPruebas.getD());

}

void count() {
  c.sum();
}
