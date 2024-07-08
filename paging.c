#include <stdio.h>

int main() {
    int memorySize, pageSize, numPages, numProcesses, remainingPages;
    int processPages[10], pageTable[10][20];
    int processNumber, pageNumber, offset, physicalAddress;

    // Input memory size and page size
    printf("Enter the memory size: ");
    scanf("%d", &memorySize);
    printf("Enter the page size: ");
    scanf("%d", &pageSize);

    // Calculate the number of pages
    numPages = memorySize / pageSize;
    printf("The number of pages available in memory: %d\n", numPages);

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    remainingPages = numPages;

    // Input page requirements and page tables for each process
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

    // Input logical address to find the physical address
    printf("Enter process number, page number, and offset: ");
    scanf("%d %d %d", &processNumber, &pageNumber, &offset);

    // Validate the input
    if (processNumber > numProcesses || pageNumber >= processPages[processNumber] || offset >= pageSize) {
        printf("Invalid process number, page number, or offset\n");
    } else {
        // Calculate the physical address
        physicalAddress = pageTable[processNumber][pageNumber] * pageSize + offset;
        printf("The physical address is: %d\n", physicalAddress);
    }

    return 0;
}
