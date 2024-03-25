#include <stdio.h>
#include <windows.h>

void print_program_titles() {
    HWND hwnd = GetForegroundWindow();
    char title[256];
    GetWindowText(hwnd, title, sizeof(title));
    printf("Program Titles:\n- %s\n", title);
}

void change_font(char* program_title, char* new_font) {
    HWND hwnd = FindWindow(NULL, program_title);
    if (hwnd == NULL) {
        printf("Program not found.\n");
        return;
    }
    
    SetForegroundWindow(hwnd);
    Sleep(1000);

    SetCursorPos(100, 100);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    
    keybd_event(VK_CONTROL, 0, 0, 0);
    keybd_event(0x44, 0, 0, 0); // ASCII value of 'd'
    keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);

    Sleep(2000);

    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = 0;
    input.ki.dwFlags = KEYEVENTF_UNICODE;
    input.ki.wScan = 'A'; // ASCII value of 'A' which will be converted to the corresponding Unicode character
    SendInput(1, &input, sizeof(INPUT));
    input.ki.wScan = VK_RETURN; // Enter key
    SendInput(1, &input, sizeof(INPUT));
}

int main() {
    print_program_titles();

    char program_title[256];
    char new_font[256];
    printf("Enter the program title: ");
    fgets(program_title, sizeof(program_title), stdin);
    printf("Enter the new font: ");
    fgets(new_font, sizeof(new_font), stdin);

    change_font(program_title, new_font);
    return 0;
}
