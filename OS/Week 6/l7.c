#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    printf("Enter number of processes -- ");
    scanf("%d", &n);
    printf("Enter number of resources -- ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int finish[n];

    for (int i = 0; i < n; i++) {
        printf("Enter details for P%d\n", i);
        printf("Enter allocation -- ");
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
        printf("Enter Max -- ");
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Enter Available Resources -- ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    int pid, request[m];
    printf("Enter New Request Details --\n");
    printf("Enter pid -- ");
    scanf("%d", &pid);
    printf("Enter Request for Resources -- ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &request[i]);
    }

    bool valid = true;
    for (int i = 0; i < m; i++) {
        if (request[i] > need[pid][i]) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        printf("Error: Process has exceeded its maximum claim.\n");
        return 0;
    }

    for (int i = 0; i < m; i++) {
        if (request[i] > avail[i]) {
            printf("Process must wait, resources not available.\n");
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        avail[i] -= request[i];
        alloc[pid][i] += request[i];
        need[pid][i] -= request[i];
    }

    int work[m];
    for (int i = 0; i < m; i++) work[i] = avail[i];
    for (int i = 0; i < n; i++) finish[i] = 0;

    int safeSeq[n], count = 0;

    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }
                if (canRun) {
                    for (int j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }
                    finish[i] = 1;
                    safeSeq[count++] = i;
                    printf("P%d is visited (", i);
                    for (int k = 0; k < m; k++) {
                        printf("%d", work[k]);
                        if (k < m - 1) printf(" ");
                    }
                    printf(")\n");
                    found = true;
                }
            }
        }
        if (!found) break;
    }

    if (count == n) {
        printf("SYSTEM IS IN SAFE STATE\n");
        printf("The Safe Sequence is -- (");
        for (int i = 0; i < n; i++) {
            printf("P%d", safeSeq[i]);
            if (i < n - 1) printf(" ");
        }
        printf(")\n");
    } else {
        printf("SYSTEM IS IN UNSAFE STATE\n");
    }

    return 0;
}
