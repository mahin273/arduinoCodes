// Define pin connections
const int mqSensorPin = A0; // Analog output pin of MQ sensor connected to A0

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the MQ sensor
  int sensorValue = analogRead(mqSensorPin);
  
  // Print the sensor value to the serial monitor
  Serial.print("MQ Sensor Value: ");
  Serial.println(sensorValue);
  
  // You can set a threshold value to detect smoke
  // Adjust this value based on calibration
  int smokeThreshold = 200; // Change this based on your tests

  if (sensorValue > smokeThreshold) {
    Serial.println("Smoke detected!");
  } else {
    Serial.println("No smoke detected.");
  }

  // Wait for 1 second before next reading
  delay(1000);
}
