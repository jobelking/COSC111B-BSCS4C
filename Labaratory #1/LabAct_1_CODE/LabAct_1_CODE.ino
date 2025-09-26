int  ledpins[5] = {12,11,10,9,8};

void setup() {
  for (int i=0; i<5; i++) {
    pinMode(ledpins[i], OUTPUT);
  }
}

void loop() {
  for (int x=0; x<5; x++){
    digitalWrite(ledpins[x], HIGH);
    delay(1000);
  }
  
  for (int y=0; y<5; y++){
    digitalWrite(ledpins[y], LOW);
    delay(1000);
  }
}



/* FIRST APPROACH

int ledPins1 = 12;
int ledPins2 = 11;
int ledPins3 = 10;
int ledPins4 = 9;
int ledPins5 = 8;
  
  
void setup() {
  pinMode (ledPins1, OUTPUT);
  pinMode (ledPins2, OUTPUT);
  pinMode (ledPins3, OUTPUT);
  pinMode (ledPins4, OUTPUT);
  pinMode (ledPins5, OUTPUT);
}

void loop() {
  //LED ON
  digitalWrite(ledPins1, HIGH);
  delay(1000);
  digitalWrite(ledPins2, HIGH);
  delay(1000);
  digitalWrite(ledPins3, HIGH);
  delay(1000);
  digitalWrite(ledPins4, HIGH);
  delay(1000);
  digitalWrite(ledPins5, HIGH);
  delay(1000);
  
  //LED OFF
  digitalWrite(ledPins1, LOW);
  delay(1000);
  digitalWrite(ledPins2, LOW);
  delay(1000);
  digitalWrite(ledPins3, LOW);
  delay(1000);
  digitalWrite(ledPins4, LOW);
  delay(1000);
  digitalWrite(ledPins5, LOW);
  delay(1000);
}

*/