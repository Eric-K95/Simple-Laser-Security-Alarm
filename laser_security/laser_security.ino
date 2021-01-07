//Ex: Laser security alarm
//Created by JIN-WOO KIM
//This exercise shows when an object detect between the laser diode and the LDR, the buzzer alarm will turn on.
//If you want to stop or reset the alarm, add a button or touch switch to turn off the alarm.

const int laserPin = 3;
const int LDR = A0;
int buzzerPin = 2;
int ledPin = 12;
int highRange = 700;

void setup() {
  pinMode(LDR, INPUT); // Define the IR receiver as input
  pinMode(laserPin, OUTPUT);  // Define the laser as output
  pinMode(buzzerPin, OUTPUT); // Define the buzzer as output
  pinMode(ledPin, OUTPUT); // Define the led as output
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(LDR);
  if (sensorValue < 500) // The range is between 380 to 980
  { Serial.println(sensorValue);
    Serial.println("No Obstacle");
    noTone(buzzerPin);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  if (sensorValue > 500) {
    for (int i = highRange; i < sensorValue; i++) {
      alarmON();
    }
  }
}
void alarmON() {
  Serial.println("Obstacle is detected");
  tone(buzzerPin, 150);
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  tone(buzzerPin, 100);
  delay(500);
}
