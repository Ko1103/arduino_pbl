

void twincle(int mode){

  if( mode == 1 ){
    //右旋回
    reset_LED();
    digitalWrite(31, HIGH);
  }else if( mode == 2){
    //左旋回
    reset_LED();
    digitalWrite(32, HIGH);
  }else if( mode == 3){
    //転倒
    reset_LED();
    digitalWrite(33, HIGH);
  }else if (mode == 4){
    //歩き
    reset_LED();
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
  }else if( mode == 5 ){
    //登り
    reset_LED();
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
  }
}

void reset_LED(){
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
}

