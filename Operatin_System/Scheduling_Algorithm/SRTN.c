#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

// Declaring the structure
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

int main() {
    int n;
    struct process processes[MAX_PROCESSES];
    bool completed[MAX_PROCESSES] = {false};
    int current_time = 0;
    int shortest_index = -1;
    int i; // Declaration of 'i' moved outside the loop

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input arrival time and burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\n");

    while (true) {
        bool completed_all = true;
        shortest_index = -1;

        for (i = 0; i < n; i++) {
            if (!completed[i] && processes[i].arrival_time <= current_time) {
                completed_all = false;
                if (shortest_index == -1 || processes[i].remaining_time < processes[shortest_index].remaining_time) {
                    shortest_index = i;
                }
            }
        }

        if (completed_all)
            break;

        if (shortest_index != -1) {
            processes[shortest_index].remaining_time--;
            if (processes[shortest_index].remaining_time == 0) {
                completed[shortest_index] = true;
            }  
        }

        current_time++;
    }

    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (i = 0; i < n; i++) {
        int waiting_time = current_time - processes[i].burst_time - processes[i].arrival_time;
        int turnaround_time = current_time - processes[i].arrival_time;

        total_waiting_time += waiting_time;
        total_turnaround_time += turnaround_time;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time, turnaround_time);
    }

    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;

    printf("The Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("The Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

