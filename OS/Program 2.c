#include <stdio.h>

void calculateWaitingTime(int bt[], int wt[], int n) {
    wt[0] = 0;
    
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
}

void calculateTurnaroundTime(int bt[], int wt[], int tat[], int n) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void averageTimes(int wt[], int tat[], int n) {
    float wtavg = 0, tatavg = 0;
    
    for (int i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);
}

void sjfScheduling(int bt[], int n) {
    int wt[20], tat[20];
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    calculateWaitingTime(bt, wt, n);
    calculateTurnaroundTime(bt, wt, tat, n);
    
    printf("\n\nSJF Scheduling\n");
    printf("\n\t Process \t Burst \t Waiting \t Turnaround");
    
    for (int i = 0; i < n; i++) {
        printf("\n\t %d \t\t %d \t\t %d \t\t %d", i + 1, bt[i], wt[i], tat[i]);
    }

    averageTimes(wt, tat, n);
}

int main() {
    int bt[20], n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time of Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    sjfScheduling(bt, n);

    return 0;
}
