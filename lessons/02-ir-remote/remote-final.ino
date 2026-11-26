// أكاديمية النمر — الدرس ٢: الريموت السحري 📺
// الكود النهائي (تشغيل / إطفاء)
// ⚠️ بدّل الأكواد دي بأكواد ريموتك من السيريال مونيتور (سكيتش discover-codes).
//    كل ريموت أكواده مختلفة — مفيش كود عالمي.
// التوصيل: حساس IR ‏OUT ← منفذ 11، لمبة LED ‏← منفذ 6 (مش 3!)
//    اللمبة على 6 لأن مكتبة IRremote وهي بتسمع بتعطّل التعتيم (PWM) على منفذ 3.
// المكتبة: IRremote ‏4.x‏ — #define DECODE_NEC قبل #include <IRremote.hpp>

#define DECODE_NEC
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 11
#define LED_PIN 6

// ⚠️ بدّل الأكواد دي بأكواد ريموتك من السيريال مونيتور
#define BUTTON_ON  0x??  // زرار التشغيل
#define BUTTON_OFF 0x??  // زرار الإطفاء

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
      digitalWrite(LED_PIN, HIGH);
    } else if (cmd == BUTTON_OFF) {
      digitalWrite(LED_PIN, LOW);
    }
    IrReceiver.resume();  // مهم جدًا: من غيرها الريموت هيتسمّع مرة واحدة بس
  }
}
