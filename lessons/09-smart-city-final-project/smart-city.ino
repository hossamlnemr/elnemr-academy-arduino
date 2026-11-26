// أكاديمية النمر — الدرس ٩: المشروع النهائي 🏙️
// مدينة الأردوينو الذكية — إنت عمدة المدينة! بنجمع كل الدروس في مشروع واحد بـ 4 مهام
// وبنتعلم أول دالة (Function): وصفة بنكتبها مرة وننادي عليها بالاسم
//
// خريطة المنافذ: 10 حمرا • 9 صفرا • 8 خضرا • 7 جرس • 6 سيرفو • 5+4 حساس المسافة • 3 نور الشارع • 2 زرار الطوارئ • A0 حساس الضوء
// المهام: 1) نور الشارع يشتغل لوحده في الضلمة  2) الوضع العادي: الحمرا منوّرة والبوابة مقفولة
//        3) الطوارئ قبل الحارس (الأمان أهم حاجة): البوابة تقفل وصفارة إنذار  4) الحارس: البوابة تفتح لما حد يقرّب أقل من 20 سم

#include <Servo.h>
Servo gate;

float readDistance() {                    // أول دالة في الكورس
  digitalWrite(4, LOW); delayMicroseconds(2);
  digitalWrite(4, HIGH); delayMicroseconds(10);
  digitalWrite(4, LOW);
  return pulseIn(5, HIGH) * 0.034 / 2;
}

void setup() {
  pinMode(10, OUTPUT); pinMode(9, OUTPUT); pinMode(8, OUTPUT);
  pinMode(7, OUTPUT); pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); pinMode(5, INPUT);
  pinMode(2, INPUT_PULLUP);
  gate.attach(6);
  gate.write(0);                            // البوابة مقفولة
}

void loop() {
  // 1) نور الشارع
  if (analogRead(A0) < 300) digitalWrite(3, HIGH);
  else digitalWrite(3, LOW);

  // 2) الوضع العادي
  digitalWrite(10, HIGH);

  // 3) الطوارئ (قبل الحارس — الأمان أهم حاجة)
  if (digitalRead(2) == LOW) {
    gate.write(0);
    tone(7, 2000, 300); delay(300);
    tone(7, 500, 300); delay(300);
    tone(7, 2000, 300); delay(300);
  }

  // 4) الحارس
  float d = readDistance();
  if (d > 0 && d < 20) {
    digitalWrite(10, LOW);
    digitalWrite(8, HIGH); tone(7, 1000, 3000);
    gate.write(90);
    delay(3000);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    gate.write(0);
    delay(1000);
    digitalWrite(9, LOW);
  }
}

// التحدي: المدينة بتاعتك إنت! غيّر المسافة لـ 50 سم، خلّي البوابة تفتح أوسع أو أبطأ، اعمل صفارة بنغمات جديدة أو لحن كامل،
// أو ضيف نور بيزيد بالتدريج أو إشارة للمشاة — وصوّر مشروعك وشاركه في التعليقات!
