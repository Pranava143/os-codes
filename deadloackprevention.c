#include <stdio.h>
#include <string.h>
#define MAX_JOBS 10
int main() {
    char job[MAX_JOBS][10];  
    int time[MAX_JOBS];      
    int avail;              
    int temp[MAX_JOBS];      
    int sorted_index[MAX_JOBS]; 
    int safe[MAX_JOBS];     
    int ind = 0;             
    int n;                  
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter name and time for job %d: ", i + 1);
        scanf("%s %d", job[i], &time[i]);
        temp[i] = time[i];
        sorted_index[i] = i;
    }
    printf("Enter the available resources: ");
    scanf("%d", &avail);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
                t = sorted_index[i];
                sorted_index[i] = sorted_index[j];
                sorted_index[j] = t;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int job_index = sorted_index[i];
        if (time[job_index] <= avail) {
            safe[ind++] = job_index;
            avail += time[job_index];
        } else {
            printf("No safe sequence\n");
            return 1;
        }
    }
    printf("Safe sequence is:\n");
    for (int i = 0; i < ind; i++) {
        printf("%s %d\n", job[safe[i]], time[safe[i]]);
    }
    return 0;
}
