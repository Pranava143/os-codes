#include <stdio.h>
#include <string.h>

#define MAX_JOBS 10

int main() {
    char job[MAX_JOBS][10];  // Array to store job names
    int time[MAX_JOBS];      // Array to store time required for each job
    int avail;               // Available resources
    int temp[MAX_JOBS];      // Temporary array for sorting times
    int sorted_index[MAX_JOBS]; // Array to store sorted indices of jobs
    int safe[MAX_JOBS];      // Array to store the safe sequence
    int ind = 0;             // Index for safe sequence
    int n;                   // Number of jobs

    // Input the number of jobs
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    // Input the name and time for each job
    for (int i = 0; i < n; i++) {
        printf("Enter name and time for job %d: ", i + 1);
        scanf("%s %d", job[i], &time[i]);
        temp[i] = time[i];
        sorted_index[i] = i;
    }

    // Input the available resources
    printf("Enter the available resources: ");
    scanf("%d", &avail);

    // Sort jobs based on time using bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                // Swap times
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
                // Swap indices
                t = sorted_index[i];
                sorted_index[i] = sorted_index[j];
                sorted_index[j] = t;
            }
        }
    }

    // Find the safe sequence
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

    // Print the safe sequence
    printf("Safe sequence is:\n");
    for (int i = 0; i < ind; i++) {
        printf("%s %d\n", job[safe[i]], time[safe[i]]);
    }

    return 0;
}
