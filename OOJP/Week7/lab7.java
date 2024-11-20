import java.util.Scanner;

class NegativeAgeException extends Exception {
    int age;
    public NegativeAgeException(int age) {
        this.age = age;
    }
    @Override
    public String toString() {
        return "Negative Age: " + age;
    }
}

class InvalidAgeException extends Exception {
    int sonAge, fatherAge;
    public InvalidAgeException(int sonAge, int fatherAge) {
        this.sonAge = sonAge;
        this.fatherAge = fatherAge;
    }
    @Override
    public String toString() {
        return "Invalid Age: " + sonAge + " is greater than or equal to father's age: " + fatherAge;
    }
}

class Father {
    String name;
    int age;
    Father(String name, int age) {
        try {
            if(age < 0) {
                throw new NegativeAgeException(age);
            }
            this.name = name;
            this.age = age;
        }
        catch(NegativeAgeException e) {
            this.age = 20;
            System.out.println(e);
        }
    }
}

class Son extends Father {
    String sonName;
    int sonAge;
    Son(String sonName, int sonAge, String fatherName, int fatherAge) {
        super(fatherName, fatherAge);
        this.sonName = sonName;
        try {
            if(sonAge < 0) {
                throw new NegativeAgeException(sonAge);
            }
            if(sonAge >= fatherAge) {
                throw new InvalidAgeException(sonAge, fatherAge);
            }
            this.sonAge = sonAge;
        }
        catch(NegativeAgeException e) {
            this.sonAge = 20;
            System.out.println(e);
        }
        catch(InvalidAgeException e) {
            this.sonAge = 10;
            System.out.println(e);
        }
    }
}

class ExceptionsDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take input for Father's details
        System.out.print("Enter Father's Name: ");
        String fatherName = sc.nextLine();
        
        System.out.print("Enter Father's Age: ");
        int fatherAge = sc.nextInt();
        
        // Take input for Son's details
        sc.nextLine();  // Consume the leftover newline character after nextInt
        System.out.print("Enter Son's Name: ");
        String sonName = sc.nextLine();
        
        System.out.print("Enter Son's Age: ");
        int sonAge = sc.nextInt();

        // Create the Son object, which also creates the Father object
        Son son = new Son(sonName, sonAge, fatherName, fatherAge);

        System.out.println("Son's Age: " + son.sonAge);
        System.out.println("Father's Age: " + son.age);
    }
}
