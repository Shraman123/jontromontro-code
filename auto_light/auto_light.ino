// যন্ত্রমন্ত্র · Arduino ক্লাস #৪ · অন্ধকার হলেই নিজে জ্বলে ওঠা আলো
// জিনিস: Arduino Uno, LDR, 10k resistor, LED + 220Ω resistor (অথবা বোর্ডের নিজের pin 13 LED)
//
// LDR-এর এক পা → 5V
// LDR-এর অন্য পা → A0, আর সেখান থেকেই 10k resistor → GND
// (তাই আলো কমলে A0-র সংখ্যাও কমে)
// LED: লম্বা পা → 220Ω → pin 13 · ছোট পা → GND

const int LDR = A0, LED = 13;
const int DARK = 300;   // তোমার ঘরে Serial Monitor দেখে এটা বদলে নাও

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR);   // 0 থেকে 1023
  Serial.println(light);
  if (light < DARK) {
    digitalWrite(LED, HIGH);     // অন্ধকার → জ্বালাও
  } else {
    digitalWrite(LED, LOW);      // আলো আছে → নেভাও
  }
  delay(100);
}
