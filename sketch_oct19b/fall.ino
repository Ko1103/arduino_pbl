void comeback(){
  //動く　
  do {
    moveServo(fore_right.knee, f_r_k_deg, 120);
    moveServo(fore_left.knee, f_l_k_deg, 120);
    
  }while(checkfall(360) == false);
  Serial.println("復帰プログラム終了");
}



//転倒しているかどうかをチェックする関数
//転倒したかどうかは270、正常に歩いているかどうかは360を基準にとっている
//転倒していれば trueを返す
bool checkfall(long border){
  bool check = false;
  
  uint8_t i;
  long x = 0;
  long y = 0;
  long z = 0;

  for (i=0; i<100; i++){
    x = x + analogRead(0);
    y = y + analogRead(1);
    z = z + analogRead(2);
  }

  x = x / 100;
  y = y / 100;
  z = z / 100;

  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" Y:");
  Serial.print(y);
  Serial.print(" Z:");
  Serial.println(z);

  delay(500); 
  if (border > 300) {
    Serial.println("状態を確認");
    if (y > border) {
      check = true;
    }
  }else if (y < border ){
    Serial.println("転倒しました。");
    check = true;
  }
  return check;
}
