// যন্ত্রমন্ত্র · Arduino ক্লাস #৮ · গাছ নিজেই বলবে, জল দাও
// জিনিস: Arduino Uno, soil moisture sensor (দুই কাঁটা + ছোট বোর্ড), একটা buzzer
//
// Sensor:  VCC → 5V · GND → GND · AO → A0   (DO pin লাগবে না)
// Buzzer:  + → pin 8 · − → GND
//
// টিপস:
// ১. আগে Serial Monitor (9600) খুলে দেখো, তোমার শুকনো মাটিতে আর ভেজা মাটিতে কত সংখ্যা আসে।
//    তারপর SHUKNO-র মান ওই দুটোর মাঝামাঝি রাখো। সাধারণত শুকনো হলে সংখ্যা বড়।
// ২. সস্তা কাঁটাগুলো সারাক্ষণ বিদ্যুৎ পেলে মাটিতে ক্ষয়ে যায়। অনেক দিন রাখতে চাইলে
//    VCC-টা 5V-এর বদলে pin 7-এ লাগাও, আর SENSOR_POWER লাইনের // সরিয়ে দাও:
//    তখন শুধু মাপার সময়টুকু বিদ্যুৎ যাবে।

const int SENSOR = A0, BUZZ = 8;
const int SHUKNO = 700;        // এর বেশি মানে মাটি শুকনো
// #define SENSOR_POWER 7

void setup() {
  Serial.begin(9600);
#ifdef SENSOR_POWER
  pinMode(SENSOR_POWER, OUTPUT);
#endif
}

void loop() {
#ifdef SENSOR_POWER
  digitalWrite(SENSOR_POWER, HIGH);
  delay(100);                  // sensor-কে একটু জেগে উঠতে দাও
#endif
  int mati = analogRead(SENSOR);
#ifdef SENSOR_POWER
  digitalWrite(SENSOR_POWER, LOW);
#endif

  Serial.print("মাটি: ");
  Serial.println(mati);

  if (mati > SHUKNO) {         // শুকনো → বিপ বিপ
    tone(BUZZ, 2000, 250); delay(450);
    tone(BUZZ, 2000, 250);
  }
  delay(2000);                 // দু'সেকেন্ড পর আবার মাপো
}
