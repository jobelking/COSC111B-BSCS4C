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
	//checks if pin is PWM. LED ON
    if (ledPins[counts]!=9 && ledPins[counts]!=10 && ledPins[counts]!=11) {
      digitalWrite(ledPins[counts], HIGH);
      delay(1000);
    }
    else {
		//adjust brightness of PWM pins. LED ON
      int brightness = 0;
      while (brightness <= 255) {
        analogWrite(ledPins[counts], brightness);
        brightness+=5;
		delay(30);
      }
    }
    counts++;
  }
  
  counts = total_led-1;
  while (counts >= 0) {
	  //checks if pin is PWM. LED OFF
    if (ledPins[counts]!=9 && ledPins[counts]!=10 && ledPins[counts]!=11) {
      digitalWrite(ledPins[counts], LOW);
      delay(1000);
    }
    else {
		//adjust brightness of PWM pins. LED OFF
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
