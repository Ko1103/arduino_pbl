

void walk(){
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, -40);
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, 40);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, -50);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, 50);

  f_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, -20);
  f_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, -60);
  f_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, 30);
  f_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, 60);
  f_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, -10);
  
  f_r_j_deg = moveServo2(back_right.joint, f_r_j_deg, 20);
  f_r_k_deg = moveServo2(back_right.knee, f_r_k_deg, 40);
  f_r_j_deg = moveServo2(back_right.joint, f_r_j_deg, -40);
  f_r_k_deg = moveServo2(back_right.knee, f_r_k_deg, -40);
  f_r_j_deg = moveServo2(back_right.joint, f_r_j_deg, 20);
}

