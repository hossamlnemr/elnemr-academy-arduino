// أكاديمية النمر — الدرس ٧: نور ليل ذكي 🌙
// الحساس الضوئي (LDR) مقاومته بتتغيّر مع الضوء — الأردوينو بيقراه برقم من 0 لـ 1023 بأمر analogRead
// التوصيل: رجل من الحساس ← خط 5V، والرجل التانية ← منفذ A0 + مقاومة 10 كيلو أوم لخط GND من نفس النقطة
// واللمبة: الرجل الطويلة ← مقاومة 120 أوم ← منفذ 3، والقصيرة ← خط GND

const int LDR = A0;
const int LAMP = 3;

void setup() {
  pinMode(LAMP, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR);        // رقم من 0 لـ 1023
  Serial.println(light);
  if (light < 300) {                  // الدنيا ضلمة
    digitalWrite(LAMP, HIGH);
  } else {                            // في ضوء
    digitalWrite(LAMP, LOW);
  }
  delay(100);
}

// التحدي: غيّر الرقم 300 إلى 500، وجرّب تخلّي النور ينوّر بالتدريج: كل ما الدنيا تضلّم أكتر، النور يزيد (تلميح: analogWrite و map)
