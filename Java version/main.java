import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        printProgramTitles();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the program title: ");
        String programTitle = reader.readLine();
        System.out.print("Enter the new font: ");
        String newFont = reader.readLine();
        changeFont(programTitle, newFont);
    }

    public static void printProgramTitles() throws IOException {
        Process process = Runtime.getRuntime().exec("wmctrl -l");
        BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
        String line;
        System.out.println("Program Titles:");
        while ((line = reader.readLine()) != null) {
            System.out.println("- " + line);
        }
    }

    public static void changeFont(String programTitle, String newFont) throws IOException {
        Runtime.getRuntime().exec("wmctrl -r \"" + programTitle + "\" -b add,maximized_vert,maximized_horz");
        Runtime.getRuntime().exec("xdotool type --delay 50 \"" + newFont + "\"");
        Runtime.getRuntime().exec("xdotool key --delay 50 \"Return\"");
    }
}
