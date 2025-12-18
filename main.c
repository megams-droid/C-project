#include <stdio.h>

#define MAX 20

// Structure for Process
typedef struct {
    int pid;
    int bt;     // Burst Time
    int at;     // Arrival Time
    int pr;     // Priority
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
    int rt;     // Remaining Time (Round Robin)
} Process;

// Function to sort by arrival time
void sortByArrival(Process p[], int n) {
    int i, j;
    Process temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void fcfs(Process p[], int n) {
    sortByArrival(p, n);
    int time = 0;

    printf("\nFCFS Scheduling:\n");
    printf("PID\tWT\tTAT\n");

    for (int i = 0; i < n; i++) {
        if (time < p[i].at)
            time = p[i].at;

        p[i].wt = time - p[i].at;
        time += p[i].bt;
        p[i].tat = p[i].wt + p[i].bt;

        printf("%d\t%d\t%d\n", p[i].pid, p[i].wt, p[i].tat);
    }
}

void sjf(Process p[], int n) {
    int completed = 0, time = 0, minBT, index;
    int visited[MAX] = {0};

    printf("\nSJF Scheduling:\n");
    printf("PID\tWT\tTAT\n");

    while (completed != n) {
        minBT = 9999;
        index = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].at <= time && p[i].bt < minBT) {
                minBT = p[i].bt;
                index = i;
            }
        }

        if (index == -1) {
            time++;
            continue;
        }

        visited[index] = 1;
        p[index].wt = time - p[index].at;
        time += p[index].bt;
        p[index].tat = p[index].wt + p[index].bt;
        completed++;

        printf("%d\t%d\t%d\n", p[index].pid, p[index].wt, p[index].tat);
    }
}

void priorityScheduling(Process p[], int n) {
    int completed = 0, time = 0, highPr, index;
    int visited[MAX] = {0};

    printf("\nPriority Scheduling:\n");
    printf("PID\tPR\tWT\tTAT\n");

    while (completed != n) {
        highPr = 9999;
        index = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].at <= time && p[i].pr < highPr) {
                highPr = p[i].pr;
                index = i;
            }
        }

        if (index == -1) {
            time++;
            continue;
        }

        visited[index] = 1;
        p[index].wt = time - p[index].at;
        time += p[index].bt;
        p[index].tat = p[index].wt + p[index].bt;
        completed++;

        printf("%d\t%d\t%d\t%d\n", p[index].pid, p[index].pr, p[index].wt, p[index].tat);
    }
}

void roundRobin(Process p[], int n, int quantum) {
    int time = 0, done;
    for (int i = 0; i < n; i++)
        p[i].rt = p[i].bt;

    printf("\nRound Robin (Quantum = %d):\n", quantum);
    printf("PID\tWT\tTAT\n");

    while (1) {
        done = 1;

        for (int i = 0; i < n; i++) {
            if (p[i].rt > 0) {
                done = 0;

                if (p[i].rt > quantum) {
                    time += quantum;
                    p[i].rt -= quantum;
                } else {
                    time += p[i].rt;
                    p[i].wt = time - p[i].bt - p[i].at;
                    p[i].rt = 0;
                    p[i].tat = p[i].wt + p[i].bt;

                    printf("%d\t%d\t%d\n", p[i].pid, p[i].wt, p[i].tat);
                }
            }
        }

        if (done)
            break;
    }
}

int main() {
    Process p[MAX];
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Priority (lower is higher): ");
        scanf("%d", &p[i].pr);
    }

    do {
        printf("\nCPU Scheduling Algorithms:\n");
        printf("1. FCFS\n2. SJF\n3. Priority Scheduling\n4. Round Robin\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            fcfs(p, n);
            break;
        case 2:
            sjf(p, n);
            break;
        case 3:
            priorityScheduling(p, n);
            break;
        case 4:
            printf("Enter Time Quantum: ");
            scanf("%d", &quantum);
            roundRobin(p, n, quantum);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}
