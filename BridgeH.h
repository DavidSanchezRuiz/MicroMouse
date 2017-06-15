#ifndef BRIDGE_H
#define BRIDGE_H
/*
* Controla las acciones de un puente H.
*/
class BridgeH {

private:

  int in1, in2, in3, in4;

public:

  BridgeH(int in1, int in2, int in3, int in4);
  void stopH();
  void fordward();
  void reverse();
  void left();
  void right();
};
/*
* Recibe como parametros las 4 salidas del puente H.
*/
BridgeH::BridgeH(int in1, int in2, int in3, int in4) {
  this->in1= in1;
  this->in2= in2;
  this->in3= in3;
  this->in4= in4;
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
#endif /* BRIDGE_H */
