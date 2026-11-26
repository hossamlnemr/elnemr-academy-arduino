// ============================================
//  Elnemr Academy - Lesson 1: Smart Night Light
//  LDR light sensor + LED on Arduino Uno
//  The LED turns ON automatically when it gets dark!
//  Watch the lesson: youtube.com/@Elnemr-academy
// ============================================

int sensorPin = A0;   // LDR connected to analog pin A0
int ledPin = 3;       // LED connected to digital pin 3
int light = 0;        // variable to store the light reading

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // open the Serial Monitor to see the readings
}

void loop() {
  light = analogRead(sensorPin);  // read the light level (0 - 1023)
  Serial.println(light);          // print it so we can calibrate

  if (light < 300) {              // it's dark -> turn the light ON
    digitalWrite(ledPin, HIGH);
  } else {                        // there's light -> turn it OFF
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}

// CHALLENGE: change 300 to 500 and see what happens!
// Then try making the LED fade gradually (hint: analogWrite + map)
