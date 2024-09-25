import java.util.Scanner;

class SwapNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int first = scanner.nextInt();
        System.out.print("Enter the second number: ");
        int second = scanner.nextInt();

        int temp = first;
        first = second;
        second = temp;

        System.out.println("After swapping:");
        System.out.println("First number: " + first);
        System.out.println("Second number: " + second);

        scanner.close();
    }
}
