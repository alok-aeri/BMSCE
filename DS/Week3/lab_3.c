#include <stdio.h>
#define MAX 5

int que[MAX];
int top = -1;
int bottom = -1;

int full() {
    return bottom == MAX - 1;
}

int empty() {
    return top == -1 || top > bottom;
}

void add(int x) {
    if (full()) {
        printf("The Queue is full currently\n");
        return;
    }
    if (empty()) {
        top = 0;
    }
    bottom++;
    que[bottom] = x;
    printf("Added: %i\n", x);
}

int remove() {
    if (empty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = que[top];
    top++;
    if (top > bottom) {
        top = bottom = -1;
    }
    return item;
}

void display() {
    if (empty()) {
        printf("The Queue is empty\n");
    } else {
        for (int i = top; i <= bottom; i++) {
            printf("Element %i: %i\n", i, que[i]);
        }
    }
}

int main(void) {
    int in, x;
    while (1) {
        printf("1: Add\n2: Delete\n3: Display\n4: Exit\n");
        if (scanf("%i", &in) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch(in) {
            case 1:
                printf("Element to add: ");
                if (scanf("%i", &x) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    break;
                }
                add(x);
                break;
            case 2:
                x = remove();
                if (x != -1) {
                    printf("Removed element: %i\n", x);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Option\n");
        }
    }
}
