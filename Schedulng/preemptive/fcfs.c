#include<stdio.h>

int main() {
    int n, burst_time[20];
    int remaining_burst_time[20];
    int waiting_time[20];
    int turnaround_time[20];
    
    int i, j, time;
    
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for(i=0; i<n; i++) {
        printf("P[%d] burst time: ", i+1);
        scanf("%d", &burst_time[i]);
        remaining_burst_time[i] = burst_time[i];
    }

    // FCFS scheduling algorithm
    printf("\nGantt Chart:\n");
    printf("0");
    for(i=0, time=0; i<n; i++) {
        waiting_time[i] = time;
        for(j=0; j<burst_time[i]; j++) {
            printf(" P[%d] %d", i+1, time+j+1);
            time++;
        }
        turnaround_time[i] = time;
    }

    // calculating average waiting and turnaround time
    for(i=0; i<n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // printing results
    printf("\n\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    for(i=0; i<n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
