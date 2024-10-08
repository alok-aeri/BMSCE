#include <stdio.h>
#include <string.h>

int index = 0, pos = 0, top = -1, length;
char symbol, temp, infix[20], postfix[20], stack[20];

void infixtopostfix();
void push(char symbol);
char pop();
int pred(char symb);

int main(void) {
    printf("Enter infix expression: \n");
    scanf("%s", infix);

    infixtopostfix();

    printf("\nInfix expression: \n%s", infix);
    printf("\nPostfix expression: \n%s", postfix);
    return 0;
}

void infixtopostfix() {
    length = strlen(infix);
    push('#');
    while (index < length) {
        symbol = infix[index];
        switch (symbol) {
        case '(':
            push(symbol);
            break;

        case ')':
            if (top < 0) {
                printf("Error: Unmatched parentheses\n");
                return;
            }
            temp = pop();
            while (temp != '(') {
                postfix[pos++] = temp;
                temp = pop();
            }
            break;

        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (top >= 0 && pred(stack[top]) >= pred(symbol)) {
                temp = pop();
                postfix[pos++] = temp;
            }
            push(symbol);
            break;

        default:
            postfix[pos++] = symbol;
        }
        index++;
    }
    while (top >= 0) {
        temp = pop();
        postfix[pos++] = temp;
    }
    postfix[pos] = '\0';
}

void push(char symbol) {
    stack[++top] = symbol;
}

char pop() {
    return stack[top--];
}

int pred(char symbol) {
    switch (symbol) {
    case '^': return 3;
    case '*':
    case '/': return 2;
    case '+':
    case '-': return 1;
    case '(': return 0;
    case '#': return -1;
    default: return -1;
    }
}
