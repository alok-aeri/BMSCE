#include <stdio.h>
#include <stdlib.h>

#define max 100

typedef struct {
    int items[max];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == max - 1) return;
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear) return -1;
    return q->items[q->front++];
}

int checkContiguous(int memory[], int start, int length) {
    if (start + length > max) return 0;
    for (int i = start; i < start + length; i++) {
        if (memory[i] != 0) return 0;
    }
    return 1;
}

int allocateFile(int memory[], int length) {
    for (int i = 0; i <= max - length; i++) {
        if (checkContiguous(memory, i, length)) {
            for (int j = i; j < i + length; j++) memory[j] = 1;
            return i;
        }
    }
    return -1;
}

int main() {
    int memory[max] = {0};
    Queue freeBlocks;
    initQueue(&freeBlocks);

    for (int i = 0; i < max; i++) {
        enqueue(&freeBlocks, i);
    }

    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);

    for (int f = 0; f < n; f++) {
        int length;
        printf("\nFile %d:\nEnter length (number of blocks): ", f + 1);
        scanf("%d", &length);

        int startBlock = allocateFile(memory, length);

        if (startBlock != -1) {
            printf("File %d allocated from block %d to %d\n", f + 1, startBlock, startBlock + length - 1);
        } else {
            printf("File %d allocation failed (not enough contiguous blocks)\n", f + 1);
        }
    }

    printf("\nFinal Memory Allocation Map:\n");
    for (int i = 0; i < max; i++) {
        printf("%d ", memory[i]);
        if ((i + 1) % 20 == 0) printf("\n");
    }

    return 0;
}
