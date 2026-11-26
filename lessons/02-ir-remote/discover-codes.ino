// أكاديمية النمر — الدرس ٢: الريموت السحري 📺
// سكيتش اكتشاف الأكواد — ارفع ده الأول قبل الكود النهائي
// التوصيل: حساس IR ‏VS1838B‏ — VCC ‏← 5V، GND ‏← GND، OUT ‏← منفذ 11
// المكتبة: IRremote ‏4.x‏ — من مدير المكتبات ابحث عن IRremote وثبّتها.
// افتح السيريال مونيتور على 9600، ودوّس على كل زرار واكتب الكود اللي يظهر.

#define DECODE_NEC
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 11

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("دوّس على أي زرار في الريموت...");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("الكود: 0x");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    IrReceiver.resume();
  }
}
