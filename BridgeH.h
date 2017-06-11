/*
* Controla las acciones de un puente H.
*/
class BridgeH {

private:

  int in1this, in2this, in3this, in4this;

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
  in1this = in1;
  in2this = in2;
  in3this = in3;
  in4this = in4;
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

/*
* Cambia el estado de todas las salidas del puente H a LOW, detine el mouse.
*/
void BridgeH::stopH() {
  digitalWrite(in1this, LOW);
  digitalWrite(in2this, LOW);
  digitalWrite(in3this, LOW);
  digitalWrite(in4this, LOW);
}
/*
* Cambia el estado de las salidas de forma que el mouse vaya hacia adelante.
*/
void BridgeH::fordward() {
  digitalWrite(in1this, HIGH);
  digitalWrite(in2this, LOW);
  digitalWrite(in3this, HIGH);
  digitalWrite(in4this, LOW);
}

/*
* Cambia el estado de las salidas de forma que el mouse vaya hacia atras.
*/
void BridgeH::reverse() {
  digitalWrite(in1this, LOW);
  digitalWrite(in2this, HIGH);
  digitalWrite(in3this, LOW);
  digitalWrite(in4this, HIGH);
}

/*
* Cambia el estado de las salidas de forma que el mouse vaya hacia la izquierda.
*/
void BridgeH::left() {
  digitalWrite(in1this, HIGH);
  digitalWrite(in2this, LOW);
  digitalWrite(in3this, LOW);
  digitalWrite(in4this, HIGH);
}

/*
* Cambia el estado de las salidas de forma que el mouse vaya hacia la derecha.
*/
void BridgeH::right() {
  digitalWrite(in1this, LOW);
  digitalWrite(in2this, HIGH);
  digitalWrite(in3this, HIGH);
  digitalWrite(in4this, LOW);
}
