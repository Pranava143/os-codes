#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    int fd[2], n;
    char buffer[100];
    pid_t p;
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    p = fork();
    if (p > 0) {
        printf("Parent passing value to child\n");
        close(fd[0]);
        write(fd[1], "hello\n", 6);
        close(fd[1]);
        int status;
        wait(&status);
    } else if (p == 0) {
        close(fd[1]);
        printf("Child printing received value\n");
        n = read(fd[0], buffer, 100);
        write(1, buffer, n);
        close(fd[0]);
    } else {
        perror("fork");
        return 1;
    }
    return 0;
}








#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <linux/stat.h>
#define FIFO_FILE "w6.txt"
int main(void) {
    FILE *fp;
    char readbuff[80];
    umask(0);
    mknod(FIFO_FILE, S_IFIFO | 0666, 0);
    while (1) {
        fp = fopen(FIFO_FILE, "r");
        fgets(readbuff, 80, fp);
        printf("Received string is: %s\n", readbuff);
        fclose(fp);
    }
    exit(0);
    return 0;
}

