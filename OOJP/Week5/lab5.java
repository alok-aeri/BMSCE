import java.util.Scanner;
import java.lang.Math;

class Account {
    int accountID;
    double accountBalance;

    Account(int accountID) {
        this.accountID = accountID;
        this.accountBalance = 0;
    }

    void addFunds(double amount) {
        this.accountBalance += amount;
    }

    void removeFunds(double amount) {
        this.accountBalance -= amount;
    }

    double calculateInterest(double rate, int duration) {
        System.out.println("Interest is not applicable for this account type.");
        return 0.0;
    }
}

class Savings extends Account {
    Savings(int accountID) {
        super(accountID);
    }

    double calculateInterest(double rate, int duration) {
        double interestAmount = (accountBalance * Math.pow((1 + (rate / 100)), duration)) - accountBalance;
        accountBalance += interestAmount;
        return interestAmount;
    }
}

class Current extends Account {
    static double maxWithdrawalLimit = 1000;

    Current(int accountID) {
        super(accountID);
    }

    public void removeFunds(double amount) {
        super.accountBalance -= amount;
        if (accountBalance < maxWithdrawalLimit) {
            System.out.println("Withdrawal limit reached - Applying service charge.");
            accountBalance -= 100;
        }
    }
}

class BankOperations {
    public static void main(String[] args) {
        System.out.println("Akshat Basra 1BM23CS020");
        double amount;
        Scanner scanner = new Scanner(System.in);

        System.out.print("1. Open Savings Account\n2. Open Current Account\n\nChoose an option: ");
        int option = scanner.nextInt();

        Account account;
        if (option == 1) {
            account = new Savings(101);
        } else {
            account = new Current(201);
        }

        System.out.println("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Compute Interest\n5. Exit");
        while (true) {
            System.out.print("Enter your choice: ");
            option = scanner.nextInt();

            switch (option) {
                case 1:
                    System.out.print("Enter deposit amount: ");
                    amount = scanner.nextDouble();
                    account.addFunds(amount);
                    break;
                case 2:
                    System.out.print("Enter withdrawal amount: ");
                    amount = scanner.nextDouble();
                    account.removeFunds(amount);
                    break;
                case 3:
                    System.out.println("Current balance: " + account.accountBalance);
                    break;
                case 4:
                    System.out.println("Calculated interest: " + account.calculateInterest(5, 1));
                    break;
                default:
                    System.exit(0);
            }
        }
    }
}
