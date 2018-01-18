

//サーボをスピードを遅くして動かす関数
//引数　ー　動かしたいサーボ、開始角度、終了角度
void moveServo(Servo leg, int start_deg, int end_deg) {
  if (start_deg < end_deg) {
    for (int deg = start_deg; deg < end_deg; deg++) {
      leg.write(deg);
      delay(t);
    }
  } else if (start_deg > end_deg) {
    for (int deg = start_deg; deg > end_deg; deg--) {
      leg.write(deg);
      delay(t);
    }
  }else {
    leg.write(start_deg);
  }
  start_deg = end_deg;
  delay(t);
}

int moveServo2(Servo leg, int target_deg, int change_deg) {
  if (change_deg > 0) {
    for(int deg= 0; deg <= change_deg; deg++){
      leg.write(target_deg + deg);
      delay(t);
    }
  }else if ( change_deg < 0 ){
    for(int deg=0; deg >= change_deg; deg--){
      leg.write(target_deg + deg);
      delay(t);
    }
  }
  
  return target_deg + change_deg;
}

//サーボを２つ同時にスピードを制御しながら動かす関数
void move_double(Servo servo_1, int start_deg_1, int end_deg_1, Servo servo_2, int start_deg_2, int end_deg_2){
  
  int deg_1 = start_deg_1;
  int deg_2 = start_deg_2;

  if( start_deg_1 > end_deg_1){
    while(true){
      servo_1.write(deg_1);
      servo_2.write(deg_2);
      deg_1 ++;
      deg_2 ++;
      if(deg_1 == end_deg_1){
        break;
      }
      delay(100);
    } 
  } else {
    while(true){
      servo_1.write(deg_1);
      servo_2.write(deg_2);
      deg_1 --;
      deg_2 --;
      if(deg_1 == end_deg_1){
        break;
     }
      delay(100);
    }
  }
} 

