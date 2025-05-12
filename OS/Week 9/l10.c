#include <stdio.h>

void FIFO(int frames, int n, int reference[]) {
    int memory[frames];
    int pageFaults = 0, index = 0;
    
    for(int i = 0; i < frames; i++) memory[i] = -1;
    
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < frames; j++) {
            if(memory[j] == reference[i]) {
                found = 1;
                break;
            }
        }
        
        if(!found) {
            memory[index] = reference[i];
            index = (index + 1) % frames;
            pageFaults++;
        }
        
        printf("PF No. %d: ", i + 1);
        for(int j = 0; j < frames; j++) {
            if(memory[j] != -1) printf("%d ", memory[j]);
        }
        printf("\n");
    }
    printf("FIFO Page Faults: %d\n", pageFaults);
}

void LRU(int frames, int n, int reference[]) {
    int memory[frames];
    int pageFaults = 0;
    int lastUsed[frames];
    
    for(int i = 0; i < frames; i++) memory[i] = -1;
    
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < frames; j++) {
            if(memory[j] == reference[i]) {
                found = 1;
                lastUsed[j] = i;
                break;
            }
        }
        
        if(!found) {
            int lruIndex = 0;
            for(int j = 1; j < frames; j++) {
                if(lastUsed[j] < lastUsed[lruIndex]) lruIndex = j;
            }
            memory[lruIndex] = reference[i];
            lastUsed[lruIndex] = i;
            pageFaults++;
        }
        
        printf("PF No. %d: ", i + 1);
        for(int j = 0; j < frames; j++) {
            if(memory[j] != -1) printf("%d ", memory[j]);
        }
        printf("\n");
    }
    printf("LRU Page Faults: %d\n", pageFaults);
}

int findOptimal(int frames, int n, int reference[], int memory[]) {
    int farthest = -1, idx = -1;
    for(int i = 0; i < frames; i++) {
        int j;
        for(j = 0; j < n; j++) {
            if(memory[i] == reference[j]) break;
        }
        if(j == n) return i;
        
        if(j > farthest) {
            farthest = j;
            idx = i;
        }
    }
    return idx;
}

void Optimal(int frames, int n, int reference[]) {
    int memory[frames];
    int pageFaults = 0;
    
    for(int i = 0; i < frames; i++) memory[i] = -1;
    
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < frames; j++) {
            if(memory[j] == reference[i]) {
                found = 1;
                break;
            }
        }
        
        if(!found) {
            int idx = findOptimal(frames, n, reference, memory);
            memory[idx] = reference[i];
            pageFaults++;
        }
        
        printf("PF No. %d: ", i + 1);
        for(int j = 0; j < frames; j++) {
            if(memory[j] != -1) printf("%d ", memory[j]);
        }
        printf("\n");
    }
    printf("Optimal Page Faults: %d\n", pageFaults);
}

int main() {
    int frames, n;
    
    printf("Enter the number of Frames: ");
    scanf("%d", &frames);
    printf("Enter the length of reference string: ");
    scanf("%d", &n);
    
    int reference[n];
    
    printf("Enter the reference string: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &reference[i]);
    }
    
    printf("FIFO Page Replacement Process:\n");
    FIFO(frames, n, reference);
    
    printf("LRU Page Replacement Process:\n");
    LRU(frames, n, reference);
    
    printf("Optimal Page Replacement Process:\n");
    Optimal(frames, n, reference);
    
    return 0;
}
