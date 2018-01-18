


//90度回転するプログラム
void turn(int direct){
  if (direct == 0){
    for(int i=0;i<8;i++){
      //時計回りに回転
      moveServo(fore_right.knee,120, 60);
      moveServo(fore_right.joint,100, 140);
      moveServo(fore_right.knee,60, 120);
      moveServo(fore_right.joint,140, 100);
      delay(200);
      moveServo(fore_left.knee,120, 60);
      moveServo(fore_left.joint,100, 140);
      moveServo(fore_left.knee,60, 120);
      moveServo(fore_left.joint,140, 100);
//      delay(200);
//      moveServo(back_left.joint, 100, 140);
//      moveServo(back_left.joint, 140, 100);
//      moveServo(back_right.joint, 100, 60);
//      moveServo(back_right.joint, 60, 100);
    }
    
  }else{
    //反時計回りに回転
    for(int i=0;i<8;i++){
      //時計回りに回転
      moveServo(fore_left.knee,120, 60);
      moveServo(fore_left.joint,100, 60);
      moveServo(fore_left.knee,60, 120);
      moveServo(fore_left.joint,60, 100);
      delay(200);
      moveServo(fore_right.knee,120, 60);
      moveServo(fore_right.joint,100, 60);
      moveServo(fore_right.knee,60, 120);
      moveServo(fore_right.joint,60, 100);
//      delay(200);
//      moveServo(back_left.joint, 100, 140);
//      moveServo(back_left.joint, 140, 100);
//      moveServo(back_right.joint, 100, 60);
//      moveServo(back_right.joint, 60, 100);
    }
  }
}



