# أكاديمية النمر — كورس أساسيات الأردوينو للأطفال 🔌🐯

**من لمبة بتومض... لمدينة ذكية كاملة!** 🏙️

كل أكواد كورس **أساسيات الأردوينو للأطفال** على قناة **أكاديمية النمر (Elnemr Academy)** — ٩ دروس بالترتيب، وكل درس بيبني على اللي قبله: ما تفكش حاجة، ضيف الجديد بس. كل المشاريع بتتنفّذ على موقع [Tinkercad](https://www.tinkercad.com) المجاني من المتصفح.

**تعلّم .. اصنع .. اكتشف**

▶️ **شاهد الكورس كاملًا:** [بلاي ليست الأردوينو على يوتيوب](https://www.youtube.com/playlist?list=PLIi9Fpl_Xdjg)

---

## 📚 خريطة الكورس — ٩ دروس

| # | الدرس | الفكرة الأساسية | الكود |
|---|-------|------------------|-------|
| ١ | 💡 لمبة بتومض | أول مشروع: `setup` مرة واحدة و `loop` للأبد | [blinking-led.ino](lessons/01-blinking-led/blinking-led.ino) |
| ٢ | 🚦 إشارة مرور كاملة | الأردوينو بينفّذ الأوامر بالترتيب | [traffic-light.ino](lessons/02-traffic-light/traffic-light.ino) |
| ٣ | 🔘 زرار يتحكم في الإشارة | الشرط `if`: لو حصل كذا اعمل كذا | [button-traffic-light.ino](lessons/03-button-traffic-light/button-traffic-light.ino) |
| ٤ | 🔔 إشارة بصوت | الجرس بيهتز فيطلع صوت — التردد بالهرتز | [traffic-light-buzzer.ino](lessons/04-traffic-light-buzzer/traffic-light-buzzer.ino) |
| ٥ | 📏 الأردوينو بيشوف | حساس المسافة بيبعت صوت ويستنى الصدى | [ultrasonic-traffic-light.ino](lessons/05-ultrasonic-traffic-light/ultrasonic-traffic-light.ino) |
| ٦ | 🚪 بوابة بتفتح لوحدها | السيرفو بيروح للزاوية اللي تقوله عليها | [servo-smart-gate.ino](lessons/06-servo-smart-gate/servo-smart-gate.ino) |
| ٧ | 🌙 نور ليل ذكي | الحساس الضوئي LDR مقاومته بتتغيّر مع الضوء | [smart-night-light.ino](lessons/07-smart-night-light/smart-night-light.ino) |
| ٨ | 📡 الريموت والأشعة تحت الحمراء | كل زرار بيبعت نبضات مخفية مختلفة | [ir-remote.ino](lessons/08-ir-remote/ir-remote.ino) |
| ٩ | 🏙️ المشروع النهائي: مدينة الأردوينو الذكية | بنجمع كل الدروس في مشروع واحد بـ ٤ مهام + أول دالة | [smart-city.ino](lessons/09-smart-city-final-project/smart-city.ino) |

وقبل الدرس الأول شوف فيديو المقدمة: **إيه هو الأردوينو وليه بنتعلمه** على القناة.

## 🗺️ خريطة المنافذ (للمشروع النهائي)

| المنفذ | موصّل بإيه |
|--------|-------------|
| 13 | اللمبة اللي جوا اللوحة (الدرس ١) |
| 10 | لمبة حمرا |
| 9 | لمبة صفرا |
| 8 | لمبة خضرا |
| 7 | الجرس (Buzzer) |
| 6 | السيرفو (البوابة) |
| 5 | حساس المسافة (Echo) |
| 4 | حساس المسافة (Trig) |
| 3 | لمبة نور الشارع |
| 2 | الزرار / مستقبل الأشعة تحت الحمراء |
| A0 | الحساس الضوئي (LDR) |

## 🔌 قواعد التوصيل

1. الخط الأحمر في لوح التجارب = الكهربا (5V)، والخط الأزرق = الأرضي (GND)
2. اللمبة: الرجل الطويلة (+) بمقاومة وبعدها منفذ، والقصيرة (−) للخط الأزرق
3. مقاومة اللمبة 120–220 أوم (في تينكركاد استخدم 120)

## 🛠️ إزاي تستخدم الأكواد

1. افتح ملف `.ino` بتاع الدرس في **Arduino IDE** أو **Tinkercad Circuits**
2. وصّل المكونات زي شرح الدرس على القناة
3. ارفع الكود وجرّب بنفسك — وكل درس في آخره تحدي 🏆

> درس الريموت (٨) محتاج مكتبة **IRremote** — هتلاقيها في Library Manager في Arduino IDE.

## 📺 تابع الأكاديمية

- يوتيوب: [youtube.com/@Elnemr-academy](https://www.youtube.com/@Elnemr-academy)
- تيك توك: [tiktok.com/@hossam_elnemr115](https://www.tiktok.com/@hossam_elnemr115)
