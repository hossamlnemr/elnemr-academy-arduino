// أكاديمية النمر — الدرس ٣: زرار يتحكم في الإشارة 🔘
// الشرط (if): لو حصل كذا اعمل كذا — الأردوينو بياخد قرار
// التوصيل: نفس درس ٢ + زرار على منفذ 2 (رجل للمنفذ، والرجل المقابلة لخط GND)
// ملحوظة: مش محتاج مقاومة للزرار، لأن الأردوينو فيه مقاومة داخلية بنفعّلها بـ INPUT_PULLUP

void setup() {
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, INPUT_PULLUP);   // الزرار
}

void loop() {
  digitalWrite(10, HIGH);               // الحمرا = الوضع العادي
  if (digitalRead(2) == LOW) {          // الزرار اتضغط؟
    digitalWrite(10, LOW);
    digitalWrite(8, HIGH); delay(3000); digitalWrite(8, LOW);
    digitalWrite(9, HIGH); delay(1000); digitalWrite(9, LOW);
  }
}

// التحدي: غيّر وقت الخضرا من 3 ثواني إلى 5، وجرّب تخلّي الصفرا تومض 3 مرات قبل ما ترجع الحمرا
