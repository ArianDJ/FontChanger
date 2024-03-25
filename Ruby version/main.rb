def print_program_titles
    puts `wmctrl -l`
end

def change_font(program_title, new_font)
    `wmctrl -r "#{program_title}" -b add,maximized_vert,maximized_horz`
    `xdotool type --delay 50 "#{new_font}"`
    `xdotool key --delay 50 "Return"`
end

print_program_titles
print "Enter the program title: "
program_title = gets.chomp
print "Enter the new font: "
new_font = gets.chomp

change_font(program_title, new_font)
