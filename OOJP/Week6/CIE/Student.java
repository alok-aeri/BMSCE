package CIE;

import java.util.Scanner;

public class Student {

    protected String usn;
    protected String name;
    protected int sem;

    Scanner sc = new Scanner(System.in);

    public void inputStudentDetails() {
        System.out.println("Enter the USN:");
        usn = sc.next();
        System.out.println("Enter the name:");
        name = sc.next();
        System.out.println("Enter the semester:");
        sem = sc.nextInt();
    }

    public void displayStudentDetails() {
        System.out.println("USN: " + usn);
        System.out.println("Name: " + name);
        System.out.println("Semester: " + sem);
    }
}
