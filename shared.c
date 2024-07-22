#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *shared_memory = (char*) shmat(shmid, NULL, 0);
    printf("Write Data: ");
    scanf("%s", shared_memory);
    printf("Data written in memory: %s\n", shared_memory);
    shmdt(shared_memory);
    return 0;
}




#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
int main() {
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char *shared_memory = (char*) shmat(shmid, NULL, 0);
    printf("Data read from memory: %s\n", shared_memory);
    shmdt(shared_memory);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
