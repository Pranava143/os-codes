#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    char d[100];
    int c, op;
    DIR *e;
    struct dirent *sd;
    printf("**menu**\n1. Create directory\n2. Remove directory\n3. Read directory\nEnter your choice: ");
    scanf("%d", &op);
    switch(op) {
        case 1:
            printf("Enter directory name: ");
            scanf("%s", d);
            c = mkdir(d, 0777);
            if (c == -1) 
                perror("Directory not created");
            else 
                printf("Directory created\n");
            break;
        case 2:
            printf("Enter directory name: ");
            scanf("%s", d);
            c = rmdir(d);
            if (c == -1) 
                perror("Directory not removed");
            else 
                printf("Directory removed\n");
            break;
        case 3:
            printf("Enter directory name to open: ");
            scanf("%s", d);
            e = opendir(d);
            if (e == NULL) {
                perror("Directory does not exist");
            } else {
                printf("Directory exists\n");
                while ((sd = readdir(e)) != NULL)
                    printf("%s\t", sd->d_name);
                printf("\n");
                closedir(e);
            }
            break;
        default:
            printf("Invalid option\n");
            break;
    }
    return 0;
}
