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
int f_r_j_deg = 110;
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
//  climb();
//  avoid();
//  fall();
  pk();
}

