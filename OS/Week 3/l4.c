#include <stdio.h>

typedef struct {
    int id, execution, period, remaining, next_arrival;
} Task;

void RMS(Task tasks[], int n, int total_time) {
    int time = 0;

    while (time < total_time) {
        int highest_priority = -1;

        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0 && tasks[i].next_arrival <= time) {
                if (highest_priority == -1 || tasks[i].period < tasks[highest_priority].period) {
                    highest_priority = i;
                }
            }
        }

        if (highest_priority == -1) {
            printf("Time %d: CPU Idle\n", time);
        } else {
            printf("Time %d: Executing Task %d\n", time, tasks[highest_priority].id);
            tasks[highest_priority].remaining--;

            if (tasks[highest_priority].remaining == 0) {
                tasks[highest_priority].remaining = tasks[highest_priority].execution;
                tasks[highest_priority].next_arrival += tasks[highest_priority].period;
                printf("Task %d Completed at Time %d\n", tasks[highest_priority].id, time + 1);
            }
        }
        time++;
    }
}

int main() {
    Task tasks[] = {
        {1, 1, 4, 1, 0},
        {2, 2, 6, 2, 0},
        {3, 1, 8, 1, 0}
    };
    
    int n = sizeof(tasks) / sizeof(tasks[0]);
    int total_time = 12;
    
    RMS(tasks, n, total_time);
    
    return 0;
}
