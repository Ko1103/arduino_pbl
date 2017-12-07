#include <Servo.h>
#define t 10
#define echoPin 22
#define trigPin 23


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


void setup() {
  fore_right.ankle.attach(3);
  fore_right.knee.attach(4);
  fore_right.joint.attach(5);
  fore_left.ankle.attach(6);
  fore_left.knee.attach(7);
  fore_left.joint.attach(8);
  back_right.knee.attach(9);
  back_right.joint.attach(10);
  back_left.knee.attach(11);
  back_left.joint.attach(12);
  
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  //初期状態
  moveServo(fore_left.ankle, 100, 100); 
  moveServo(fore_left.knee, 100, 100); 
  moveServo(fore_left.joint, 100, 100);
  moveServo(fore_right.ankle, 100, 100); //right ankle 150度でまっすぐになる
  moveServo(fore_right.knee, 100,100); // right knee の初期値として足を下につかせる
  moveServo(fore_right.joint, 100,100); //right jointの初期値として正面を向かせる
  moveServo(back_right.knee, 100,100);
  moveServo(back_right.joint, 100,100);
  moveServo(back_left.knee, 100,100);
  moveServo(back_left.joint, 100,100);
//  walk();
}

void walk(){
  moveServo(fore_right.knee, 100,60);
  moveServo(fore_right.knee, 60,100);
//  moveServo(back_left.joint, 60);
//  moveServo(back_left.knee, 70);
//  moveServo(back_left.joint, 120);
//  moveServo(back_left.knee, 120);
//  moveServo(fore_right.knee, 120);
//  moveServo(fore_left.knee, 90);
//  moveServo(fore_left.knee, 150);
//  moveServo(back_right.joint, 150);
//  moveServo(back_right.knee, 120);
//  moveServo(back_left.joint, 110);
//  moveServo(back_right.joint, 120);
//  moveServo(back_right.knee, 60);
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
  delay(t);
}


//超音波センサーから前方の障害物からの距離を取得する.
//その取得した値を[cm]単位で取得して、Distance(double型)に値を代入する
//5[cm]〜25[cm]の範囲で精度が保証される。
void getDistance(){
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
  }else {
    Serial.println("no distance");
  }
  delay(20);
}


//サーボを２つ同時にスピードを制御しながら動かす関数
//void move_Double_servo(Servo servo_1, int start_deg_1, int end_deg_1, Servo servo_2, int start_deg_2, int end_deg_2){
//  if (start_deg_1 < end_deg_1) {
//    for (int deg = start_deg_1; deg < end_deg_1; deg++) {
//      servo.write(deg);
//      delay(t);
//    }
//  } else if (start_deg > end_deg) {
//    for (int deg = start_deg; deg > end_deg; deg--) {
//      servo.write(deg);
//      delay(t);
//    }
//  } else {
//    servo.write(start_deg);
//  }
//} 
