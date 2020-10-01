/*
  Project GamePad_by_EDDC
  Copyright (c) 2020 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2020
  Example Demo: Button-Keyboard-Motor
*/

#include "Keyboard.h"
#include "Mouse.h"

#define MOTOR1_PIN 2
#define MOTOR2_PIN 3
#define MOTOR3_PIN 4
#define MOTOR4_PIN 5

#define UP_PIN 6
#define DOWN_PIN 7
#define LEFT_PIN 8
#define RIGHT_PIN 9

#define LEFT_SW1_PIN 10
#define LEFT_SW2_PIN 16

#define RIGHT_SW1_PIN 14
#define RIGHT_SW2_PIN 15

void setup()
{
    Serial.begin(9600);

    Keyboard.begin();
    Mouse.begin();

    pinMode (MOTOR1_PIN, OUTPUT);
    pinMode (MOTOR2_PIN, OUTPUT);
    pinMode (MOTOR3_PIN, OUTPUT);
    pinMode (MOTOR4_PIN, OUTPUT);
}

void loop()
{
    if (digitalRead(UP_PIN) == HIGH)
    {
        Keyboard.write('w');
        digitalWrite(MOTOR1_PIN, HIGH);
        digitalWrite(MOTOR2_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
        digitalWrite(MOTOR2_PIN, LOW);
    }

    if (digitalRead(DOWN_PIN) == HIGH)
    {
        Keyboard.write('s');
        digitalWrite(MOTOR3_PIN, HIGH);
        digitalWrite(MOTOR4_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR3_PIN, LOW);
        digitalWrite(MOTOR4_PIN, LOW);
    }

    if (digitalRead(LEFT_PIN) == HIGH)
    {
        Keyboard.write('a');
        digitalWrite(MOTOR1_PIN, HIGH);
        digitalWrite(MOTOR3_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
        digitalWrite(MOTOR3_PIN, LOW);
    }

    if (digitalRead(RIGHT_PIN) == HIGH)
    {
        Keyboard.write('d');
        digitalWrite(MOTOR2_PIN, HIGH);
        digitalWrite(MOTOR4_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR2_PIN, LOW);
        digitalWrite(MOTOR4_PIN, LOW);
    }

    if (digitalRead(LEFT_SW1_PIN) == HIGH)
    {
        Keyboard.write('z');
        digitalWrite(MOTOR1_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
    }

    if (digitalRead(LEFT_SW2_PIN) == HIGH)
    {
        Keyboard.write('1');
        digitalWrite(MOTOR1_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
    }

    if (digitalRead(RIGHT_SW1_PIN) == HIGH)
    {
        Keyboard.write('x');
        digitalWrite(MOTOR2_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR2_PIN, LOW);
    }

    if (digitalRead(RIGHT_SW2_PIN) == HIGH)
    {
        Keyboard.write('2');
        digitalWrite(MOTOR2_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR2_PIN, LOW);
    }
}
