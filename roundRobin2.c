#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int rem_bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int num_process;
    printf("Enter the number of processes:");
    scanf("%d", &num_process);

    struct process p[num_process];

    printf("Start entering the details of the processes...\n");

    for (int i = 0; i < num_process; i++) {
        printf("Enter the Process ID, Arrival time and the Burst time of process %d:", i + 1);
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
        p[i].rem_bt = p[i].bt;
    }

    int quantum;
    printf("Enter the time quantum of the process:");
    scanf("%d", &quantum);

    int time = 0;
    int completed = 0; // Counter for completed processes

    while (completed < num_process) {
        for (int i = 0; i < num_process; i++) {
            if (p[i].rem_bt > 0) {
                if (p[i].rem_bt > quantum) {
                    // Execute with time quantum
                    time += quantum;
                    p[i].rem_bt -= quantum;
                } else {
                    // Last execution cycle for this process
                    time += p[i].rem_bt;
                    p[i].rem_bt = 0;
                    p[i].ct = time;
                    completed++;
                }
            }
        }
    }

    // Calculate turnaround time (TAT) and waiting time (WT)
    float total_tat = 0, total_wt = 0;
    for (int i = 0; i < num_process; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    // Print the schedule and results
    printf("\nThe scheduled processes in Round Robin scheduling are...\n");
    printf("%-12s %-14s %-12s %-17s %-17s %-14s\n",
           "PROCESS ID", "ARRIVAL TIME", "BURST TIME", "COMPLETION TIME", "TURNAROUND TIME", "WAITING TIME");

    for (int i = 0; i < num_process; i++) {
        printf("%-12d %-14d %-12d %-17d %-17d %-14d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    // Calculate and print average turnaround time and waiting time
    float avg_tat = total_tat / num_process;
    float avg_wt = total_wt / num_process;
    printf("\nThe average Turnaround time is: %.2f\n", avg_tat);
    printf("The average Waiting time is: %.2f\n", avg_wt);

    return 0;
}

