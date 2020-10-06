/*
  Project GamePad_by_EDDC
  Copyright (c) 2020 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2020
  Example Demo: Button-Register-Keyboard
*/

#include "SPI.h"
#include "Keyboard.h"

enum { REG_LATCH = 6 };

void setup()
{
    Serial.begin(9600);
    SPI.begin();
    Keyboard.begin();

    pinMode(REG_LATCH, OUTPUT);
    digitalWrite(REG_LATCH, HIGH);
}

void loop()
{
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
            }

            if (i == 1)
            {
                Keyboard.write('s');
            }

            if (i == 2)
            {
                Keyboard.write('a');
            }

            if (i == 3)
            {
                Keyboard.write('d');
            }

            if (i == 4)
            {
                Keyboard.write('q');
            }

            if (i == 5)
            {
                Keyboard.write('e');
            }

            if (i == 6)
            {
                Keyboard.write('z');
            }

            if (i == 7)
            {
                Keyboard.write('x');
            }
        }

        changed >>= 1;
        states >>= 1;
    }
}
