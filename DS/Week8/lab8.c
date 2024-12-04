#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insertatfirst();
void insertatend();
void insertatpos();
void deletefirst();
void deletelast();
void deleteSpecific();

struct node{
    int data;
    node *link;
}node;

typedef struct node *Start, *new1, *temp, *Curr, *last;

void main() {
    int cho;
    while (1) {
        printf("\nEnter your choice\n");
        printf("1.CREATE\n2.DISPLAY\n3.INSERT AT FIRST\n4.INSERT AT END\n5.INSERT AT POSITION\n6.DELETE FIRST\n7.DELETE LAST\n8.DELETE SPECIFIC\n9.EXIT\n");
        scanf("%d", &cho);
        switch (cho) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertatfirst(); break;
            case 4: insertatend(); break;
            case 5: insertatpos(); break;
            case 6: deletefirst(); break;
            case 7: deletelast(); break;
            case 8: deleteSpecific(); break;
            case 9: exit(0); break;
            default: printf("Invalid choice \n"); break;
        }
    }
}

void create() {
    char ca;
    while(1) {
        new1 = (node*)malloc(sizeof(node));
        printf("Enter data for insertion:\t");
        scanf("%d", &new1->data);
        if (Start == NULL) {
            Start = new1;
            last = new1;
            new1->link = Start;
        } else {
            last->link = new1;
            last = new1;
            new1->link = Start;
        }
        printf("Do you want to insert another node? Enter Y or y for Yes or N or n for No: \t");
        getchar();
        scanf("%c", &ca);
        if (ca != 'Y' && ca != 'y') {
            break;
        }
    }
}

void display() {
    if (Start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    temp = Start;
    do {
        printf("%d ->", temp->data);
        temp = temp->link;
    } while (temp != Start);
    printf("START \n");
}

void insertatfirst() {
    new1 = (node*)malloc(sizeof(node));
    printf("Enter data for insertion:\t");
    scanf("%d", &new1->data);
    if (Start == NULL) {
        Start = new1;
        new1->link = Start;
    } else {
        temp = Start;
        while (temp->link != Start) {
            temp = temp->link;
        }
        temp->link = new1;
        new1->link = Start;
        Start = new1;
    }
}

void insertatend() {
    new1 = (node*)malloc(sizeof(node));
    printf("Enter data for insertion:\t");
    scanf("%d", &new1->data);
    if (Start == NULL) {
        Start = new1;
        new1->link = Start;
    } else {
        temp = Start;
        while (temp->link != Start) {
            temp = temp->link;
        }
        temp->link = new1;
        new1->link = Start;
    }
}

void insertatpos() {
    int pos, i = 1;
    printf("Enter the position:\t");
    scanf("%d", &pos);
    new1 = (node*)malloc(sizeof(node));
    printf("Enter data for insertion:\t");
    scanf("%d", &new1->data);
    if (pos == 1) {
        insertatfirst();
        return;
    }
    temp = Start;
    while (temp->link != Start && i < pos - 1) {
        temp = temp->link;
        i++;
    }
    if (i == pos - 1) {
        new1->link = temp->link;
        temp->link = new1;
    } else {
        printf("Position exceeds the length of the list.\n");
    }
}

void deletefirst() {
    if (Start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (Start->link == Start) {
        free(Start);
        Start = NULL;
    } else {
        temp = Start;
        while (temp->link != Start) {
            temp = temp->link;
        }
        temp->link = Start->link;
        free(Start);
        Start = temp->link;
    }
}

void deletelast() {
    if (Start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    if (Start->link == Start) {
        free(Start);
        Start = NULL;
    } else {
        temp = Start;
        while (temp->link->link != Start) {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = Start;
    }
}

void deleteSpecific() {
    int value;
    printf("Enter the value to delete: ");
    scanf("%d", &value);
    if (Start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    temp = Start;
    if (temp->data == value) {
        deletefirst();
        return;
    }
    while (temp->link != Start && temp->link->data != value) {
        temp = temp->link;
    }
    if (temp->link == Start) {
        printf("Value not found in the list.\n");
    } else {
        node *toDelete = temp->link;
        temp->link = temp->link->link;
        free(toDelete);
    }
}
