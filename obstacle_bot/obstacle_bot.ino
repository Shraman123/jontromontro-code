// যন্ত্রমন্ত্র · Arduino ক্লাস #৩ · দেয়াল দেখলেই ঘুরে যাওয়া রোবট
// জিনিস: Arduino Uno, HC-SR04 ultrasonic sensor, L298N motor driver, ২টো চাকাওয়ালা DC মোটর, ব্যাটারি (7–12V)
//
// HC-SR04:  VCC → 5V · GND → GND · TRIG → pin 9 · ECHO → pin 10
// L298N:    IN1 → pin 4 · IN2 → pin 5 (বাঁ মোটর)
//           IN3 → pin 6 · IN4 → pin 7 (ডান মোটর)
//           ENA আর ENB-এর জাম্পার লাগানো থাকুক (পুরো স্পিড)
//           ব্যাটারি + → L298N 12V · ব্যাটারি − → L298N GND → Arduino GND (GND এক করতেই হবে!)

const int TRIG = 9, ECHO = 10;
const int IN1 = 4, IN2 = 5, IN3 = 6, IN4 = 7;
const int LIMIT_CM = 20;   // এর চেয়ে কাছে দেয়াল হলে ঘোরো

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  Serial.begin(9600);
}

// বাদুড়ের কায়দা: শব্দ পাঠাও, ফিরে আসতে কত সময় লাগল মাপো
long distanceCm() {
  digitalWrite(TRIG, LOW);  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long us = pulseIn(ECHO, HIGH, 30000);   // ৩০ ms-এ কিছু না ফিরলে 0
  if (us == 0) return 999;                // কিছু নেই সামনে
  return us / 58;                         // শব্দের গতি থেকে সেন্টিমিটার
}

void forward() {
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnRight() {
  // বাঁ চাকা সামনে, ডান চাকা পেছনে → নিজের জায়গায় ডানদিকে ঘোরে
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
  delay(400);
}

void loop() {
  long d = distanceCm();
  Serial.println(d);
  if (d < LIMIT_CM) {
    turnRight();
  } else {
    forward();
  }
  delay(50);
}
