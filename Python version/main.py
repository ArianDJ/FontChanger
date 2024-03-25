import pygetwindow as gw
import pyautogui as pag
import time

def print_program_titles():
    all_windows = gw.getAllTitles()
    print("Program Titles:")
    for title in all_windows:
        print("-", title)

def change_font(program_title, new_font):
    program_window = gw.getWindowsWithTitle(program_title)
    if len(program_window) == 0:
        print("Program not found.")
        return
    
    window = program_window[0]
    window.activate()
    time.sleep(1)

    pag.moveTo(window.left + 10, window.top + 10)
    pag.click()

    pag.hotkey('ctrl', 'd')
    time.sleep(2)

    pag.write(new_font)
    pag.press('enter')

print_program_titles()

program_title = input("Enter the program title: ")
new_font = input("Enter the new font: ")

change_font(program_title, new_font)
