#include <iostream>
#include <windows.h>

void printProgramTitles() {
    system("wmctrl -l");
}

void changeFont(std::string programTitle, std::string newFont) {
    system(("wmctrl -r \"" + programTitle + "\" -b add,maximized_vert,maximized_horz").c_str());
    system(("xdotool type --delay 50 \"" + newFont + "\"").c_str());
    system("xdotool key --delay 50 Return");
}

int main() {
    printProgramTitles();
    std::string programTitle, newFont;
    std::cout << "Enter the program title: ";
    std::getline(std::cin, programTitle);
    std::cout << "Enter the new font: ";
    std::getline(std::cin, newFont);
    changeFont(programTitle, newFont);
    return 0;
}
