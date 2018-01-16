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
  back_right.knee.write(60);
  back_right.joint.write(160);
  back_left.knee.write(150);
  back_left.joint.write(50);
  pk();
}


void pk(){
  int mode = 0;
  if (mode == 0){
    fore_left.knee.write(30);
    fore_right.knee.write(40);
    fore_right.ankle.write(60);
    fore_left.ankle.write(60);
    delay(1000);
    fore_left.joint.write(30);//開く
    fore_right.joint.write(150);
    delay(1000);
    fore_right.joint.write(100);
    fore_left.joint.write(100);
  }else {
    
  }
}
