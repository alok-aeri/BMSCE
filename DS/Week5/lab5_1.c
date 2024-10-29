#include <stdio.h>

void tOH(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return;
    }
    tOH(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    tOH(n - 1, aux_rod, to_rod, from_rod);
}

int main(void) {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tOH(n, 'A', 'C', 'B');
    return 0;
}
