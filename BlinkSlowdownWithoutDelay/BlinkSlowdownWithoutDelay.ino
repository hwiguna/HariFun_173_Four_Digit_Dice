// I wrote this to tweak the wheel of fortune style slow down rate.

unsigned long startingSpeed = 30;
unsigned long startingDeceleration = 1;
unsigned long actionDelay = 0;
unsigned long decelerationRate = 0;
byte rollPin = 2;

#define IS_IDLE 0
#define IS_PRESSED 1
#define LED_ON 2
#define LED_OFF 3
byte state = IS_IDLE;

unsigned long timeForAction;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rollPin, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  switch (state) {
    case IS_IDLE:
        if (digitalRead(rollPin) == LOW) {
          actionDelay = startingSpeed;
          decelerationRate = startingDeceleration;
          timeForAction = millis() + actionDelay; // When we should turn OFF the LED
          digitalWrite(LED_BUILTIN,HIGH);
          state = LED_ON;
        }
    break;
    
    case LED_ON:
      if (millis() >= timeForAction) {
          timeForAction = millis() + actionDelay; // When we should turn ON the LED
          actionDelay += decelerationRate; // keep increasing actionDelay
          decelerationRate+=2;
          digitalWrite(LED_BUILTIN, LOW);
          state = LED_OFF;
      }
    break;
    
    case LED_OFF:
      if (millis() >= timeForAction) {
          timeForAction = millis() + actionDelay; // When we should turn ON the LED
          actionDelay += decelerationRate; // keep increasing actionDelay
          decelerationRate+=2;
          digitalWrite(LED_BUILTIN, HIGH);

          if (actionDelay < 400) 
            state = LED_ON;
          else
            state = IS_IDLE;
      }
      break;
  }

}
