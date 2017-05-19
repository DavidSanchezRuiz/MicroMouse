class Counter{
private:
  int count,state,pin;
public:
  Counter(int pin);
  int getCount();
  void sum();
};

Counter::Counter(int pinT){
  count=0;
  pinMode(pin,INPUT);
  pin=pinT;
  state=digitalRead(pin);
}

int Counter::getCount(){
  return count;
}
void Counter::sum(){
    count++;
}
