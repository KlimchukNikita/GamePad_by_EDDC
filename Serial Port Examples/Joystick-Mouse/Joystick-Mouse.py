import pyautogui, sys
import time
import serial

ArduinoSerial = serial.Serial('COM3', 9600)
time.sleep(1)

while 1:
    data = str(ArduinoSerial.readline())

    (position_x, position_y, button_1) = data.split(":")
    (axis_x, axis_y) = pyautogui.position()

    position_x = int(position_x)
    position_y = int(position_y)

    pyautogui.moveTo(axis_x + position_x, axis_y - position_y)

    if '1' in button_1:
        pyautogui.click(button = "left")
