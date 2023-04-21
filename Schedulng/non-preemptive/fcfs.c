#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n, burst_time[20];
    int waiting_time[20];
    int turnaround_time[20];

    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;


    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time for each process:\n");
    for(int i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    // calculating waiting time for each process
    waiting_time[0] = 0;
    for(int i=1; i<n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    // calculating turnaround time for each process
    for(int i=0; i<n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // calculating average waiting and turnaround time
    for(int i=0; i<n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // printing results
    printf("\nProcess\tBurst time\tWaiting time\tTurnaround time\n");
    for(int i=0; i<n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
