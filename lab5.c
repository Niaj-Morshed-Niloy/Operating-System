#include <stdio.h>

void calculateNeed(int need[][10], int max[][10], int allot[][10], int P, int R) {
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            need[i][j] = max[i][j] - allot[i][j];
}

int checkSafe(int processes[], int avail[], int max[][10], int allot[][10], int P, int R) {
    int need[10][10];
    calculateNeed(need, max, allot, P, R);

    int finish[10], safeSeq[10], work[10];
    for (int i = 0; i < P; i++)
        finish[i] = 0;

    for (int i = 0; i < R; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < P) {
        int found = 0;
        for (int p = 0; p < P; p++) {
            if (finish[p] == 0) {
                int j;
                for (j = 0; j < R; j++)
                    if (need[p][j] > work[j])
                        break;

                if (j == R) {
                    for (int k = 0; k < R; k++)
                        work[k] += allot[p][k];

                    safeSeq[count++] = processes[p];
                    finish[p] = 1; // mark process as finished
                    found = 1;
                }
            }
        }

        if (found == 0) { // if no process can proceed, deadlock is possible
            printf("System is not in a safe state.\n");

        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++)
        printf("%d ", safeSeq[i]);
    printf("\n");

}

int main() {
    int P, R;
    printf("Enter the number of processes: ");
    scanf("%d", &P);

    printf("Enter the number of resource types: ");
    scanf("%d", &R);

    int processes[P], avail[R], max[P][10], allot[P][10];

    for (int i = 0; i < P; i++)
        processes[i] = i; // process IDs

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &allot[i][j]);

    printf("Enter the Maximum Matrix:\n");
    for (int i = 0; i < P; i++)
        for (int j = 0; j < R; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the Available Resources:\n");
    for (int i = 0; i < R; i++)
        scanf("%d", &avail[i]);

    checkSafe(processes, avail, max, allot, P, R);

    return 0;
}

