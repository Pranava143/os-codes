#include <stdio.h>

int main() {
    int n, i, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float wtavg = 0, tatavg = 0;
    
    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Get the burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; // Initialize remaining burst time
    }
    
    // Get the quantum time
    printf("Enter the quantum time: ");
    scanf("%d", &qt);
    
    // Execute processes in round robin order
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process
                
                if (rem_bt[i] > qt) {
                    rem_bt[i] -= qt;
                    sq += qt;
                } else {
                    sq += rem_bt[i];
                    wt[i] = sq - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }
        
        if (done == 1) // All processes are done
            break;
    }
    
    // Calculate turnaround time and waiting time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    
    // Display process details
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    
    // Calculate and display average waiting and turnaround time
    printf("Average Waiting Time: %.2f\n", wtavg / n);
    printf("Average Turnaround Time: %.2f\n", tatavg / n);
    
    return 0;
}
