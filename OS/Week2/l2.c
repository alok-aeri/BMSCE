#include <stdio.h>

#define MAX_PROCESSES 20

void fcfs(int bt[], int n, const char* queue_name) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES], i;
    float wtavg = 0, tatavg = 0;

    printf("\n-- %s Queue --\n", queue_name);
    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\n\t Process \t Burst \t Waiting \t Turnaround");
    for (i = 0; i < n; i++) {
        printf("\n\t %d \t %d \t %d \t %d", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);
}

int main() {
    int n_sys, n_user, i;
    int sys_bt[MAX_PROCESSES], user_bt[MAX_PROCESSES];

    printf("Enter number of system processes: ");
    scanf("%d", &n_sys);
    printf("Enter number of user processes: ");
    scanf("%d", &n_user);

    printf("\nEnter burst times for system processes (FCFS):\n");
    for (i = 0; i < n_sys; i++) {
        printf("Burst time of system process %d: ", i + 1);
        scanf("%d", &sys_bt[i]);
    }

    printf("\nEnter burst times for user processes (FCFS):\n");
    for (i = 0; i < n_user; i++) {
        printf("Burst time of user process %d: ", i + 1);
        scanf("%d", &user_bt[i]);
    }

    fcfs(sys_bt, n_sys, "System");

    fcfs(user_bt, n_user, "User");

    return 0;
}
