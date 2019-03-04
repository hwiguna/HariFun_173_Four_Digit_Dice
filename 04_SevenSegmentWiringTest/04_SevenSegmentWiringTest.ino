// Test to make sure we understand and wired the 7-segment correctly.
// Should lit up every segment from right to left.
// Hari Wiguna, 2019

//== Input Pins ==
byte rollButton = A5;

//== Four-digit 7-Segment Display ==
byte digit0 = 2;
byte digit1 = 3;
byte digit2 = 4;
byte digit3 = 5;
byte segmentA = 12;
byte segmentB = 11;
byte segmentC = 10;
byte segmentD = 9;
byte segmentE = 8;
byte segmentF = 7;
byte segmentG = 6;

void SetupInputs() {
  pinMode(rollButton, INPUT_PULLUP);
}

void SetupOutputs() {
  //== Setup 7-segment display ==
  pinMode(digit0, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
  pinMode(digit3, OUTPUT);
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
}

void Flash(byte segmentPin) {
  digitalWrite(segmentPin, LOW);
  delay(200);
  digitalWrite(segmentPin, HIGH);
}

void FlashAtoG(byte digitPin) {
  digitalWrite(digitPin, HIGH);
  
  Flash(segmentA);
  Flash(segmentB);
  Flash(segmentC);
  Flash(segmentD);
  Flash(segmentE);
  Flash(segmentF);
  Flash(segmentG);
  
  digitalWrite(digitPin, LOW);
}

void Test7Seg() {
  FlashAtoG(digit0);
  FlashAtoG(digit1);
  FlashAtoG(digit2);
  FlashAtoG(digit3);
}

void setup() {
  SetupInputs();
  SetupOutputs();
}

void loop() {
  Test7Seg();
}
