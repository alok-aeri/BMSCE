#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next, *prev;
} Node;

void printList(Node *head) {
    for (Node *node = head; node; node = node->next) {
        printf("%d ->", node->value);
    }
    printf("NULL\n");
}

void addAtFront(Node **head, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->value = value;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head) (*head)->prev = newNode;
    *head = newNode;
}

void removeByValue(Node **head, int value) {
    if (!*head) return;

    Node *current = *head;
    while (current && current->value != value) {
        current = current->next;
    }

    if (!current) {
        printf("Value %d not found\n", value);
        return;
    }

    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;
    if (current == *head) *head = current->next;

    free(current);
}

int main() {
    Node *head = NULL;
    addAtFront(&head, 20);
    addAtFront(&head, 40);
    addAtFront(&head, 50);
    addAtFront(&head, 60);
    
    printList(head);
    
    removeByValue(&head, 50);
    printList(head);
    
    removeByValue(&head, 60);
    printList(head);
    
    removeByValue(&head, 100);
    printList(head);
    
    return 0;
}
