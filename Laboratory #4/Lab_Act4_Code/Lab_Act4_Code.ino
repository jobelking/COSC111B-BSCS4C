#define PHOTORESISTOR_PIN A0
#define ALERT_PIN 8

const int LIGHT_THRESHOLD = 220;
bool isMeetThreshold = false;

void setup() {
  Serial.begin(9600);
  pinMode(ALERT_PIN, OUTPUT);
  Serial.println("System Ready. Type 'stop' to stop blinking.");
}

int readBrightness() {
  return analogRead(PHOTORESISTOR_PIN) * 0.27;
}

void loop() {
  // Check for Serial command first (for faster response)
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();
    input.toLowerCase();
    if (input == "stop") {
      isMeetThreshold = false;
      digitalWrite(ALERT_PIN, LOW);
      Serial.println("Blinking stopped.");
    }
  }

  int brightness = readBrightness();
  Serial.print("Brightness: ");
  Serial.println(brightness);

  if (brightness >= LIGHT_THRESHOLD) {
    isMeetThreshold = true;
  }

  if (isMeetThreshold) {
    digitalWrite(ALERT_PIN, HIGH);
    delay(100);
    digitalWrite(ALERT_PIN, LOW);
    delay(100);
  } else {
    delay(200); // shorter delay to stay responsive
  }
}
