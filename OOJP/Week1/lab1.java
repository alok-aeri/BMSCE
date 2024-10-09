import java.util.Scanner;

class EquationSolver {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("a: ");
        double a = scanner.nextDouble();
        
        System.out.print("b: ");
        double b = scanner.nextDouble();
        
        System.out.print("c: ");
        double c = scanner.nextDouble();
        
        double d = (b * b)- (4 * a * c);
        
        if (d > 0) {
            double r1 = (-b + Math.sqrt(d)) / (2 * a);
            double r2 = (-b - Math.sqrt(d)) / (2 * a);
            System.out.println("The roots are distinct and real:");
            System.out.println("Root 1: " + r1);
            System.out.println("Root 2: " + r2);
        } else if (d == 0) {
            double root = -b / (2 * a);
            System.out.println("The roots are equal and real:");
            System.out.println("which is: " + root);
        } else {
            System.out.println("The roots are complex:");
            double r10 = -b / (2 * a);
            double r20 = Math.sqrt(-d) / (2 * a);
            System.out.println("Root 1: " + r10 + " + " + r20 + "i");
            System.out.println("Root 2: " + r10 + " - " + r20 + "i");
        }
        
        scanner.close();
    }
}
