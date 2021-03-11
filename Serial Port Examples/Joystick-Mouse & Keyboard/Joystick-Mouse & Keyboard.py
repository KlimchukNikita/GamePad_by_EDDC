import pyautogui, sys
import time
import serial

ArduinoSerial = serial.Serial('COM3', 9600)
time.sleep(1)

while 1:
    data = str(ArduinoSerial.readline())

    (position_x, position_y, button_1,
        button_2, button_3, button_4,
        button_5, button_6, button_7) = data.split(":")

    (axis_x, axis_y) = pyautogui.position()

    position_x = int(position_x)
    position_y = int(position_y)

    pyautogui.moveTo(axis_x + position_x, axis_y - position_y)

    if '1' in button_1:
        pyautogui.click(button = "left")

    if '2' in button_2:
        pyautogui.click(button = "right")

    if '3' in button_3:
        pyautogui.write("w")

    if '4' in button_4:
        pyautogui.write("a")

    if '5' in button_5:
        pyautogui.write("s")

    if '6' in button_6:
        pyautogui.write("d")

    if '7' in button_7:
        pyautogui.press("space")
