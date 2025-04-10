const int redButton = 13;
const int redLed = 12;
const int greenButton = 11;
const int greenLed = 10;
const int lockTime = 5000;

bool gameLocked = false;

unsigned long startTime = 0;

void setup() {
  pinMode(redButton, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenButton, INPUT);
  pinMode(greenLed, OUTPUT);
}

void loop() {
  if (!gameLocked) {
    if (digitalRead(redButton) == HIGH) {
      digitalWrite(redLed, HIGH);
      gameLocked = true;
      startTime = millis();
    }
    else if (digitalRead(greenButton) == HIGH) {
      digitalWrite(greenLed, HIGH);
      gameLocked = true;
      startTime = millis();
    }
  }
  else if (millis() - startTime >= lockTime) {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    gameLocked = false;
  }
}
