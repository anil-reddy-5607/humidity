#define MQ135_PIN A0     // Analog pin connected to MQ135
#define LED_PIN 7        // Optional: LED or buzzer for alert

void setup() {
  Serial.begin(9600);
  pinMode(MQ135_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(MQ135_PIN);
  float voltage = sensorValue * (5.0 / 1023.0);  // Convert to voltage
  float ppm = map(sensorValue, 0, 1023, 0, 1000); // Rough estimation in ppm

  Serial.print("Analog Value: "); Serial.print(sensorValue);
  Serial.print(" | Voltage: "); Serial.print(voltage, 2);
  Serial.print(" V | Estimated PPM: "); Serial.println(ppm);

  // Trigger alert if pollution level is high
  if (ppm > 400) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(2000);  // Wait for 2 seconds before next read
}
