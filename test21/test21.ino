// ===================== 数码管配置（你跑通的原版） =====================
const int segPins[] = {13, 12, 14, 27, 26, 25, 33}; 
const byte numCodes[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

// ===================== 【你的原版马里奥音乐，一字未改！】 =====================
#define BUZZER_PIN 18
int melody[] = {330, 330, 330, 262, 330, 392};
int noteDurations[] = {8,4,4,8,4,2};

// ===================== 按键自锁配置 =====================
#define KEY_PIN 19
bool deviceState = false;
bool lastKeyState = HIGH;

void setup() {
  // 初始化引脚
  for (int i = 0; i < 7; i++) pinMode(segPins[i], OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(KEY_PIN, INPUT_PULLUP);
}

void loop() {
  bool currentKeyState = digitalRead(KEY_PIN);
  
  // 按键边沿触发，切换开关状态
  if (currentKeyState == LOW && lastKeyState == HIGH) {
    delay(20);
    deviceState = !deviceState;
    
    if(deviceState){
      // 开启：短提示音
      tone(BUZZER_PIN, 1500); delay(100); noTone(BUZZER_PIN);
    }else{
      // 关锁：播放【你的原版马里奥音乐】
      playSuperMario();
    }
  }

  // 状态显示
  displayNumber(deviceState ? 8 : 0);
  lastKeyState = currentKeyState;
}

// ===================== 【你的原版音乐函数，完全不动！】 =====================
void playSuperMario() {
  int totalNotes = sizeof(melody) / sizeof(melody[0]);
  for (int i = 0; i < totalNotes; i++) {
    int noteDuration = 800 / noteDurations[i];
    tone(BUZZER_PIN, melody[i]);
    delay(noteDuration * 1.3);
    noTone(BUZZER_PIN);
    delay(50);
  }
  noTone(BUZZER_PIN);
}

// 数码管显示函数
void displayNumber(int num) {
  byte code = numCodes[num];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], bitRead(code, i));
  }
}