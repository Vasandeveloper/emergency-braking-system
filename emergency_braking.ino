const int trigPin = 9;
const int echoPin = 10;
const int motorPin = 5;
const int ledPin = 6;
const int buzzerPin = 7;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 20 && distance > 0) {
    digitalWrite(motorPin, LOW);   // Stop motor
    digitalWrite(ledPin, HIGH);    // LED ON
    digitalWrite(buzzerPin, HIGH); // Buzzer ON
  } else {
    digitalWrite(motorPin, HIGH);  // Start motor
    digitalWrite(ledPin, LOW);     // LED OFF
    digitalWrite(buzzerPin, LOW);  // Buzzer OFF
  }

  delay(200);
}
