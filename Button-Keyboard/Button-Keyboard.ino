/*
  Project GamePad_by_EDDC
  Copyright (c) 2020 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2020
  Example Demo: Button-Keyboard
*/

#include "Keyboard.h"
#include "Mouse.h"

#define X_PIN 4
#define Y_PIN 5

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
}

void loop()
{
    if (digitalRead(X_PIN) == HIGH)
    {
        Keyboard.write('q');
    }

    if (digitalRead(Y_PIN) == HIGH)
    {
        Keyboard.write('e');
    }

    if (digitalRead(UP_PIN) == HIGH)
    {
        Keyboard.write('w');
    }

    if (digitalRead(DOWN_PIN) == HIGH)
    {
        Keyboard.write('s');
    }

    if (digitalRead(LEFT_PIN) == HIGH)
    {
        Keyboard.write('a');
    }

    if (digitalRead(RIGHT_PIN) == HIGH)
    {
        Keyboard.write('d');
    }

    if (digitalRead(LEFT_SW1_PIN) == HIGH)
    {
        Keyboard.write('z');
    }

    if (digitalRead(LEFT_SW2_PIN) == HIGH)
    {
        Keyboard.write('1');
    }

    if (digitalRead(RIGHT_SW1_PIN) == HIGH)
    {
        Keyboard.write('x');
    }

    if (digitalRead(RIGHT_SW2_PIN) == HIGH)
    {
        Keyboard.write('2');
    }
}
