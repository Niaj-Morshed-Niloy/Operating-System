#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity];
    int front = 0, pageFaults = 0;

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
    }

    printf("Page\tFrames\n");

    for (int i = 0; i < n; i++) {
        int found = 0;


        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[front] = pages[i];
            front = (front + 1) % capacity; // Update front pointer
            pageFaults++; // Count page fault

            // Display frames after replacement
            printf("%d\t", pages[i]);
            for (int k = 0; k < capacity; k++) {
                if (frames[k] != -1)
                    printf("%d ", frames[k]);
                else
                    printf("- ");
            }
            printf("\n");
        } else {
            printf("%d\tHit\n", pages[i]);
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3; // Number of frames in memory

    fifoPageReplacement(pages, n, capacity);

    return 0;
}

