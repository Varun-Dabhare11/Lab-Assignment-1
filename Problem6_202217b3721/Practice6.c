#include <stdio.h>

// Function to calculate waiting time and turnaround time
void calculateTimes(int n, int burst_time[], int arrival_time[], int waiting_time[], int turnaround_time[], int completion_time[]) {
    int i;
    completion_time[0] = arrival_time[0] + burst_time[0];

    for (i = 1; i < n; i++) {
        completion_time[i] = completion_time[i - 1] + burst_time[i];
    }

    for (i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }
}

// Function to print the results
void printResults(int n, int waiting_time[], int turnaround_time[]) {
    int i;
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\n", i + 1, waiting_time[i], turnaround_time[i]);
        total_wt += waiting_time[i];
        total_tat += turnaround_time[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n, i;
    int burst_time[10], arrival_time[10], waiting_time[10], turnaround_time[10], completion_time[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }

    printf("Enter the arrival times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arrival_time[i]);
    }

    // Calculate waiting time and turnaround time
    calculateTimes(n, burst_time, arrival_time, waiting_time, turnaround_time, completion_time);

    // Print results
    printResults(n, waiting_time, turnaround_time);

    return 0;
}
