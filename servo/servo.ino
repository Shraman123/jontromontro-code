// যন্ত্রমন্ত্র · Arduino ক্লাস #৫ · Servo = বাধ্য মোটর
// তার: বাদামি → GND · লাল → 5V · কমলা → pin 9
#include <Servo.h>

Servo arm;

void setup() {
  arm.attach(9);      // signal তার pin 9-এ
}

void loop() {
  arm.write(0);       // 0° তে যাও
  delay(1000);
  arm.write(90);      // 90° তে যাও
  delay(1000);
  arm.write(180);     // 180° তে যাও
  delay(1000);

  // বোনাস: ধীরে ধীরে 180° থেকে 0° পর্যন্ত ঘোরো
  for (int a = 180; a >= 0; a--) {
    arm.write(a);
    delay(15);
  }
  delay(1000);
}
