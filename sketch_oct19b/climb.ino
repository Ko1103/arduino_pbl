

void climb(){
  fall();
  twincle(5);
  f_l_a_deg = moveServo2(fore_left.ankle, f_l_a_deg, 80);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, -80); //110 -> 30
  f_l_a_deg = moveServo2(fore_left.ankle, f_l_a_deg, -80);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, 80);
  
  f_r_a_deg = moveServo2(fore_right.ankle, f_r_a_deg, 70);
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg,-70);
  f_r_a_deg = moveServo2(fore_right.ankle, f_r_a_deg, -70);
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, 70);

  b_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, -40); //joint
  b_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, -90);
  b_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, 40); //joint
  b_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, 90);
  
  b_r_j_deg = moveServo2(back_right.joint, b_r_j_deg, 40);
  b_r_k_deg = moveServo2(back_right.knee, b_r_k_deg, 80);
  b_r_j_deg = moveServo2(back_right.joint, b_r_j_deg, -40);
  b_r_k_deg = moveServo2(back_right.knee, b_r_k_deg, -80);
//  b_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, 20);
}

