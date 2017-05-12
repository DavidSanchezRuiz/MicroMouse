class BridgeH{
private:
  int in1this,in2this,in3this,in4this;
public:
  BridgeH(int in1, int in2, int in3, int in4);
  void stopH();
  void fordward();
  void reverse();
  void left();
  void right();
};

BridgeH::BridgeH(int in1, int in2, int in3, int in4){
  in1this=in1;
  in2this=in2;
  in3this=in3;
  in4this=in4;
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}
void BridgeH::stopH(){
  digitalWrite(in1this, LOW);
  digitalWrite(in2this, LOW);
  digitalWrite(in3this, LOW);
  digitalWrite(in4this, LOW);
}
void BridgeH::fordward(){
  digitalWrite(in1this, HIGH);
  digitalWrite(in2this, LOW);
  digitalWrite(in3this, HIGH);
  digitalWrite(in4this, LOW);
}
void BridgeH::reverse(){
  digitalWrite(in1this, LOW);
  digitalWrite(in2this, HIGH);
  digitalWrite(in3this, LOW);
  digitalWrite(in4this, HIGH);
}
void BridgeH::left(){
  digitalWrite(in1this, HIGH);
  digitalWrite(in2this, LOW);
  digitalWrite(in3this, LOW);
  digitalWrite(in4this, HIGH);
}
void BridgeH::right(){
  digitalWrite(in1this, LOW);
  digitalWrite(in2this, HIGH);
  digitalWrite(in3this, HIGH);
  digitalWrite(in4this, LOW);
}
