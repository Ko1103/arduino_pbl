

void walk(){
  twincle(4);
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, -40);
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, 40);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, -50);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, 50);

  b_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, -40);
  b_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, -60);
  b_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, 50);
  b_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, 60);
  b_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, -10);
  
  b_r_j_deg = moveServo2(back_right.joint, b_r_j_deg, 40);
  b_r_k_deg = moveServo2(back_right.knee, b_r_k_deg, 40);
  b_r_j_deg = moveServo2(back_right.joint, b_r_j_deg, -60);
  b_r_k_deg = moveServo2(back_right.knee, b_r_k_deg, -40);
  b_r_j_deg = moveServo2(back_right.joint, b_r_j_deg, 20);
  fall();
}

