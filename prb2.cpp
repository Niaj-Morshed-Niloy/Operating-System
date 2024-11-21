#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

bool compareBurstTime(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
    }


    sort(processes.begin(), processes.end(), compareBurstTime);


    processes[0].waitingTime = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].burstTime + processes[i - 1].waitingTime;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
    }


    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
    }
    float averageWaitingTime = (float)totalWaitingTime / n;


    int totalTurnAroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalTurnAroundTime += processes[i].turnAroundTime;
    }
    float averageTurnAroundTime = (float)totalTurnAroundTime / n;


    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" << processes[i].burstTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnAroundTime << endl;
    }

    cout << "\nAverage Waiting Time: " << averageWaitingTime;
    cout << "\nAverage Turnaround Time: " << averageTurnAroundTime;

    return 0;
}
