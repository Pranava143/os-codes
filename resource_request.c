#include <stdio.h>
#include <stdlib.h>

int max[100][100], alloc[100][100], need[100][100], avail[100];
int n, r;

void input();
void show();
void calculate();
void requestResource();

int main() {
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    calculate();
    requestResource();
    return 0;
}

void input() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &r);

    printf("Enter the Max Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the Allocation Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter the Available Resources:\n");
    for (int j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    printf("\nProcess\t Allocation\t Max\t\t Available\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t ", i);
        for (int j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t ");
        for (int j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t ");
        if (i == 0) {
            for (int j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}

void calculate() {
    int finish[100] = {0}, safeSeq[100], work[100], count = 0;
    for (int i = 0; i < r; i++) {
        work[i] = avail[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == r) {
                    for (int k = 0; k < r; k++) {
                        work[k] += alloc[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            printf("\nSystem is in unsafe state.\n");
            return;
        }
    }
    printf("\nSystem is in safe state.\nSafe sequence is: ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");
}

void requestResource() {
    int pid, request[100];

    printf("\nDo you want to make an additional request for any process? (1=Yes | 0=No): ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter process number: ");
        scanf("%d", &pid);

        printf("Enter additional request for each resource:\n");
        for (int i = 0; i < r; i++) {
            printf("Resource %d: ", i + 1);
            scanf("%d", &request[i]);
        }

        for (int i = 0; i < r; i++) {
            if (request[i] > need[pid][i]) {
                printf("\nError: Request exceeds need.\n");
                return;
            }
        }

        for (int i = 0; i < r; i++) {
            if (request[i] > avail[i]) {
                printf("\nError: Request exceeds available resources.\n");
                return;
            }
        }

        for (int i = 0; i < r; i++) {
            avail[i] -= request[i];
            alloc[pid][i] += request[i];
            need[pid][i] -= request[i];
        }

        calculate();
    }
}
