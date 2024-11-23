#include <stdio.h>

struct Process {
    int pid,bt,wt,tat,rem_bt;
};

void findWaitingTime(struct Process proc[], int n, int quantum) {
    int t = 0;
    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (proc[i].rem_bt > 0) {
                done = 0;

                if (proc[i].rem_bt > quantum) {

                    t += quantum;
                    proc[i].rem_bt -= quantum;
                } else {

                    t += proc[i].rem_bt;
                    proc[i].wt = t - proc[i].bt;
                    proc[i].rem_bt = 0;
                }
            }
        }


        if (done == 1)
            break;
    }
}

void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++)
        proc[i].tat = proc[i].bt + proc[i].wt;
}

void findAverageTimes(struct Process proc[], int n, int quantum) {
    int total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, quantum);
    findTurnaroundTime(proc, n);

    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].wt, proc[i].tat);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / n);
    printf("\nAverage turnaround time = %.2f\n", (float)total_tat / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
        proc[i].pid = i + 1;
        proc[i].rem_bt = proc[i].bt;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    findAverageTimes(proc, n, quantum);

    return 0;
}


