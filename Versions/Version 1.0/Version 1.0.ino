/*
  Project GamePad_by_EDDC
  Copyright (c) 2020 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2020
  Version: 1.0 Release
*/

#include "Keyboard.h"
#include "Mouse.h"

#define X1_AXIS A0
#define Y1_AXIS A1

#define X2_AXIS A2
#define Y2_AXIS A3

#define A_PIN 2
#define B_PIN 3
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

int range = 12;
int responseDelay = 5;
int threshold = range / 4;
int center = range / 2;

void setup()
{
    Serial.begin(9600);

    Keyboard.begin();
    Mouse.begin();
}

void loop()
{
    int xReading = readAxis(A0);
    int yReading = readAxis(A1);

    Mouse.move(xReading, yReading, 0);

    if (digitalRead(A_PIN) == HIGH)
    {
        if (!Mouse.isPressed(MOUSE_LEFT))
        {
            Mouse.press(MOUSE_LEFT);
        }
    }

    else
    {
        if (Mouse.isPressed(MOUSE_LEFT))
        {
            Mouse.release(MOUSE_LEFT);
        }
    }

    delay(responseDelay);

    if (digitalRead(B_PIN) == HIGH)
    {
        if (!Mouse.isPressed(MOUSE_RIGHT))
        {
            Mouse.press(MOUSE_RIGHT);
        }
    }

    else
    {
        if (Mouse.isPressed(MOUSE_RIGHT))
        {
            Mouse.release(MOUSE_RIGHT);
        }
    }

    delay(responseDelay);

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

int readAxis(int thisAxis)
{
    int reading = analogRead(thisAxis);
    reading = map(reading, 0, 1023, 0, range);

    int distance = reading - center;
    if (abs(distance) < threshold)
    {
        distance = 0;
    }

    return distance;
}
