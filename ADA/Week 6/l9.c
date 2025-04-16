#include <stdio.h>

void printPermutation(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void johnsonTrotter(int n) {
    int arr[n], dir[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i + 1; 
        dir[i] = -1;   
    }

    printPermutation(arr, n); 

    while (1) {
        int largest = -1;
        int largestIndex = -1;

        for (int i = 0; i < n; i++) {
            int canMove = 0;

            if (dir[i] == -1 && i > 0 && arr[i] > arr[i - 1]) {
                canMove = 1;
            } else if (dir[i] == 1 && i < n - 1 && arr[i] > arr[i + 1]) {
                canMove = 1;
            }

            if (canMove && arr[i] > largest) {
                largest = arr[i];
                largestIndex = i;
            }
        }

        if (largest == -1) break;

        int temp = arr[largestIndex];
        arr[largestIndex] = arr[largestIndex + dir[largestIndex]];
        arr[largestIndex + dir[largestIndex]] = temp;

        dir[largestIndex] = -dir[largestIndex];

        printPermutation(arr, n);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n); 

    return 0;
}
