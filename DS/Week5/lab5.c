#include<stdio.h>

int fact(int i) {
    if (i == 1) {
        return 1;
    }
    else {
        return(i * fact(i -1));
    }
}
int fibo(int i) {
    if (i == 1) {
        return 0;
    }
    else if (i == 2) {
        return 1;
    }
    else {
        return (fibo(i-2)+ fibo(i-1));
    }
}

int main(void) {
    int x;
    printf("The fibonacci of: \n");
    scanf("%i", &x);
    printf("The fibonacci of %i is %i", x, fibo(x));
}


