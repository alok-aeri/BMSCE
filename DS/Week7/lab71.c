#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node* NODE;

NODE newnode() {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    return new_node;
}

NODE insert_end(int item, NODE first) {
    NODE new_end = newnode();
    new_end->value = item;
    new_end->next = NULL;

    if (first == NULL) {
        return new_end;
    }

    NODE current = first;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_end;
    return first;
}

NODE reverse(NODE first) {
    NODE current = NULL, temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        temp->next = current;
        current = temp;
    }
    return current;
}

NODE concatenate(NODE first_1, NODE first_2) {
    if (first_1 == NULL) {
        return first_2;
    }
    if (first_2 == NULL) {
        return first_1;
    }

    NODE last1 = first_1;
    while (last1->next != NULL) {
        last1 = last1->next;
    }
    last1->next = first_2;
    return first_1;
}

NODE sort(NODE first) {
    if (first == NULL || first->next == NULL) {
        return first;
    }

    NODE temp1, temp2;
    int swapped;

    do {
        swapped = 0;
        temp1 = first;
        while (temp1->next != NULL) {
            temp2 = temp1->next;
            if (temp1->value > temp2->value) {
                int temp = temp1->value;
                temp1->value = temp2->value;
                temp2->value = temp;
                swapped = 1;
            }
            temp1 = temp1->next;
        }
    } while (swapped);

    return first;
}

void display(NODE first) {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    NODE temp = first;
    while (temp != NULL) {
        printf("%d\t", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    NODE first_1 = NULL;
    NODE first_2 = NULL;
    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert in linked list 1\n");
        printf("2. Insert in linked list 2\n");
        printf("3. Sort linked list 1\n");
        printf("4. Sort linked list 2\n");
        printf("5. Reverse linked list 1\n");
        printf("6. Reverse linked list 2\n");
        printf("7. Concatenate the two linked lists\n");
        printf("8. Display LL 1\n");
        printf("9. Display LL 2\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                first_1 = insert_end(item, first_1);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                first_2 = insert_end(item, first_2);
                break;
            case 3:
                printf("Sorted Linked list 1\n");
                first_1 = sort(first_1);
                break;
            case 4:
                printf("Sorted Linked list 2\n");
                first_2 = sort(first_2);
                break;
            case 5:
                printf("Linked list 1 reversed\n");
                first_1 = reverse(first_1);
                break;
            case 6:
                printf("Linked list 2 reversed\n");
                first_2 = reverse(first_2);
                break;
            case 7:
                first_1 = concatenate(first_1, first_2);
                printf("Lists concatenated\n");
                break;
            case 8:
                printf("Linked list 1: ");
                display(first_1);
                break;
            case 9:
                printf("Linked list 2: ");
                display(first_2);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
