#define BUZZER_PIN 18

// ===================== 精简：超级玛丽经典短旋律（仅保留开头核心部分） =====================
int melody[] = {
  330, 330, 330, 262, 330, 392
};

// 对应精简后的时长（和旋律一一匹配）
int noteDurations[] = {
  8,4,4,8,4,2
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // 三声提醒音
  reminderTone();
  delay(2000);

  // 播放【短版】超级玛丽
  playSuperMario();
  delay(2000);
}

// 保留你的提醒音
void reminderTone() {
  for (int i = 0; i < 3; i++) {
    tone(BUZZER_PIN, 1000);
    delay(200);
    noTone(BUZZER_PIN);
    delay(200);
  }
}

// 播放精简版音乐
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