// যন্ত্রমন্ত্র · Arduino ক্লাস #৯ · লুডোর ছক্কা
// জিনিস: Arduino Uno, ৭টা LED, ৭টা 220Ω রেজিস্টর, একটা push button
//
// LED গুলো ছক্কার ফোঁটার মতো সাজাও:
//      a     e          a = D2   e = D6
//      b  d  f          b = D3   d = D5   f = D7
//      c     g          c = D4   g = D8
// প্রতিটা LED: লম্বা পা → রেজিস্টর → pin, ছোট পা → GND
// বোতাম: এক পা → pin 12, অন্য পা → GND (INPUT_PULLUP, তাই আলাদা রেজিস্টর লাগবে না)
//
// টিপস: A0-তে কিছু লাগিও না। খোলা পিনের এলোমেলো ভোল্টেজ দিয়েই randomSeed হয়।

const int LED[7] = {2, 3, 4, 5, 6, 7, 8};   // a b c d e f g
const int BTN = 12;

// কোন সংখ্যায় কোন LED জ্বলবে (a b c d e f g)
const byte FACE[7][7] = {
  {0, 0, 0, 0, 0, 0, 0},   // ০: সব নেভা
  {0, 0, 0, 1, 0, 0, 0},   // ১: মাঝেরটা
  {1, 0, 0, 0, 0, 0, 1},   // ২: দুই কোণ
  {1, 0, 0, 1, 0, 0, 1},   // ৩: কোণাকুণি
  {1, 0, 1, 0, 1, 0, 1},   // ৪: চার কোণ
  {1, 0, 1, 1, 1, 0, 1},   // ৫: চার কোণ + মাঝ
  {1, 1, 1, 0, 1, 1, 1},   // ৬: দুই পাশের সারি
};

void dekhao(int n) {
  for (int i = 0; i < 7; i++) digitalWrite(LED[i], FACE[n][i] ? HIGH : LOW);
}

void setup() {
  for (int i = 0; i < 7; i++) pinMode(LED[i], OUTPUT);
  pinMode(BTN, INPUT_PULLUP);       // না টিপলে HIGH, টিপলে LOW
  randomSeed(analogRead(A0));       // প্রতিবার নতুন ক্রম
  dekhao(0);
}

void loop() {
  if (digitalRead(BTN) == LOW) {
    for (int i = 0; i < 10; i++) {  // গড়াচ্ছে… ধীরে ধীরে থামে
      dekhao(random(1, 7));         // random(1, 7) = ১ থেকে ৬
      delay(60 + i * 20);
    }
    dekhao(random(1, 7));           // আসল দান
    while (digitalRead(BTN) == LOW) {}  // আঙুল না সরানো পর্যন্ত অপেক্ষা
    delay(50);                      // বোতামের কাঁপুনি (bounce) থামুক
  }
}
