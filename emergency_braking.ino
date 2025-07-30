// Emergency Braking System with LED and Motor

const int trigPin = 9;
const int echoPin = 10;
const int motorPin = 5;  // Motor control pin
const int ledPin = 6;    // LED alert pin

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo duration and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check for object within threshold (e.g., 20 cm)
  if (distance < 20 && distance > 0) {
    digitalWrite(motorPin, LOW);  // Stop motor
    digitalWrite(ledPin, HIGH);   // Turn on LED alert
  } else {
    digitalWrite(motorPin, HIGH); // Run motor
    digitalWrite(ledPin, LOW);    // Turn off LED
  }

  delay(200);
}