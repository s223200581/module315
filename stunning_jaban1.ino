const int triggerPin = 9;    // Pin for HC-SR04 trigger
const int echoPin = 10;      // Pin for HC-SR04 echo
const int ledPin = 13;       // Pin for the LED

void setup() {
  pinMode(triggerPin, OUTPUT); // Set trigger pin as an OUTPUT
  pinMode(echoPin, INPUT);     // Set echo pin as an INPUT
  pinMode(ledPin, OUTPUT);     // Set LED pin as an OUTPUT
  Serial.begin(9600);          // Initialize serial communication
}

void loop() {
  // Send a signal to the trigger pin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Read the duration of the pulse from the echo pin
  long pulseDuration = pulseIn(echoPin, HIGH);
  // Convert the pulse duration to distance in centimeters
  float measuredDistance = (pulseDuration / 2.0) * 0.0344;

  // Display the measured distance on the Serial Monitor
  Serial.print("Measured Distance: ");
  Serial.print(measuredDistance);
  Serial.println(" cm");

  // Determine if the measured distance is approximately 113.4 cm
  if (abs(measuredDistance - 113.4) < 1.0) { // Acceptable error margin of 1 cm
    // Activate the LED with a blink pattern
    digitalWrite(ledPin, HIGH);
    delay(500); // LED on for 500 milliseconds
    digitalWrite(ledPin, LOW);
    delay(500); // LED off for 500 milliseconds
  } else {
    // Ensure the LED is turned off if distance does not match
    digitalWrite(ledPin, LOW);
  }

  delay(100); // Short pause before the next measurement
}
