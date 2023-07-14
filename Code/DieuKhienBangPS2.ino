// Khai báo thư viện PS2X_lib.h
#include <PS2X_lib.h>

// Khai báo các chân PS2_DAT, PS2_CMND, PS2_SEL, PS2_CLK
const int PS2_DAT = 26;
const int PS2_CMD = 25;
const int PS2_SEL = 23;
const int PS2_CLK = 22;
// Khai báo các chân động co
const int Motor1Pin1 = 12;
const int Motor1Pin2 = 14;
const int Motor2Pin1 = 33;
const int Motor2Pin2 = 32;

PS2X ps2x;

void setup(){
  // Gọi chương trình báo lỗi của PS2
  int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT);
  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);
}

void loop(){
  ps2x.read_gamepad();
  // Điều chỉnh tốc độ thông trục trục Y của nút joystick bên phải
  int speed = map(ps2x.Analog(PSS_RY), 0, 255, 0, 255);
  // Các trường hợp khi bấm nút
   if (y < 128) {
    // Gọi hàm tiến
    moveForward(speed);
    Serial.println("Moving forward");
  } else if (y > 128) {
    // Gọi hàm lùi
    moveBack(speed);
    Serial.println("Moving backward");
  } else if (x < 128) {
    // Gọi hàm quay trái
    turnleft(speed);
    Serial.println("Turning left");
  } else if (x > 128) {
    // Hàm quay phải
    turnRight(speed);
    Serial.println("Turning right");
  } else if (ps2x.Button(PSB_PAD_UP)) { 
    // Nút lên của phím điều hướng
    Serial.println("PSB_PAD_UP");
  } else if (ps2x.Button(PSB_PAD_DOWN)) { 
    // Nút xuống của phím điều hướng
    Serial.println("PSB_PAD_DOWN");
  } else if (ps2x.Button(PSB_PAD_LEFT)) { 
    // Nút bên trái của phím điều hướng
    Serial.println("PSB_PAD_LEFT");
  } else if (ps2x.Button(PSB_PAD_RIGHT)) { 
    // Nút bên phải của phím điều hướng
    Serial.println("PSB_PAD_RIGHT");
  } else if (ps2x.Button(PSB_CROSS)) {
    // Nút chữ X
    Serial.println("Cross button is pressed");
  } else if (ps2x.Button(PSB_CIRCLE)) { 
    // Nút tròn
    Serial.println("Circle button is pressed");
  } else if (ps2x.Button(PSB_SQUARE)) {
    // Nút vuông
    Serial.println("Square button is pressed");
  } else if (ps2x.Button(PSB_TRIANGLE)) { 
    // Nút tam giác
    Serial.println("Triangle button is pressed");
  }else if (ps2x.Button(PSB_L1)) {
    // Nút L1
    Serial.println("L1 button is pressed");
  } else if (ps2x.Button(PSB_L2)) {
    // Nút L2
    Serial.println("L2 button is pressed");
  }else if (ps2x.Button(PSB_R1)) {
    // Nút R1
    Serial.println("R1 button is pressed");
  } else if (ps2x.Button(PSB_R2)) {
    // Nút R2
    Serial.println("R2 button is pressed");
  } else {
    // Nếu không bấm gì thì gọi hàm dừng
    stop();
    Serial.println('Stop');
  }
}
// Hàm tiến
void moveForward(int speed) {
  analogWrite(Motor1Pin1, speed);
  analogWrite(Motor1Pin2, 0);
  analogWrite(Motor2Pin1, speed);
  analogWrite(Motor2Pin2, 0);
}
// Hàm lùi
void moveBack(int speed) {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, speed);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, speed);
}
// Hàm quay trái
void turnleft(int speed) {
  analogWrite(Motor1Pin1, 0);
  analogWrite(Motor1Pin2, speed);
  analogWrite(Motor2Pin1, speed);
  analogWrite(Motor2Pin2, 0);
}
// Hàm quay phải
void turnRight(int speed) {
  analogWrite(Motor1Pin1, speed);
  analogWrite(Motor1Pin2, 0);
  analogWrite(Motor2Pin1, 0);
  analogWrite(Motor2Pin2, speed);
}
// Hàm dừng
void stop() {
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);}