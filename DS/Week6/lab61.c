#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert();
void insertAtPosition();
void delete();
void deleteAtPosition();
void display();

struct Node* head = NULL;

int main() {
    int ch;
    while (1) {
        printf("\n1.Insert at End\n2.Insert at Position\n3.Delete (First)\n4.Delete at Position\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                insertAtPosition();
                break;
            case 3:
                delete();
                break;
            case 4:
                deleteAtPosition();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}

void insert() {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter element to be inserted: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL; 

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition() {
    int pos;
    printf("Enter position to insert (starting from 1): ");
    scanf("%d", &pos);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter element to insert at position %d: ", pos);
    scanf("%d", &newNode->data);

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position %d.\n", pos);
    } else {
        struct Node* temp = head;
        int i;
        for (i = 1; temp != NULL && i < pos - 1; i++) {
            temp = temp->next; 
        }

        if (temp == NULL) {
            printf("Position is out of range. Inserting at the end.\n");
            newNode->next = NULL;
            if (head == NULL) {
                head = newNode;
            } else {
                struct Node* last = head;
                while (last->next != NULL) {
                    last = last->next;
                }
                last->next = newNode;
            }
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node inserted at position %d.\n", pos);
        }
    }
}

void delete() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;  
    printf("Deleted element is %d\n", temp->data);
    free(temp); 
}

void deleteAtPosition() {
    int pos, i;
    printf("Enter position to delete (starting from 1): ");
    scanf("%d", &pos);

    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    if (pos == 1) {
        delete();  
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    
    for (i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of range.\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted element is %d\n", temp->data);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked list contains:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
