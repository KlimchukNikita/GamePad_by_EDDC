/*
  Project GamePad_by_EDDC
  Copyright (c) 2020 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2020
  Example Demo: Button-Register-Serial
*/

#include "SPI.h"

enum { REG_LATCH = 8 };

void setup()
{
    Serial.begin(9600);
    SPI.begin();

    pinMode(REG_LATCH, OUTPUT);
    digitalWrite(REG_LATCH, HIGH);
}

void loop()
{
    static uint8_t last_input_states = 0;
    
    digitalWrite(REG_LATCH, LOW);
    digitalWrite(REG_LATCH, HIGH);
    
    uint8_t states = SPI.transfer(0);
    
    if (states != last_input_states)
    {
        uint8_t changed = states ^ last_input_states;
        last_input_states = states;
        
        for (int i = 0; i < 8; ++i)
        {
            if (changed & 1)
            {
                Serial.print("#");
                Serial.print(i);
                Serial.print(" -> ");
                Serial.println(states & 1);
            }
            
            changed >>= 1;
            states >>= 1;
        }
    }
}
