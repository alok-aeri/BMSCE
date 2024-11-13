package CIE;

import java.util.Scanner;

public class Internals extends Student {
    protected int marks[] = new int[5];  // Array for internal marks


    public void inputCIEmarks() {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter internal marks for 5 subjects:");
        for (int i = 0; i < 5; i++) {
            marks[i] = s.nextInt();
        }
    }


    public void displayCIEmarks() {
        System.out.println("Internal Marks:");
        for (int i = 0; i < 5; i++) {
            System.out.println("Subject " + (i + 1) + ": " + marks[i]);
        }
    }
}
