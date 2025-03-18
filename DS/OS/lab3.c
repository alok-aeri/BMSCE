#include <stdio.h>

#define MAX_PROCESSES 20
#define TIME_QUANTUM 4  // For Round Robin scheduling

// Function to implement Round Robin Scheduling
void roundRobin(int bt[], int n) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES], remaining_bt[MAX_PROCESSES];
    int i, total_wt = 0, total_tat = 0;
    
    // Copy burst times to remaining_bt for processing
    for (i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }

    int time = 0;
    while (1) {
        int done = 1;  // Flag to check if all processes are done
        for (i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                done = 0;
                if (remaining_bt[i] > TIME_QUANTUM) {
                    remaining_bt[i] -= TIME_QUANTUM;
                    time += TIME_QUANTUM;
                } else {
                    time += remaining_bt[i];
                    wt[i] = time - bt[i];
                    tat[i] = wt[i] + bt[i];
                    total_wt += wt[i];
                    total_tat += tat[i];
                    remaining_bt[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }

    // Display the results
    printf("\n\t Process \t Burst \t Waiting \t Turnaround");
    for (i = 0; i < n; i++) {
        printf("\n\t %d \t %d \t %d \t %d", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat / n);
}

// Function to implement FCFS Scheduling
void fcfs(int bt[], int n) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES], i;
    float wtavg = 0, tatavg = 0;

    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Display the results
    printf("\n\t Process \t Burst \t Waiting \t Turnaround");
    for (i = 0; i < n; i++) {
        printf("\n\t %d \t %d \t %d \t %d", i+1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f", tatavg / n);
}

int main() {
    int n_fg, n_bg, i;
    int fg_bt[MAX_PROCESSES], bg_bt[MAX_PROCESSES];

    printf("Enter number of foreground processes: ");
    scanf("%d", &n_fg);
    printf("Enter number of background processes: ");
    scanf("%d", &n_bg);

    // Input burst times for foreground processes
    printf("\nEnter burst times for foreground processes (Round Robin):\n");
    for (i = 0; i < n_fg; i++) {
        printf("Burst time of process %d: ", i+1);
        scanf("%d", &fg_bt[i]);
    }

    // Input burst times for background processes
    printf("\nEnter burst times for background processes (FCFS):\n");
    for (i = 0; i < n_bg; i++) {
        printf("Burst time of process %d: ", i+1);
        scanf("%d", &bg_bt[i]);
    }

    // First, schedule foreground processes using Round Robin
    printf("\n\n-- Foreground Processes (Round Robin Scheduling) --\n");
    roundRobin(fg_bt, n_fg);

    // Then, schedule background processes using FCFS
    printf("\n\n-- Background Processes (FCFS Scheduling) --\n");
    fcfs(bg_bt, n_bg);

    return 0;
}
