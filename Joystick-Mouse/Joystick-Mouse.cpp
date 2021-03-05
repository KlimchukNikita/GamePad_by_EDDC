void setup()
{
    Serial.begin(9600);

    pinMode(2, INPUT);
    digitalWrite(2, HIGH);
}

void loop()
{
    int button_1 = 0;

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

    Serial.print(position_x);
    Serial.print(":");

    Serial.print(position_y);
    Serial.print(":");

    Serial.println(button_1);
    delay(120);
}
