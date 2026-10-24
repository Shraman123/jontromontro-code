// যন্ত্রমন্ত্র · Arduino ক্লাস #৬ · Arduino গায় সা রে গা মা
// জিনিস: Arduino Uno, একটা PASSIVE buzzer (active buzzer শুধু এক সুরে বিপ করে)
//
// Buzzer + → pin 8 · Buzzer − → GND

const int BUZZ = 8;

//              সা   রে   গা   মা   পা   ধা   নি   সা'
int sur[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
  // ওঠা: সা থেকে সা'
  for (int i = 0; i < 8; i++) {
    tone(BUZZ, sur[i]);
    delay(350);
  }
  // নামা: সা' থেকে সা
  for (int i = 7; i >= 0; i--) {
    tone(BUZZ, sur[i]);
    delay(350);
  }
  noTone(BUZZ);
}

void loop() {}   // একবার বাজিয়েই থামবে। আবার শুনতে Reset বোতাম টেপো
