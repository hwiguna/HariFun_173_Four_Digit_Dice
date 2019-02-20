// Blink three times everytime user presses the button
// Hari Wiguna, 2019

byte rollPin = A5; // Yes, you can use Analog pins for digital read and write :-)

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rollPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(rollPin) == LOW) {
    for (byte i=0; i<3; i++) {
      digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(250);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
      delay(250);                       // wait for a second
    }
  }
}
