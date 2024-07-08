#include <stdio.h>

int main() {
    int numProcesses = 5;
    int numResources = 3;

    int allocation[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int maximum[5][3] = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3} };
    int available[3] = {3, 3, 2};

    int finished[5] = {0};
    int safeSequence[5];
    int need[5][3];

    // Calculate the need matrix
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }

    int count = 0;
    while (count < numProcesses) {
        int found = 0;
        for (int p = 0; p < numProcesses; p++) {
            if (finished[p] == 0) {
                int canAllocate = 1;
                for (int r = 0; r < numResources; r++) {
                    if (need[p][r] > available[r]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int r = 0; r < numResources; r++) {
                        available[r] += allocation[p][r];
                    }
                    safeSequence[count++] = p;
                    finished[p] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("The system is not in a safe state\n");
            return 0;
        }
    }

    printf("The system is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < numProcesses; i++) {
        printf("P%d ", safeSequence[i]);
        if (i < numProcesses - 1) {
            printf("-> ");
        }
    }
    printf("\n");

    return 0;
}
