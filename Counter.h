#ifndef COUNTER
#define COUNTER
/*
* Controla el sensor que cuenta pasos.
*/
class Counter {

private:

  int count, state, pin;

public:

  Counter(int pin);
  int getCount();
  int getCountPointer();
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
  return count/2;
}

/*
 * Retorna el puntero del contador.
 */
int Counter::getCountPointer() {
  int *pointer=count;
  return pointer;
}

/*
* Suma 1 al valor del contador.
*/
void Counter::sum() {
    count++;
}
#endif /* COUNTER */
