abstract class Shape {
    double dimension1, dimension2;

    Shape(double x, double y) {
        dimension1 = x;
        dimension2 = y;
    }

    abstract double computeArea();
}

class RectangleShape extends Shape {
    RectangleShape(double x, double y) {
        super(x, y);
    }

    double computeArea() {
        System.out.println("Computing area for Rectangle.");
        return dimension1 * dimension2;
    }
}

class TriangleShape extends Shape {
    TriangleShape(double x, double y) {
        super(x, y);
    }

    double computeArea() {
        System.out.println("Computing area for Triangle.");
        return dimension1 * dimension2 / 2;
    }
}

class CircleShape extends Shape {
    CircleShape(double x, double y) {
        super(x, y);
    }

    double computeArea() {
        System.out.println("Computing area for Circle.");
        return 3.14 * dimension1 * dimension1;
    }
}

class ShapeAreaCalculator {
    public static void main(String[] args) {
        System.out.println("Akshat Basra 1BM23CS020");

        RectangleShape rect = new RectangleShape(9, 5);
        TriangleShape tri = new TriangleShape(10, 8);
        CircleShape circ = new CircleShape(10, 10);

        Shape shapeRef;

        shapeRef = rect;
        System.out.println("Area: " + shapeRef.computeArea());

        shapeRef = tri;
        System.out.println("Area: " + shapeRef.computeArea());

        shapeRef = circ;
        System.out.println("Area: " + shapeRef.computeArea());
    }
}
