import java.util.Scanner;

class Stud_details {
    int marks[] = new int[8];
    String usn, name;
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

    void display() {
        System.out.println("USN: " + usn);
        System.out.println("Name: " + name);
        for (int i = 0; i < 8; i++) {
            System.out.println("Marks for subject " + (i + 1) + ": " + marks[i]);
        }
    }
}

class Student {
    static void main(String args[]) {
        Stud_details s1[] = new Stud_details[3];

        for (int j = 0; j < 3; j++) {
            s1[j] = new Stud_details();
        }

        for (int j = 0; j < 3; j++) {
            System.out.println("Enter the details for student " + (j + 1) + ":");
            s1[j].getdetails();
        }

        for (int j = 0; j < 3; j++) {
            s1[j].display();
        }
    }
}
