#include <stdio.h>
#define MAX 4

int cirq[MAX], front = -1, rear = -1, item;

void insert();
int delete();
void display();

void main() {
    int ch;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                item = delete();
                if (item != -1) {
                    printf("Deleted element is %d\n", item);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

void insert() {
    if ((rear + 1) % MAX == front) {
        printf("Circular queue is full\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    printf("Enter element to be inserted: ");
    scanf("%d", &item);
    cirq[rear] = item;
}

int delete() {
    if (front == -1) {
        printf("Circular queue is empty\n");
        return -1;
    }
    item = cirq[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return item;
}

void display() {
    if (front == -1) {
        printf("Circular queue is empty\n");
        return;
    }
    printf("Circular queue contains:\n");
    if (front <= rear) {
        for (int i = front; i <= rear; i++) {
            printf("%d\t", cirq[i]);
        }
    } else {
        for (int i = front; i < MAX; i++) {
            printf("%d\t", cirq[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d\t", cirq[i]);
        }
    }
    printf("\n");
}
