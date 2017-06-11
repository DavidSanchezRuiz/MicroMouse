class Ultra{
private:
  int echo;
  int trig;
  int timeU;
public:
  Ultra(int trigA, int echoA);
  long getD();
};

Ultra::Ultra(int trigA, int echoA){
  echo=echoA;
  trig=trigA;
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
}
long Ultra::getD(){
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  timeU=pulseIn(echo,HIGH);
  return int(0.017*timeU);
}
