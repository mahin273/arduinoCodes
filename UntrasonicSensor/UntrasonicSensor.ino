// Define pins for the ultrasonic sensor
const int trigPin = 11;
const int echoPin = 12;

// Variable to store the duration and distance
long duration;
int distance;

void setup() {
  // Start the serial monitor at a baud rate of 9600
  Serial.begin(9600);
  
  // Define the trigPin as OUTPUT and the echoPin as INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin by setting it LOW
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Trigger the sensor by setting the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, and calculate the duration in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;
  
  // Print the distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Add a short delay before the next loop
  delay(500);
}
