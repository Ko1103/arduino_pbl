

//回避
void avoid(){
  mode = check_distance();
  if(mode == 0){
    walk();
  }else if(mode == 1){
    delay(2000);
    turn(0);
    for(int i=0;i<4;i++){
      walk();
    }
    turn(1);
  }
}


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
      f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, -60);
      f_l_j_deg = moveServo2(fore_left.joint, f_l_j_deg, 40);
      f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, 60);
      f_l_j_deg = moveServo2(fore_left.joint, f_l_j_deg, -40);
      delay(200);
//      moveServo(back_left.joint, 100, 140);
//      moveServo(back_left.joint, 140, 100);
//      moveServo(back_right.joint, 100, 60);
//      moveServo(back_right.joint, 60, 100);
    }
    
  }else{
    //反時計回りに回転
    for(int i=0;i<8;i++){
      //時計回りに回転
      f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, -60);
      f_l_j_deg = moveServo2(fore_left.joint, f_l_j_deg, -40);
      f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, 40);
      f_l_j_deg = moveServo2(fore_left.joint, f_l_j_deg, 40);
      delay(200);
      f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, -60);
      f_r_j_deg = moveServo2(fore_right.joint, f_r_j_deg, -40);
      f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, 60);
      f_r_j_deg = moveServo2(fore_right.joint, f_r_j_deg, 40);
      delay(200);
      f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, 20);
//      moveServo(back_left.joint, 100, 140);
//      moveServo(back_left.joint, 140, 100);
//      moveServo(back_right.joint, 100, 60);
//      moveServo(back_right.joint, 60, 100);
    }
  }
}



