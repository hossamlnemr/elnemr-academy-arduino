// أكاديمية النمر — الدرس ٨: الريموت والأشعة تحت الحمراء 📡
// كل زرار في الريموت بيبعت نبضات مخفية مختلفة — المستقبل بيترجمها لرقم، والأردوينو بيقارن الرقم ويقرر
// التوصيل: سيب التلات لمبات (10 و9 و8) + مستقبل الأشعة: رجل الكهربا ← خط 5V، الأرضي ← خط GND، الإشارة ← منفذ 2
// تحذير: ترتيب الرجول بيختلف من نوع لنوع — اقرا الحروف المكتوبة على المستقبل قبل التوصيل

#include <IRremote.hpp>      // ثبّت المكتبة من Library Manager

void light(int pin) {
  digitalWrite(10, LOW); digitalWrite(9, LOW); digitalWrite(8, LOW);
  digitalWrite(pin, HIGH);
}

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(2);
  pinMode(10, OUTPUT); pinMode(9, OUTPUT); pinMode(8, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    int c = IrReceiver.decodedIRData.command;
    Serial.println(c);                  // اعرف رقم كل زرار

    if (c == 12) light(10);             // زرار 1 ← الحمرا
    else if (c == 24) light(9);         // زرار 2 ← الصفرا
    else if (c == 94) light(8);         // زرار 3 ← الخضرا
    else if (c == 22) { digitalWrite(10, LOW); digitalWrite(9, LOW); digitalWrite(8, LOW); }  // زرار 0 ← اطفي الكل

    IrReceiver.resume();
  }
}

// أرقام الزراير (12 و24 و94 و22) بتخص ريموت معيّن — ريموتك ممكن يبعت أرقام تانية:
// ارفع الكود، افتح السيريال مونيتور، دوس الزراير، واكتب الأرقام اللي ظهرت مكان أرقام الكود
// التحدي: ضيف زرار رقم 4 يخلّي التلات لمبات يومضوا مع بعض 3 مرات، وبعدها جرّب تتحكم في بوابة السيرفو بالريموت
