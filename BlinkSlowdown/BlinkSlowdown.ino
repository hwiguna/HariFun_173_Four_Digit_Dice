// I wrote this to tweak the wheel of fortune style slow down rate.

unsigned long startingSpeed = 30;
unsigned long startingDeceleration = 1;
unsigned long actionDelay = 0;
unsigned long decelerationRate = 0;
byte rollPin = 2;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rollPin, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(rollPin) == LOW) {
    actionDelay = startingSpeed;
    decelerationRate = startingDeceleration;
    while (actionDelay < 200) {
      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(actionDelay);                       // wait for a second
      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
      delay(actionDelay);                       // wait for a second
      actionDelay += decelerationRate; // keep increasing actionDelay
      decelerationRate+=2;
    }

    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
}
