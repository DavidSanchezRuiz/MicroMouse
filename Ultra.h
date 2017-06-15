#ifndef ULTRA
#define ULTRA

#define RIGHT_MIN_DISTANCE 5
#define FRONT_MIN_DISTANCE 5
#define LEFT_MIN_DISTANCE 5

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

  bool continueWalk;

public:

  Ultra(int trigA, int echoA);
  long getD();

  // setContinueWalk();
};

/*
* Constructor que recibe los parametros pines de ECHO
* y de TRIGGER para el sensor ultrasonico.
*/
Ultra::Ultra(int trigA, int echoA) {
  echo = echoA;
  trig = trigA;
  continueWalk = false;
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
