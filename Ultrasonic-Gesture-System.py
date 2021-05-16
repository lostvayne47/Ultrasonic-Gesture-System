import serial 
import time 
import pyautogui

ArduinoSerial = serial.Serial('com5',9600) 
time.sleep(1) 
while 1:
    incoming = str (ArduinoSerial.readline()) 
    print (incoming)
    
    if 'Play/Pause' in incoming:
        pyautogui.typewrite(['space'], 0.2)

    if 'Rewind' in incoming:
        #pyautogui.hotkey('ctrl', 'left') 
        #pyautogui.hotkey('fn', 'pgdn') 
        pyautogui.press('volumedown')

    if 'Forward' in incoming:
        #pyautogui.hotkey('ctrl', 'right')
        #pyautogui.hotkey('fn', 'pgup')
        pyautogui.press('volumeup')      

    if 'Vup' in incoming: 
        pyautogui.scroll(100)    
        
    if 'Vdown' in incoming:
        pyautogui.scroll(-100) 

    incoming = "" 