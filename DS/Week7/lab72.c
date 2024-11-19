#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node* NODE;

NODE newnode(int item) {
    NODE new_node = (NODE)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->value = item;
    new_node->next = NULL;
    return new_node;
}

NODE push(NODE top, int item) {
    NODE new_top = newnode(item);
    new_top->next = top;
    return new_top;
}

NODE pop(NODE top) {
    if (top == NULL) {
        printf("Stack is empty, cannot pop\n");
        return top;
    }
    NODE temp = top;
    top = top->next;
    free(temp);
    return top;
}

void display_stack(NODE top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    NODE temp = top;
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

NODE enqueue(NODE rear, int item) {
    NODE new_node = newnode(item);
    if (rear == NULL) {
        return new_node;
    }
    rear->next = new_node;
    return new_node;
}

NODE dequeue(NODE *front) {
    if (*front == NULL) {
        printf("Queue is empty, cannot dequeue\n");
        return *front;
    }
    NODE temp = *front;
    *front = (*front)->next;
    free(temp);
    return *front;
}

void display_queue(NODE front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    NODE temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    NODE stack_top = NULL;
    NODE queue_front = NULL, queue_rear = NULL;

    int choice, item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push onto Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue into Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push onto Stack: ");
                scanf("%d", &item);
                stack_top = push(stack_top, item);
                break;
            case 2:
                stack_top = pop(stack_top);
                break;
            case 3:
                display_stack(stack_top);
                break;
 
