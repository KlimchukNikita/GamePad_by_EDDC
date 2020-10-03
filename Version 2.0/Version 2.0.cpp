/*
  Project GamePad_by_EDDC
  Copyright (c) 2020 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2020
  Version: 2.0 Release
*/

#include "Keyboard.h"
#include "Mouse.h"
#include "SPI.h"

#define X1_AXIS A0
#define Y1_AXIS A1

#define X2_AXIS A2
#define Y2_AXIS A3

#define LEFT_SW1_PIN 8
#define LEFT_SW2_PIN 16

#define RIGHT_SW1_PIN 9
#define RIGHT_SW2_PIN 10

#define MAIN_SW_PIN 7

#define MOTOR1_PIN 2
#define MOTOR2_PIN 3
#define MOTOR3_PIN 4
#define MOTOR4_PIN 5

int range = 12;
int responseDelay = 5;
int threshold = range / 4;
int center = range / 2;

enum { REG_LATCH = 6 };

void setup()
{
    Serial.begin(9600);

    Keyboard.begin();
    Mouse.begin();
    SPI.begin();

    pinMode (MOTOR1_PIN, OUTPUT);
    pinMode (MOTOR2_PIN, OUTPUT);
    pinMode (MOTOR3_PIN, OUTPUT);
    pinMode (MOTOR4_PIN, OUTPUT);

    pinMode(REG_LATCH, OUTPUT);
    digitalWrite(REG_LATCH, HIGH);
}

void loop()
{
    int xReading = readAxis(A0);
    int yReading = readAxis(A1);

    Mouse.move(xReading, yReading, 0);

    int rotationX2;
    rotationX2 = analogRead (X2_AXIS);

    if ((rotationX2 >= 0) && (rotationX2 < 341))
    {
        Keyboard.write('w');
        digitalWrite(MOTOR1_PIN, HIGH);
        digitalWrite(MOTOR2_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
        digitalWrite(MOTOR2_PIN, LOW);
    }

    if ((rotationX2 >= 682) && (rotationX2 < 1023))
    {
        Keyboard.write('s');
        digitalWrite(MOTOR3_PIN, HIGH);
        digitalWrite(MOTOR4_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR3_PIN, LOW);
        digitalWrite(MOTOR4_PIN, LOW);
    }

    int rotationY2;
    rotationY2 = analogRead (Y2_AXIS);

    if ((rotationY2 >= 0) && (rotationY2 < 341))
    {
        Keyboard.write('a');
        digitalWrite(MOTOR1_PIN, HIGH);
        digitalWrite(MOTOR3_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
        digitalWrite(MOTOR3_PIN, LOW);
    }

    if ((rotationY2 >= 682) && (rotationY2 < 1023))
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
        Keyboard.write('1');
        digitalWrite(MOTOR1_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
    }

    if (digitalRead(LEFT_SW2_PIN) == HIGH)
    {
        Keyboard.write('2');
        digitalWrite(MOTOR1_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
    }

    if (digitalRead(RIGHT_SW1_PIN) == HIGH)
    {
        Keyboard.write('3');
        digitalWrite(MOTOR2_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR2_PIN, LOW);
    }

    if (digitalRead(RIGHT_SW2_PIN) == HIGH)
    {
        Keyboard.write('4');
        digitalWrite(MOTOR2_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR2_PIN, LOW);
    }

    static uint8_t last_input_states = 0;
    
    digitalWrite(REG_LATCH, LOW);
    digitalWrite(REG_LATCH, HIGH);
    
    uint8_t states = SPI.transfer(0);

    uint8_t changed = states ^ last_input_states;
    last_input_states = states;

    for (int i = 0; i < 8; ++i)
    {
        if (changed & 1)
        {
            if (i == 0)
            {
                Keyboard.write('w');
                digitalWrite(MOTOR1_PIN, HIGH);
                digitalWrite(MOTOR2_PIN, HIGH);
                delay(50);
                digitalWrite(MOTOR1_PIN, LOW);
                digitalWrite(MOTOR2_PIN, LOW);
            }

            if (i == 1)
            {
                Keyboard.write('s');
                digitalWrite(MOTOR3_PIN, HIGH);
                digitalWrite(MOTOR4_PIN, HIGH);
                delay(50);
                digitalWrite(MOTOR3_PIN, LOW);
                digitalWrite(MOTOR4_PIN, LOW);
            }

            if (i == 2)
            {
                Keyboard.write('a');
                digitalWrite(MOTOR1_PIN, HIGH);
                digitalWrite(MOTOR3_PIN, HIGH);
                delay(50);
                digitalWrite(MOTOR1_PIN, LOW);
                digitalWrite(MOTOR3_PIN, LOW);
            }

            if (i == 3)
            {
                Keyboard.write('d');
                digitalWrite(MOTOR2_PIN, HIGH);
                digitalWrite(MOTOR4_PIN, HIGH);
                delay(50);
                digitalWrite(MOTOR2_PIN, LOW);
                digitalWrite(MOTOR4_PIN, LOW);
            }

            if (i == 4)
            {
                Keyboard.write('q');
                digitalWrite(MOTOR1_PIN, HIGH);
                delay(50);
                digitalWrite(MOTOR1_PIN, LOW);
            }

            if (i == 5)
            {
                Keyboard.write('e');
                digitalWrite(MOTOR1_PIN, HIGH);
                delay(50);
                digitalWrite(MOTOR1_PIN, LOW);
            }

            if (i == 6)
            {
                Keyboard.write('z');
                digitalWrite(MOTOR2_PIN, HIGH);
                delay(50);
                digitalWrite(MOTOR2_PIN, LOW);
            }

            if (i == 7)
            {
                Keyboard.write('x');
                digitalWrite(MOTOR2_PIN, HIGH);
                delay(50);
                digitalWrite(MOTOR2_PIN, LOW);
            }
        }

        changed >>= 1;
        states >>= 1;
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
