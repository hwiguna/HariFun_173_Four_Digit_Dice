// Count up 0 to 9 from right to left
// Hari Wiguna, 2019

//== Input Pins ==
byte rollButton = A5;
byte upButton = A4;
byte downButton = A3;

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

byte bitMap[] = {segmentA,segmentB,segmentC,segmentD,segmentE,segmentF,segmentG};

byte charMap[] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
};

void SetupInputs() {
  pinMode(rollButton, INPUT_PULLUP);
  pinMode(upButton, INPUT_PULLUP);
  pinMode(downButton, INPUT_PULLUP);
}

void SetupOutputs() {
  //== Setup 7-segment display ==
  pinMode(digit0, OUTPUT);   digitalWrite(digit0, LOW);
  pinMode(digit1, OUTPUT);   digitalWrite(digit1, LOW);
  pinMode(digit2, OUTPUT);   digitalWrite(digit2, LOW);
  pinMode(digit3, OUTPUT);   digitalWrite(digit3, LOW);
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

void TestDigit(byte digitPin, byte value) {
  digitalWrite(digitPin, HIGH);

  for (byte bitIndex=0; bitIndex<7; bitIndex++) { // Note that we only use bits 0-6, NOT 0-7
    digitalWrite( bitMap[bitIndex], !bitRead(charMap[value], 7-bitIndex) );
  }
  
  delay(300);
  digitalWrite(digitPin, LOW);
}

void TestDigits(byte digitPin) {
  for (byte value=0; value<10; value++) {
    TestDigit(digitPin, value);
  }
}

void setup() {
  SetupInputs();
  SetupOutputs();
}

void loop() {
  //Test7Seg();
  TestDigits(digit0);
  TestDigits(digit1);
  TestDigits(digit2);
  TestDigits(digit3);
}
