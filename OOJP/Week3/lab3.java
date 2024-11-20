import java.util.Scanner;

class Publication {
    private String title;
    private String writer;
    private float cost;
    private int pageCount;

    // Constructor
    Publication(String title, String writer, float cost, int pageCount) {
        this.title = title;
        this.writer = writer;
        this.cost = cost;
        this.pageCount = pageCount;
    }

    // Getters
    String getTitle() {
        return this.title;
    }

    String getWriter() {
        return this.writer;
    }

    float getCost() {
        return this.cost;
    }

    int getPageCount() {
        return this.pageCount;
    }

    // Setters
    void setTitle(String title) {
        this.title = title;
    }

    void setWriter(String writer) {
        this.writer = writer;
    }

    void setCost(float cost) {
        this.cost = cost;
    }

    void setPageCount(int pageCount) {
        this.pageCount = pageCount;
    }

    @Override
    public String toString() {
        return "\nTitle: " + this.title + 
               "\nAuthor: " + this.writer + 
               "\nPrice: " + this.cost + 
               "\nPages: " + this.pageCount;
    }
}

class BookCatalog {
    public static void main(String[] args) {
        System.out.println("Akshat Basra 1BM23CS020");

        // Scanner to take user input
        Scanner input = new Scanner(System.in);

        // Get number of books from user
        System.out.print("How many books would you like to enter? ");
        int numberOfBooks = input.nextInt();
        Publication[] catalog = new Publication[numberOfBooks];

        // Input book details
        for (int i = 0; i < numberOfBooks; i++) {
            System.out.println("\nEntering details for Book " + (i + 1));

            System.out.print("Enter book title: ");
            String bookTitle = input.next();

            System.out.print("Enter author name: ");
            String bookAuthor = input.next();

            System.out.print("Enter book price: ");
            float bookPrice = input.nextFloat();

            System.out.print("Enter number of pages: ");
            int bookPages = input.nextInt();

            catalog[i] = new Publication(bookTitle, bookAuthor, bookPrice, bookPages);
        }

        // Output book details
        System.out.println("\n--- Book Catalog ---");
        for (int i = 0; i < numberOfBooks; i++) {
            System.out.println(catalog[i].toString());
        }

        // Close scanner to avoid resource leak
        input.close();
    }
}
