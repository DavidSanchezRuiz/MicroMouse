#ifndef BRIDGE_H
#define BRIDGE_H

#define FRONT_BLOCK 0

#define GO_FORWARD  1
#define TURN_RIGHT  2
#define GO_BACK     3
#define TURN_LEFT   4
#define STOPPED     5
#define NEXT_LEFT   6
#define NEXT_RIGHT  7



/*
* Controla las acciones de un puente H.
*/
class BridgeH {

private:

  int in1, in2, in3, in4, status, nextStep;
  bool obstacle;

public:

  BridgeH(int in1, int in2, int in3, int in4);
  void stopH();
  void fordward();
  void reverse();
  void left();
  void right();
  void next(int leftDistance, int rightDistance);

  int getStatus();
  void setStatus(int status);

  int getNextStep();
  void setNextStep(int next);

  bool getObstacle();
  void setObstacle(bool obstacle);
};
/*
* Recibe como parametros las 4 salidas del puente H.
*/
BridgeH::BridgeH(int in1, int in2, int in3, int in4) {
  this->in1 = in1;
  this->in2 = in2;
  this->in3 = in3;
  this->in4 = in4;

  this->obstacle = false;

  this->status = STOPPED;

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

/*
* Cambia el estado de todas las salidas del puente H a LOW, detine el mouse.
*/
void BridgeH::stopH() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
/*
* Cambia el estado de las salidas de forma que el mouse vaya hacia adelante.
*/
void BridgeH::fordward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

/*
* Cambia el estado de las salidas de forma que el mouse vaya hacia atras.
*/
void BridgeH::reverse() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

/*
* Cambia el estado de las salidas de forma que el mouse vaya hacia la izquierda.
*/
void BridgeH::left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

/*
* Cambia el estado de las salidas de forma que el mouse vaya hacia la derecha.
*/
void BridgeH::right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void BridgeH::next(int leftDistance, int rightDistance) {
  if (leftDistance > rightDistance) {
    this->nextStep = NEXT_LEFT;
  } else {
    this->nextStep = NEXT_RIGHT;
  }
}

int BridgeH::getStatus(){
  return this->status;
}
void BridgeH::setStatus(int status){
  this->status = status;
}

int BridgeH::getNextStep(){
  return this->nextStep;
}
void BridgeH::setNextStep(int next){
  this->nextStep = next;
}

bool BridgeH::getObstacle(){
  return this->obstacle;
}

void BridgeH::setObstacle(bool obstacle){
  this->obstacle = obstacle;
}

#endif /* BRIDGE_H */
