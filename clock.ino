
#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68
#define INTENSITY 1
#define DELAY 5

#define SegA 2
#define SegB 3
#define SegC 4
#define SegD 5
#define SegE 6
#define SegF 7
#define SegG 8

#define Dig1 9
#define Dig2 10
#define Dig3 11
#define Dig4 12

byte numberConfig[10][7] =  {\
  {1,1,1,1,1,1,0},\
  {0,1,1,0,0,0,0},\
  {1,1,0,1,1,0,1},\
  {1,1,1,1,0,0,1},\
  {0,1,1,0,0,1,1},\
  {1,0,1,1,0,1,1},\
  {0,0,1,1,1,1,1},\
  {1,1,1,0,0,0,0},\
  {1,1,1,1,1,1,1},\
  {1,1,1,0,0,1,1}\
};

void setup() {
  Wire.begin();
  
  Serial.begin(9600);
  pinMode(SegA, OUTPUT);
  digitalWrite(SegA, LOW);
  pinMode(SegB, OUTPUT);
  digitalWrite(SegB, LOW);
  pinMode(SegC, OUTPUT);
  digitalWrite(SegC, LOW);
  pinMode(SegD, OUTPUT);
  digitalWrite(SegD, LOW);
  pinMode(SegE, OUTPUT);
  digitalWrite(SegE, LOW);
  pinMode(SegF, OUTPUT);
  digitalWrite(SegF, LOW);
  pinMode(SegG, OUTPUT);
  digitalWrite(SegG, LOW);
  
  pinMode(Dig1, OUTPUT);
  digitalWrite(Dig1, HIGH);
  pinMode(Dig2, OUTPUT);
  digitalWrite(Dig2, HIGH);
  pinMode(Dig3, OUTPUT);
  digitalWrite(Dig3, HIGH);
  pinMode(Dig4, OUTPUT);
  digitalWrite(Dig4, HIGH);

  setDS3231time(0,30,7,7,25,10,2015); // seconds, minutes, hours, day, date, month, year
}

void loop() {
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;

  readDS3231time(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);

  int h1, h2, m1, m2;
  h1 = hour / 10;
  h2 = hour % 10;
  m1 = minute / 10;
  m2 = minute % 10;
  
  flashDigit(h1, Dig1, INTENSITY);
  flashDigit(h2, Dig2, INTENSITY);
  flashDigit(m1, Dig3, INTENSITY);
  flashDigit(m2, Dig4, INTENSITY);

  delay(DELAY);
}
