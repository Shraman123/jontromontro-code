// যন্ত্রমন্ত্র · Arduino ক্লাস #৭ · ঘরে কেউ ঢুকলেই অ্যালার্ম
// জিনিস: Arduino Uno, HC-SR501 PIR sensor, একটা buzzer (passive হলে ভালো), চাইলে একটা LED
//
// PIR:     VCC → 5V · GND → GND · OUT → pin 2
// Buzzer:  + → pin 8 · − → GND
// LED (ঐচ্ছিক): বোর্ডের নিজের pin 13 LED-ই জ্বলবে
//
// টিপস: চালু করার পর PIR-কে ৩০–৬০ সেকেন্ড সময় দাও, ও ঘরের "স্বাভাবিক তাপ" শিখে নেয়।
// PIR-এর গায়ে দুটো কমলা স্ক্রু: একটা দূরত্ব (sensitivity), অন্যটা কতক্ষণ HIGH থাকবে (time delay)।

const int PIR = 2, BUZZ = 8, LED = 13;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("PIR গরম হচ্ছে... ৩০ সেকেন্ড অপেক্ষা করো");
  delay(30000);
  Serial.println("পাহারা শুরু!");
}

void loop() {
  if (digitalRead(PIR) == HIGH) {   // কেউ নড়ছে
    digitalWrite(LED, HIGH);
    tone(BUZZ, 1000); delay(200);   // পুলিশের সাইরেনের মতো দুই সুর
    tone(BUZZ, 1400); delay(200);
  } else {                          // কেউ নেই
    digitalWrite(LED, LOW);
    noTone(BUZZ);
  }
}
