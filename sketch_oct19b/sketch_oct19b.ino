#include <Servo.h>
#define t 5
#define echoPin 3 //緑色の超音波センサーの線
#define trigPin 2 //青色の超音波センサーの線

struct Fore {
  Servo ankle; //つまさき
  Servo knee; //ひざ
  Servo joint;//こかんせつ
};

struct Back {
  Servo knee;//ひざ
  Servo joint;//こかんせつ
};

struct Fore fore_right;
struct Fore fore_left;
struct Back back_right;
struct Back back_left;
double Duration = 0;
double Distance = 0;


int mode = 0; //歩行、悪路、旋回などの切り替え用の数値

int f_l_a_deg = 80;
int f_l_k_deg = 110;
int f_l_j_deg = 90;
int f_r_a_deg = 80;
int f_r_k_deg = 120;
int f_r_j_deg = 90;
int b_l_k_deg = 120;
int b_l_j_deg = 120;
int b_r_k_deg = 70;
int b_r_j_deg = 90;

void setup() {
  fore_left.ankle.attach(4);
  fore_left.knee.attach(5);
  fore_left.joint.attach(6);
  fore_right.ankle.attach(7);
  fore_right.knee.attach(8);
  fore_right.joint.attach(9);
  back_left.knee.attach(10);
  back_left.joint.attach(11);
  back_right.knee.attach(12);
  back_right.joint.attach(13);
  
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
//  初期状態
  mode = check_distance();
  moveServo(fore_left.ankle, f_l_a_deg, f_l_a_deg); 
  moveServo(fore_left.knee, f_l_k_deg, f_l_k_deg); 
  moveServo(fore_left.joint, f_l_j_deg, f_l_j_deg);
  moveServo(fore_right.ankle, f_r_a_deg, f_r_a_deg); //right ankle 150度でまっすぐになる
  moveServo(fore_right.knee, f_r_k_deg, f_r_k_deg); // right knee の初期値として足を下につかせる
  moveServo(fore_right.joint, f_r_j_deg, f_r_j_deg); //right jointの初期値として正面を向かせる
  
  moveServo(back_right.knee, b_r_k_deg, b_r_k_deg);
  moveServo(back_right.joint, b_r_j_deg, b_r_j_deg);
  moveServo(back_left.knee, b_l_k_deg, b_l_k_deg);
  moveServo(back_left.joint, b_l_j_deg, b_l_j_deg);
  
  //歩行
//  walk();
  //悪路
  climb();

  //回避
//  if(mode == 0){
//    walk();
//  }else if(mode == 1){
//    delay(2000);
//    turn(0);
//    for(int i=0;i<5;i++){
//      walk();
//    }
//    turn(1);
//  }
//  climb();
//  pushup();
}


void pushup(){
  moveServo(fore_left.ankle, 90, 90); 
  moveServo(fore_left.knee, 120, 120); 
  moveServo(fore_left.joint, 30, 30);
  moveServo(fore_right.ankle, 90, 90); //right ankle 150度でまっすぐになる
  moveServo(fore_right.knee, 120,120); // right knee の初期値として足を下につかせる
  moveServo(fore_right.joint, 150,150); //right jointの初期値として正面を向かせる
  moveServo(back_right.knee, 90,90);
  moveServo(back_right.joint, 110,110);
  moveServo(back_left.knee, 100,100);
  moveServo(back_left.joint, 100,100);
  move_double(fore_left.knee, 120, 90, fore_right.knee, 120, 90);
  move_double(fore_left.knee, 90, 120, fore_right.knee, 90, 120);
}


void walk(){
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, -40);
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, 40);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, -50);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, 50);

  f_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, -20);
  f_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, -60);
  f_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, 30);
  f_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, 60);
  f_l_j_deg = moveServo(back_left.joint, b_l_j_deg, -10);
  
  f_r_j_deg = moveServo2(back_right.joint, f_r_j_deg, 20);
  f_r_k_deg = moveServo2(back_right.knee, f_r_k_deg, 40);
  f_r_j_deg = moveServo2(back_right.joint, f_r_j_deg, -40);
  f_r_k_deg = moveServo2(back_right.knee, f_r_k_deg, -40);
  f_r_j_deg = moveServo2(back_right.joint, f_r_j_deg, 20);
}



void climb(){
  f_l_a_deg = moveServo2(fore_left.ankle, f_l_a_deg, 80);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, -80); //110 -> 30
  f_l_a_deg = moveServo2(fore_left.ankle, f_l_a_deg, -80);
  f_l_k_deg = moveServo2(fore_left.knee, f_l_k_deg, 80);
  
  f_r_a_deg = moveServo2(fore_right.ankle, f_r_a_deg, 70);
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg,-70);
  f_r_a_deg = moveServo2(fore_right.ankle, f_r_a_deg, -70);
  f_r_k_deg = moveServo2(fore_right.knee, f_r_k_deg, 70);

  b_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, -60); //joint
  b_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, -90);
  b_l_j_deg = moveServo2(back_left.joint, b_l_j_deg, 60); //joint
  b_l_k_deg = moveServo2(back_left.knee, b_l_k_deg, 90);
  
  b_r_j_deg = moveServo2(back_right.joint, b_r_j_deg, 60);
  b_r_k_deg = moveServo2(back_right.knee, b_r_k_deg, 80);
  b_r_j_deg = moveServo2(back_right.joint, b_r_j_deg, -60);
  b_r_k_deg = moveServo2(back_right.knee, b_r_k_deg, -80);
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
