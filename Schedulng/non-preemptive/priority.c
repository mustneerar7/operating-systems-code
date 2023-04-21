#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int n, i, j, temp;
    
    int burst_time[20];
    int priority[20];
    int waiting_time[20];
    int turnaround_time[20];
    
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority for each process:\n");
    for(i=0; i<n; i++) {
        printf("P[%d] burst time: ", i+1);
        scanf("%d", &burst_time[i]);
        printf("P[%d] priority: ", i+1);
        scanf("%d", &priority[i]);
    }

    // sorting processes in ascending order of priority using selection sort algorithm
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(priority[i] > priority[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }

    // calculating waiting time for each process
    waiting_time[0] = 0;
    for(i=1; i<n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    // calculating turnaround time for each process
    for(i=0; i<n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    // calculating average waiting and turnaround time
    for(i=0; i<n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // printing results
    printf("\nProcess\tBurst time\tPriority\tWaiting time\tTurnaround time\n");
    for(i=0; i<n; i++) {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}
