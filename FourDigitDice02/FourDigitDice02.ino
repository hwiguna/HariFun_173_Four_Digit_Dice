
unsigned long actionDelay = 0;
unsigned long timeForAction;
unsigned long decelerationRate = 5;
unsigned long kount;

byte ledPin =13;

void setup() {
  //Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  if (millis() >= timeForAction) {
    //== Time for action! ==
    digitalWrite(ledPin,LOW);
    delay(50);
    digitalWrite(ledPin,HIGH);
    //int rnd = random(1,7);
    //Serial.print(rnd); // Show the action
    //Serial.print("  ");
    //if ( (++kount % 16)== 0) Serial.println();
    actionDelay += decelerationRate; // keep increasing actionDelay
    timeForAction = millis() + actionDelay; // Set for next time
  }
}

