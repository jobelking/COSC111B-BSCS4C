const int total_led = 5;
int ledPins[total_led] = {12,11,10,9,8};

void setup() {
  int count = 0;
  while (count < total_led) {
    pinMode(ledPins[count], OUTPUT);
    count++;
  }
}


void loop() {
  int counts = 0;
  while (counts < total_led){
    if (ledPins[counts]!=9 && ledPins[counts]!=10 && ledPins[counts]!=11) {
      digitalWrite(ledPins[counts], HIGH);
      delay(1000);
    }
    else {
      int brightness = 0;
      while (brightness <= 255) {
        analogWrite(ledPins[counts], brightness);
        brightness+=5;
		delay(30);
      }
    }
    counts++;
  }
  
  while (counts >= 0) {
    if (ledPins[counts]!=9 && ledPins[counts]!=10 && ledPins[counts]!=11) {
      digitalWrite(ledPins[counts], LOW);
      delay(1000);
    }
    else {
      int brightness = 255;
      while (brightness >= 0) {
        analogWrite(ledPins[counts], brightness);
        brightness-=5;
        delay(30);
      }
    }
    counts--;
  }
}