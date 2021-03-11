void setup()
{
    Serial.begin(9600);

    pinMode(2, INPUT);
    pinMode(3, INPUT);

    pinMode(4, INPUT);
    pinMode(5, INPUT);
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);

    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
}

void loop()
{
    int button_1 = 0;
    int button_2 = 0;

    int button_3 = 0;
    int button_4 = 0;
    int button_5 = 0;
    int button_6 = 0;
    int button_7 = 0;

    int axis_x = analogRead(A0);
    int axis_y = analogRead(A1);

    int position_x, position_y;

    if (axis_x > 450 and axis_x < 550)
    position_x = 0;

    if (axis_x >= 550)
    position_x = map(axis_x, 550, 1023, 0, 80);

    if (axis_x <= 450)
    position_x = map(axis_x, 450, 0, 0, -80);

    if (axis_y > 450 and axis_y < 550)
    position_y = 0;

    if (axis_y >= 550)
    position_y = map(axis_y, 550, 1023, 0, 80);

    if (axis_y <= 450)
    position_y = map(axis_y, 450, 0, 0, -80);

    if (digitalRead(2) == LOW)
    button_1 = 1;

    else
    button_1 = 0;

    if (digitalRead(3) == LOW)
    button_2 = 2;

    else
    button_2 = 0;

    if (digitalRead(4) == LOW)
    button_3 = 3;

    else
    button_3 = 0;

    if (digitalRead(5) == LOW)
    button_4 = 4;

    else
    button_4 = 0;

    if (digitalRead(6) == LOW)
    button_5 = 5;

    else
    button_5 = 0;

    if (digitalRead(7) == LOW)
    button_6 = 6;

    else
    button_6 = 0;

    if (digitalRead(8) == LOW)
    button_7 = 7;

    else
    button_7 = 0;

    Serial.print(position_x);
    Serial.print(":");

    Serial.print(position_y);
    Serial.print(":");

    Serial.print(button_1);
    Serial.print(":");

    Serial.print(button_2);
    Serial.print(":");

    Serial.print(button_3);
    Serial.print(":");

    Serial.print(button_4);
    Serial.print(":");

    Serial.print(button_5);
    Serial.print(":");

    Serial.print(button_6);
    Serial.print(":");

    Serial.println(button_7);
    delay(120);
}
