// Slot 1 Pins
#define trig1 2
#define echo1 3
#define green1 8
#define red1 9

// Slot 2 Pins
#define trig2 4
#define echo2 5
#define green2 10
#define red2 11

long duration;
int distance;

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(green1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red2, OUTPUT);

  Serial.begin(9600);
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

void loop() {
  int d1 = getDistance(trig1, echo1);
  int d2 = getDistance(trig2, echo2);

  // SLOT 1
  if (d1 < 15) {
    digitalWrite(red1, HIGH);
    digitalWrite(green1, LOW);
  } else {
    digitalWrite(red1, LOW);
    digitalWrite(green1, HIGH);
  }

  // SLOT 2
  if (d2 < 15) {
    digitalWrite(red2, HIGH);
    digitalWrite(green2, LOW);
  } else {
    digitalWrite(red2, LOW);
    digitalWrite(green2, HIGH);
  }

  delay(300);
}
