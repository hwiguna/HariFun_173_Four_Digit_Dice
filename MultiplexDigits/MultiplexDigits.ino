#include <TimerOne.h>

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

byte digitMap[] = {digit0, digit1, digit2, digit3};
byte segmentMap[] = {segmentA, segmentB, segmentC, segmentD, segmentE, segmentF, segmentG};

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

volatile unsigned long curValue = 0;
volatile byte curDigitIndex = 0;

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

void DrawDigit(byte value) {
  for (byte bitIndex = 0; bitIndex < 7; bitIndex++) { // Note that we only use bits 0-6, NOT 0-7
    digitalWrite( segmentMap[bitIndex], !bitRead(charMap[value], 7 - bitIndex) );
  }
}

void RefreshDigit() {
  // Note that curDigitIndex zero is rightmost on the display (least significant digit)
  digitalWrite(digitMap[curDigitIndex], LOW); // Turn off previous digit
  
  curDigitIndex++ ;// What's the next digit?
  if (curDigitIndex > 3) curDigitIndex = 0; // Cycle back to zero if we're about to go beyond the four digits of our display
  
  String curValueStr = "0000" + String(curValue); // Left pad with zeroes, to make sure we're at least 4 digits
  int digitValue = curValueStr.charAt( curValueStr.length()-1-curDigitIndex) - '0'; // What's the value of digit at position curDigitIndex?
  DrawDigit(digitValue); // Draw value at curDigitIndex
  
  digitalWrite(digitMap[curDigitIndex], HIGH); // Turn ON current digit
}

void CountUpTest() {
  for (int i = 0; i < 10000; i++) {
    noInterrupts();
    curValue = i;
    interrupts();
    delay(10);
  }
}
void setup() {
  SetupInputs();
  SetupOutputs();

  //-- Setup Timer --
  Timer1.initialize(4000); // in microseconds
  Timer1.attachInterrupt(RefreshDigit);
}

void loop() {
  CountUpTest();
}
