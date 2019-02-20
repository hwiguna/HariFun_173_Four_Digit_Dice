// I wrote this to tweak the wheel of fortune style slow down rate.
// Hari Wiguna, 2019

unsigned long startingSpeed = 30;
unsigned long startingDeceleration = 1;
unsigned long actionDelay = 0;
unsigned long decelerationRate = 0;
byte rollPin = A5; // Yes, you can use Analog pins for digital read and write :-)

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rollPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(rollPin) == LOW) {
    actionDelay = startingSpeed;
    decelerationRate = startingDeceleration;
    while (actionDelay < 200) {
      digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(actionDelay);               // wait for a second
      digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
      delay(actionDelay);               // wait for a second
      actionDelay += decelerationRate;  // keep increasing actionDelay
      decelerationRate+=2;
    }

    digitalWrite(LED_BUILTIN, HIGH);    // After dice is done slowing down, we always want to end up ON.
  }
}
