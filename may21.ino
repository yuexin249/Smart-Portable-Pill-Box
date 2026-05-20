// 定义7段数码管的控制引脚 (对应 a~g 段)
const int segPins[] = {13, 12, 14, 27, 26, 25, 33}; 

// 共阴极数码管 0~9 的段码表 (a,b,c,d,e,f,g)
// 1=点亮, 0=熄灭
const byte numCodes[10] = {
  0x3F, // 0
  0x06, // 1
  0x5B, // 2
  0x4F, // 3
  0x66, // 4
  0x6D, // 5
  0x7D, // 6
  0x07, // 7
  0x7F, // 8
  0x6F  // 9
};

void setup() {
  // 初始化所有段引脚为输出模式
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
}

void loop() {
  // 循环显示 0~9
  for (int i = 0; i < 10; i++) {
    displayNumber(i);  // 显示当前数字
    delay(500);        // 每个数字显示500毫秒
  }
}

// 数字显示函数：输入0-9，控制数码管点亮
void displayNumber(int num) {
  byte code = numCodes[num];
  // 逐段控制亮灭
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], bitRead(code, i));
  }
}