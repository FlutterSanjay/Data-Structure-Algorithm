#include<bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
};

void calculateTimes(Process process[], int n, int quantum) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = process[i].burstTime;
    }
    int currentTime = 0;
    bool allDone = false;
    
    while (!allDone) {
        allDone = true;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                allDone = false;
                if (remainingTime[i] > quantum) {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    currentTime += remainingTime[i];
                    process[i].completionTime = currentTime;
                    remainingTime[i] = 0;
                }
            }
        }
    }
}

void calculateTurnAroundTime(Process process[], int n) {
    for (int i = 0; i < n; i++) {
        process[i].turnAroundTime = process[i].completionTime - process[i].arrivalTime;
    }
}

void calculateWaitingTime(Process process[], int n) {
    for (int i = 0; i < n; i++) {
        process[i].waitingTime = process[i].turnAroundTime - process[i].burstTime;
    }
}

void printResults(Process process[], int n) {
    cout << "Process ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << process[i].id << "          | "
             << process[i].arrivalTime << "           | "
             << process[i].burstTime << "          | "
             << process[i].completionTime << "              | "
             << process[i].turnAroundTime << "             | "
             << process[i].waitingTime << "\n";
    }
}

int main() {
    int n, quantum;
    cout << "Enter the number of Processes: ";
    cin >> n;
    cout << "Enter the Time Quantum: ";
    cin >> quantum;

    Process process[n];
    cout << "Enter Process details:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ":\n";
        process[i].id = i + 1;
        cout << "Arrival Time: ";
        cin >> process[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> process[i].burstTime;
    }

    calculateTimes(process, n, quantum);
    calculateTurnAroundTime(process, n);
    calculateWaitingTime(process, n);

    printResults(process, n);

    return 0;
}
