#include <stdio.h>

typedef struct {
    int id, execution, period, deadline, remaining, next_arrival;
} Task;

void EDF(Task tasks[], int n, int total_time) {
    int time = 0;

    while (time < total_time) {
        int earliest_deadline = -1;

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0 && tasks[i].next_arrival <= time) {
                if (earliest_deadline == -1 || tasks[i].deadline < tasks[earliest_deadline].deadline) {
                    earliest_deadline = i;
                }
            }
        }

        if (earliest_deadline == -1) {
            printf("Time %d: CPU Idle\n", time);
        } else {
            printf("Time %d: Executing Task %d\n", time, tasks[earliest_deadline].id);
            tasks[earliest_deadline].remaining--;

            if (tasks[earliest_deadline].remaining == 0) {
                tasks[earliest_deadline].remaining = tasks[earliest_deadline].execution;
                tasks[earliest_deadline].next_arrival += tasks[earliest_deadline].period;
                printf("Task %d Completed at Time %d\n", tasks[earliest_deadline].id, time + 1);
            }
        }
        time++;
    }
}

int main() {
    Task tasks[] = {
        {1, 1, 5, 5, 1, 0},
        {2, 2, 7, 7, 2, 0},
        {3, 1, 4, 4, 1, 0}
    };
    
    int n = sizeof(tasks) / sizeof(tasks[0]);
    int total_time = 12;
    
    EDF(tasks, n, total_time);
    
    return 0;
}
