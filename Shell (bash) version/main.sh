#!/bin/bash

print_program_titles() {
    wmctrl -l
}

change_font() {
    program_title="$1"
    new_font="$2"
    
    wmctrl -r "$program_title" -b add,maximized_vert,maximized_horz
    xdotool type --delay 50 "$new_font"
    xdotool key --delay 50 "Return"
}

print_program_titles

read -p "Enter the program title: " program_title
read -p "Enter the new font: " new_font

change_font "$program_title" "$new_font"
