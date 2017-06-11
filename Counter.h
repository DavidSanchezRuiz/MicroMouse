/*
* Controla el sensor que cuenta pasos.
*/
class Counter {

private:

  int count, state, pin;

public:

  Counter(int pin);
  int getCount();
  void sum();
};

/*
* Recibe como parametro el pin utilizado por el contador.
*/
Counter::Counter(int pinT) {
  count = 0;
  pinMode(pin, INPUT);
  pin = pinT;
  state = digitalRead(pin);
}

/*
* Retorna el valor del contador.
*/
int Counter::getCount() {
  return count;
}

/*
* Suma 1 al valor del contador.
*/
void Counter::sum() {
    count++;
}
