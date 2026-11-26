// أكاديمية النمر — الدرس ٤: إشارة بصوت 🔔
// الجرس (بزر) بيهتز فيطلع صوت — سرعة الاهتزاز اسمها التردد وبتتقاس بالهرتز: كل ما زاد، الصوت أحدّ
// التوصيل: نفس درس ٣ + الجرس: الرجل الموجبة (+) للمنفذ 7، والتانية لخط GND (مش محتاج مقاومة)

void setup() {
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  digitalWrite(10, HIGH);
  if (digitalRead(2) == LOW) {
    digitalWrite(10, LOW);
    digitalWrite(8, HIGH);
    tone(7, 1000, 3000);      // المنفذ، التردد، المدة بالميللي ثانية
    delay(3000);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    tone(7, 2000, 1000);      // نغمة أحدّ
    delay(1000);
    digitalWrite(9, LOW);
  }
}

// التحدي: غيّر التردد في الخضرا من 1000 إلى 500 وبعدها إلى 3000 وسمّع الفرق، وجرّب تخلّي الجرس يزن 3 نغمات ورا بعض زي جرس الباب
