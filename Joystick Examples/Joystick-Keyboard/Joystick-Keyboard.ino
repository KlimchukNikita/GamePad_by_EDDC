/*
  Project GamePad_by_EDDC
  Copyright (c) 2020 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2020
  Example Demo: Joystick-Keyboard
*/

#include "Keyboard.h"
#include "Mouse.h"

#define X2_AXIS A2
#define Y2_AXIS A3

void setup()
{
    Serial.begin(9600);

    Keyboard.begin();
    Mouse.begin();
}

void loop()
{
    int rotationX2;
    rotationX2 = analogRead (X2_AXIS);

    if ((rotationX2 >= 0) && (rotationX2 < 341))
    {
        Keyboard.write('w');
    }

    if ((rotationX2 >= 682) && (rotationX2 < 1023))
    {
        Keyboard.write('s');
    }

    int rotationY2;
    rotationY2 = analogRead (Y2_AXIS);

    if ((rotationY2 >= 0) && (rotationY2 < 341))
    {
        Keyboard.write('a');
    }

    if ((rotationY2 >= 682) && (rotationY2 < 1023))
    {
        Keyboard.write('d');
    }
}
