#include <stdio.h>

int main() {
    int n, i, qt, count = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10];
    float wtavg = 0, tatavg = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i]; 
    }

    printf("Enter the quantum time: ");
    scanf("%d", &qt);

    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; 
                
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
        
        if (done == 1) 
            break;
    }
    
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }
    
    printf("\n\tPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\tP%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }
    
    printf("Average Waiting Time: %.2f\n", wtavg / n);
    printf("Average Turnaround Time: %.2f\n", tatavg / n);
    
    return 0;
}
