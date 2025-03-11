#include<stdio.h>

int main () {
    int bt[20], wt[20], tat[20], i, n;
    float wtavg = 0, tatavg = 0;

    printf("The no. of processes: \n");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("The Burst Time of Process %d: ", i+1);
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\t Process \t Burst \t Waiting \t Turnaround");
    for(i = 0; i < n; i++){
        printf("\n\t %d \t %d \t %d \t %d", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);    

    return 0;
}
