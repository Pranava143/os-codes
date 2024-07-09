#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Generate a unique key
    key_t key = ftok("shmfile", 65);

    // Create a shared memory segment
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach to the shared memory segment
    char *shared_memory = (char*) shmat(shmid, NULL, 0);

    // Get input from the user
    printf("Write Data: ");
    scanf("%s", shared_memory);

    printf("Data written in memory: %s\n", shared_memory);

    // Detach from the shared memory segment
    shmdt(shared_memory);

    return 0;
}




#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    // Generate a unique key
    key_t key = ftok("shmfile", 65);

    // Locate the shared memory segment
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach to the shared memory segment
    char *shared_memory = (char*) shmat(shmid, NULL, 0);

    // Print the data from the shared memory
    printf("Data read from memory: %s\n", shared_memory);

    // Detach from the shared memory segment
    shmdt(shared_memory);

    // Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
