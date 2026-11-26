// أكاديمية النمر — الدرس ٥: الأردوينو بيشوف 📏
// حساس المسافة بيبعت صوت عالي ويستنى الصدى — الوقت اللي الصوت أخده بيتحوّل لمسافة: الوقت × 0.034 ÷ 2
// التوصيل: نفس درس ٤ من غير الزرار + حساس HC-SR04:
// ‏VCC ← 5V، ‏GND ← خط الأرضي، ‏Trig ← منفذ 4، ‏Echo ← منفذ 5

void setup() {
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);   // Trig
  pinMode(5, INPUT);    // Echo
  Serial.begin(9600);
}

void loop() {
  digitalWrite(10, HIGH);                 // الحمرا = الوضع العادي

  digitalWrite(4, LOW); delayMicroseconds(2);
  digitalWrite(4, HIGH); delayMicroseconds(10);
  digitalWrite(4, LOW);                   // الحساس يبعت الصوت

  long t = pulseIn(5, HIGH);              // وقت رجوع الصدى
  float d = t * 0.034 / 2;                // المسافة بالسنتيمتر
  Serial.println(d);

  if (d > 0 && d < 20) {                  // حد قرّب
    digitalWrite(10, LOW);
    digitalWrite(8, HIGH); tone(7, 1000, 3000); delay(3000); digitalWrite(8, LOW);
    digitalWrite(9, HIGH); tone(7, 2000, 1000); delay(1000); digitalWrite(9, LOW);
  }
}

// التحدي: غيّر الرقم 20 إلى 50، وبعدها اعمل حساس ركن عربية: كل ما تقرّب، الجرس يزن أسرع!
