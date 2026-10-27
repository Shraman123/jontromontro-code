# যন্ত্রমন্ত্র · Arduino কোড

Instagram-এ **যন্ত্রমন্ত্র**-র Arduino পর্বগুলোর পুরো কোড। মেশিন শেখে, আমরাও শিখি, বাংলায়।

| পর্ব | কী বানাবে | কোড |
|---|---|---|
| Arduino ক্লাস #৩ | দেয়াল দেখলেই ঘুরে যাওয়া রোবট 🚗 | [obstacle_bot](obstacle_bot/obstacle_bot.ino) |
| Arduino ক্লাস #৪ | অন্ধকার হলেই নিজে জ্বলে ওঠা আলো 💡 | [auto_light](auto_light/auto_light.ino) |
| Arduino ক্লাস #৫ | ঠিক কোণে থামা Servo মোটর 🎯 | [servo](servo/servo.ino) |
| Arduino ক্লাস #৬ | Buzzer-এ সা রে গা মা 🎵 | [buzzer_sargam](buzzer_sargam/buzzer_sargam.ino) |
| Arduino ক্লাস #৭ | ঘরে কেউ ঢুকলেই অ্যালার্ম 🚨 | [pir_alarm](pir_alarm/pir_alarm.ino) |
| Arduino ক্লাস #৮ | মাটি শুকোলেই গাছ চেঁচাবে 🌱 | [plant_alarm](plant_alarm/plant_alarm.ino) |

তার কোথায় জুড়বে, সেটা প্রতিটা ফাইলের একদম ওপরে লেখা আছে।

## কীভাবে চালাবে

1. [Arduino IDE](https://www.arduino.cc/en/software) নামাও।
2. যে ফাইলটা চাও খোলো, তারপর ওপরে ডানদিকে **Copy raw file** বোতাম (📋) টেপো।
3. IDE-তে নতুন sketch খুলে paste করো।
4. **Tools → Board → Arduino Uno** আর **Tools → Port** বেছে নিয়ে **Upload** (→) টেপো।

## আটকে গেলে

- **Upload হচ্ছে না:** Port ঠিক বাছা হয়েছে কিনা দেখো। USB তার শুধু চার্জিং-এর হলে চলবে না, data তার লাগবে।
- **মোটর বা Servo কাঁপছে, Arduino বারবার reset হচ্ছে:** power কম পড়ছে। মোটরের জন্য আলাদা ব্যাটারি দাও, আর সব GND এক করো।
- **কিছুই বুঝছ না কী হচ্ছে:** **Tools → Serial Monitor** খোলো (9600 baud)। sensor-এর সংখ্যা ওখানে দেখা যায়।

প্রশ্ন থাকলে Instagram-এ যন্ত্রমন্ত্র-কে DM করো। বানালে ভিডিও পাঠিও, story-তে দেব 🔥

MIT License, যা খুশি বানাও।
