import java.util.Scanner;

class Stud_details {
    int marks[] = new int[8];
    String usn, name;
    int sum = 0;
    float sgpa = 0;
    Scanner sc = new Scanner(System.in);

    void getdetails() {
        System.out.println("Enter the USN:");
        usn = sc.next();
        System.out.println("Enter the name:");
        name = sc.next();
        System.out.println("Enter the marks for 8 subjects:");
        for (int i = 0; i < 8; i++) {
            marks[i] = sc.nextInt();
        }
    }

    void calci() {
        sum = 0;
        for (int i = 0; i < 8; i++) {
            if (i < 2) {
                sum += (marks[i] * 4);
            } else if (i < 5) {
                sum += (marks[i] * 3);
            } else {
                sum += marks[i];
            }
        }
        sgpa = (float)sum / 20;
        System.out.println("GPA = " + sgpa);
    }

    void display() {
        System.out.println("USN: " + usn);
        System.out.println("Name: " + name);
        for (int i = 0; i < 8; i++) {
            System.out.println("Marks for subject " + (i + 1) + ": " + marks[i]);
        }
    }
}

public class Student {
    public static void main(String args[]) {
        Stud_details s1[] = new Stud_details[3];

        for (int j = 0; j < 3; j++) {
            s1[j] = new Stud_details();
        }

        for (int j = 0; j < 3; j++) {
            System.out.println("Enter the details for student " + (j + 1) + ":");
            s1[j].getdetails();
        }

        for (int j = 0; j < 3; j++) {
            s1[j].calci();
        }
        
        for (int j = 0; j < 3; j++) {
            s1[j].display();
        }
    }
}
