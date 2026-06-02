#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

byte smile[8] = {
  B00000000,
  B01000100,
  B01000100,
  B00000000,
  B00000000,
  B01000100,
  B00111000,
  B00000000
};

void setup(void) {
  u8g2.begin();
}

void loop(void) {
  u8g2.clearBuffer();
  for (int y=0; y<8; y++) {
    for (int x=0; x<8; x++) {
      if (bitRead(smile[y], 7-x)) {
        u8g2.drawPixel(30+x, 30+y);
      }
    }
  }
  u8g2.sendBuffer();
}