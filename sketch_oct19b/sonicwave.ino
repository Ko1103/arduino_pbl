//前方との距離を測る関数
//一定の回数測定してその距離から次の行動に応じた値を返す
int check_distance(){
  int result;
  int count = 0;
  for(int i=0;i<10;i++){
    if(getDistance() < 30){
      count++;
    }
  }
  if (count > 7){
    return 1;
  } else {
    return 0;
  }
}


//超音波センサーから前方の障害物からの距離を取得する.
//その取得した値を[cm]単位で取得して、Distance(double型)に値を代入する
//5[cm]〜25[cm]の範囲で精度が保証される。
int getDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH);
  if (Duration > 0){
    Duration = Duration/2;
    Distance = Duration*340*100/1000000;
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println(" cm");
    delay(20);
    return Distance;
  }else {
    Serial.println("no distance");
    return -1;
  }
}




