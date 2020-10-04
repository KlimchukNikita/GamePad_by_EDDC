/*
  Project GamePad_by_EDDC
  Copyright (c) 2020 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2020
  Example Demo: Joystick-Mouse
*/

#include "Keyboard.h"
#include "Mouse.h"

#define X1_AXIS A0
#define Y1_AXIS A1

#define A_PIN 2
#define B_PIN 3

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
