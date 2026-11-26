// أكاديمية النمر — الدرس ٢: الريموت السحري 📺
// نسخة متقدمة — الكود النهائي + زرار تعتيم
// الفرق عن remote-final.ino: زرار تالت BUTTON_DIM كل دوسة يعلّي النور
// خطوة (0 ← 51 ← 102 ... ← 255 ثم يرجع 0)، بأمر analogWrite على منفذ 6.
// ملحوظة: الريموت وهو مضغوط بيبعت إشارة "تكرار"، فالسطر اللي فيه
// IRDATA_FLAGS_IS_REPEAT بيمنع النور يقفز خطوات كتير من دوسة واحدة.
// التوصيل والمكتبة زي remote-final.ino بالظبط.

#define DECODE_NEC
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 11
#define LED_PIN 6

// ⚠️ بدّل الأكواد دي بأكواد ريموتك من السيريال مونيتور (سكيتش discover-codes)
#define BUTTON_ON  0x??  // زرار التشغيل
#define BUTTON_OFF 0x??  // زرار الإطفاء
#define BUTTON_DIM 0x??  // زرار التعتيم — كل دوسة يعلّي النور خطوة

int brightness = 0;  // 0 = مطفية، 255 = أعلى نور

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    uint8_t cmd = IrReceiver.decodedIRData.command;
    Serial.print("الكود: 0x");
    Serial.println(cmd, HEX);

    if (cmd == BUTTON_ON) {
      brightness = 255;
      analogWrite(LED_PIN, brightness);
    } else if (cmd == BUTTON_OFF) {
      brightness = 0;
      analogWrite(LED_PIN, brightness);
    } else if (cmd == BUTTON_DIM
               && !(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)) {
      brightness += 51;
      if (brightness > 255) {
        brightness = 0;
      }
      analogWrite(LED_PIN, brightness);
    }
    IrReceiver.resume();  // مهم جدًا: من غيرها الريموت هيتسمّع مرة واحدة بس
  }
}
