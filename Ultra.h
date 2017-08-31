#ifndef ULTRA
#define ULTRA

#define RIGHT_MIN_DISTANCE 15
#define FRONT_MIN_DISTANCE 15
#define LEFT_MIN_DISTANCE 15

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
  bool getContinueWalk();
  void setContinueWalk(bool continueWalk);

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
  if(int(0.017 * timeU)<0)
  return 20;
  else
  return int(0.017 * timeU);
}

bool Ultra::getContinueWalk(){
  return continueWalk;
}

void Ultra::setContinueWalk(bool continueWalk){
  this->continueWalk=continueWalk;
}

#endif /* ULTRA */
