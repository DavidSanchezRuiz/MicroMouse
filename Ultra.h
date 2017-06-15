#ifndef ULTRA
#define ULTRA
/*
* Se encarga de controlar el sensor ultrasonico.
*/
class Ultra {

private:
  // Envia onda
  int echo;
  // Recibe conda
  int trig;
  // Tiempo de duracion de rebote de la onda
  int timeU;

public:

  Ultra(int trigA, int echoA);
  long getD();
};

/*
* Constructor que recibe los parametros pines de ECHO
* y de TRIGGER para el sensor ultrasonico.
*/
Ultra::Ultra(int trigA, int echoA) {
  echo = echoA;
  trig = trigA;
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
}
/*
* Distancia en cm
*/
long Ultra::getD() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  timeU = pulseIn(echo, HIGH);
  return int(0.017 * timeU);
}
#endif /* ULTRA */
