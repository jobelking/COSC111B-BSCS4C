#define THERMISTOR_PIN A0
#define PHOTORESISTOR_PIN A2
#define ALERT_PIN 12

const float TEMP_THRESHOLD = 40; // Celsius
const int LIGHT_THRESHOLD = 220;

void setup() {
  Serial.begin(9600);
  pinMode(ALERT_PIN, OUTPUT);
}

// ----------------------------------------------------------------------
// Function to read temperature in Celsius
// ----------------------------------------------------------------------
float readTemperature() {
  int analogValue = analogRead(THERMISTOR_PIN);
  float conversion = analogValue * (5.0 / 1023.0);
  float resistance = (5.0 - conversion) * 10000 / conversion; // 10k divider
  float temperature = 1 / (log(resistance / 10000.0) / 3950 + 1 / 298.15) - 273.15;
  return temperature;
}

// ----------------------------------------------------------------------
// Function to read brightness
// ----------------------------------------------------------------------
int readBrightness() {
  int brightness = analogRead(PHOTORESISTOR_PIN)*0.27;
  return brightness;
}

// ----------------------------------------------------------------------
// Loop
// ----------------------------------------------------------------------
void loop() {
  float temperature = readTemperature();
  int brightness = readBrightness();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Brightness: ");
  Serial.println(brightness);

  // Fire detection logic
  if (temperature >= TEMP_THRESHOLD && brightness >= LIGHT_THRESHOLD) {
    // Fast blink LED/buzzer
    digitalWrite(ALERT_PIN, HIGH);
    delay(1000);
    digitalWrite(ALERT_PIN, LOW);
    delay(1000);
  } else {
    digitalWrite(ALERT_PIN, LOW);
  }
}
