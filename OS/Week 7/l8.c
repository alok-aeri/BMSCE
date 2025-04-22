#include <stdio.h>

#define max 10
#define pro 10

// Function prototypes
void firstFit(int blockSize[], int blocks, int processSize[], int processes);
void bestFit(int blockSize[], int blocks, int processSize[], int processes);
void worstFit(int blockSize[], int blocks, int processSize[], int processes);

int main() {
    int blockSize[max], processSize[pro];
    int blocks, processes, choice;

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);
    printf("Enter size of each block:\n");
    for (int i = 0; i < blocks; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter size of each process:\n");
    for (int i = 0; i < processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    while (1) {
        printf("\nChoose Allocation Strategy:\n");
        printf("1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        int tempBlockSize[max];
        for (int i = 0; i < blocks; i++) {
            tempBlockSize[i] = blockSize[i];
        }

        switch (choice) {
            case 1:
                firstFit(tempBlockSize, blocks, processSize, processes);
                break;
            case 2:
                bestFit(tempBlockSize, blocks, processSize, processes);
                break;
            case 3:
                worstFit(tempBlockSize, blocks, processSize, processes);
                break;
            case 4:
                printf("Exiting...\n");
                return 0; 
            default:
                printf("Invalid choice! Please select 1-4.\n");
        }
    }

    return 0;
}

void firstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[pro];
    for (int i = 0; i < processes; i++) allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        int allocated = 0;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                allocated = 1;
                break;
            }
        }

        if (!allocated) {
            for (int j = 0; j < blocks; j++) {
                if (blockSize[j] >= processSize[i]) {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
            }
        }
    }

    printf("\nFirst Fit Allocation (with sharing):\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[pro];
    for (int i = 0; i < processes; i++) allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        } else {
            for (int j = 0; j < blocks; j++) {
                if (blockSize[j] >= processSize[i]) {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
            }
        }
    }

    printf("\nBest Fit Allocation (with sharing):\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes) {
    int allocation[pro];
    for (int i = 0; i < processes; i++) allocation[i] = -1;

    for (int i = 0; i < processes; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        } else {
            for (int j = 0; j < blocks; j++) {
                if (blockSize[j] >= processSize[i]) {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
            }
        }
    }

    printf("\nWorst Fit Allocation (with sharing):\n");
    for (int i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("Process %d -> Not Allocated\n", i + 1);
    }
}
