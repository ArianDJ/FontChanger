using System;
using System.Diagnostics;

class Program {
    static void Main(string[] args) {
        PrintProgramTitles();
        Console.Write("Enter the program title: ");
        string programTitle = Console.ReadLine();
        Console.Write("Enter the new font: ");
        string newFont = Console.ReadLine();
        ChangeFont(programTitle, newFont);
    }

    static void PrintProgramTitles() {
        Process process = new Process();
        process.StartInfo.FileName = "wmctrl";
        process.StartInfo.Arguments = "-l";
        process.StartInfo.UseShellExecute = false;
        process.StartInfo.RedirectStandardOutput = true;
        process.Start();
        string output = process.StandardOutput.ReadToEnd();
        process.WaitForExit();
        Console.WriteLine("Program Titles:");
        Console.WriteLine(output);
    }

    static void ChangeFont(string programTitle, string newFont) {
        Process.Start("wmctrl", "-r \"" + programTitle + "\" -b add,maximized_vert,maximized_horz");
        Process.Start("xdotool", "type --delay 50 \"" + newFont + "\"");
        Process.Start("xdotool", "key --delay 50 \"Return\"");
    }
}
