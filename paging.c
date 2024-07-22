#include <stdio.h>
int main() {
    int memorySize, pageSize, numPages, numProcesses, remainingPages;
    int processPages[10], pageTable[10][20];
    int processNumber, pageNumber, offset, physicalAddress;
    printf("Enter the memory size: ");
    scanf("%d", &memorySize);
    printf("Enter the page size: ");
    scanf("%d", &pageSize);
    numPages = memorySize / pageSize;
    printf("The number of pages available in memory: %d\n", numPages);
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);
    remainingPages = numPages;
    for (int i = 1; i <= numProcesses; i++) {
        printf("Enter number of pages required for process[%d]: ", i);
        scanf("%d", &processPages[i]);
        if (processPages[i] > remainingPages) {
            printf("Memory is full\n");
            break;
        }
        remainingPages -= processPages[i];
        printf("Enter page table for process[%d]:\n", i);
        for (int j = 0; j < processPages[i]; j++) {
            scanf("%d", &pageTable[i][j]);
        }
    }
    printf("Enter process number, page number, and offset: ");
    scanf("%d %d %d", &processNumber, &pageNumber, &offset);
    if (processNumber > numProcesses || pageNumber >= processPages[processNumber] || offset >= pageSize) {
        printf("Invalid process number, page number, or offset\n");
    } else {
        physicalAddress = pageTable[processNumber][pageNumber] * pageSize + offset;
        printf("The physical address is: %d\n", physicalAddress);
    }
    return 0;
}
