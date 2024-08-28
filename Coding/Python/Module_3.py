# String Immutable and string methods

name='sakib\'s khan'
print(name)

# tuples and tuples methods in python
def multiple():
    return 3,4
things='pen','truepf','dfsfa','dsfsf'
print(things[0])


from time import sleep
import pyautogui

sleep(5)
for i in range (0,3):
    pyautogui.write("Ki Koros", interval=0.25)
    pyautogui.press('enter')

import cv2
cam=cv2.VideoCapture(0)
while True:
    _, frame=cam.read()
    cv2.imshow('My cam',frame)
    cv2.waitKey(1)


num = lambda a:a*a
print(num(2**2))