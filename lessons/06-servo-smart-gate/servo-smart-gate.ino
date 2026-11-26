// أكاديمية النمر — الدرس ٦: بوابة بتفتح لوحدها 🚪
// السيرفو محرك بيروح للزاوية اللي تقوله عليها (من 0 لـ 180) ويقف فيها — الأمر (write(زاوية بيحرّكه
// التوصيل: نفس درس ٥ + محرك سيرفو: الأحمر ← خط 5V، الأسود/البني ← خط GND، البرتقالي/الأصفر (الإشارة) ← منفذ 6
// وركّب ورقة مقواة صغيرة على دراع السيرفو تبقى هي البوابة

#include <Servo.h>
Servo gate;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
  gate.attach(6);
  gate.write(0);          // البوابة مقفولة
}

void loop() {
  digitalWrite(10, HIGH);

  digitalWrite(4, LOW); delayMicroseconds(2);
  digitalWrite(4, HIGH); delayMicroseconds(10);
  digitalWrite(4, LOW);
  float d = pulseIn(5, HIGH) * 0.034 / 2;

  if (d > 0 && d < 20) {
    digitalWrite(10, LOW);
    digitalWrite(8, HIGH); tone(7, 1000, 3000);
    gate.write(90);               // افتح البوابة
    delay(3000);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH); tone(7, 2000, 1000);
    delay(1000);
    gate.write(0);                // اقفل البوابة
    digitalWrite(9, LOW);
  }
}

// التحدي: غيّر الزاوية 90 إلى 180، وجرّب تخلّي البوابة تفتح نص فتحة بس (زاوية 45)، أو تفضل مفتوحة 6 ثواني
