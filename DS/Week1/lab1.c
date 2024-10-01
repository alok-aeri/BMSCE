#include<stdio.h>

#define max 3
void push();
int pop();
void display();
int s[max],top=-1,i,item,ch;
int main(void){
    while(1) {
        printf("1:push\n2:pop\n3:display\n4:exit\n"); scanf("%i", &ch);

        switch(ch){
        case 1: push();
                break;
        case 2: pop();
                item = pop();
                if (item != -1) {
                    printf("Popped element : %i", item);
                }
                break;
        case 3: display();
                break;
        case 4:
            return 0;
        default:
            printf("invalid");
        }
    }
}
void push(){
    if (top==max-1){
        printf("Stack Overflow");
        return;
    }
    else {
        printf("The one being pushed : ");
        scanf("%i", &item);
        top += 1;
        s[top] = item;
    }
}
int pop(){
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    item = s[top];
    top -= 1;
    return item;
}
void display(){
    if (top == -1){
        printf("Stack is empty");
        return;
    }
    printf("Stack Contents : ");
    for (i = top; i >= 0; i--){
        printf("%d\n", s[i]);
    }
}
