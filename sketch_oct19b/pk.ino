

//pk
void pk(){
  pkinit();
  do {
    if(check_front() ==true ){
      stop_ball();
      delay(1000);
    }
  }while(true);
}



void pkinit(){
  fore_left.knee.write(30);
  fore_right.knee.write(40);
  fore_right.ankle.write(60);
  fore_left.ankle.write(60);
  
  moveServo(fore_left.joint, 70, 70);
  moveServo(fore_right.joint, 110, 110);
  
  back_right.knee.write(60);
  back_right.joint.write(160);
  back_left.knee.write(150);
  back_left.joint.write(50);
}


void stop_ball(){
  delay(50);
  fore_left.joint.write(30);//開く
  fore_right.joint.write(150);
  delay(1000);
  moveServo(fore_left.joint, 70, 70);
  moveServo(fore_right.joint, 110, 110);
  
}

bool check_front() {
  bool check = false;
  int distance = getDistance();
  if (distance  < 50){
    check = true;
  }
  return check;
}
