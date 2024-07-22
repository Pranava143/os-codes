#include <sys/stat.h> 
#include <stdio.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    int i = 0; 
    int f1, f2; 
    char c, strin[100]; 
    f1 = open("data", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (f1 < 0) {
        perror("Failed to open file for writing");
        return 1;
    }
    while ((c = getchar()) != '\n') { 
        strin[i++] = c; 
    } 
    strin[i] = '\0'; 
    write(f1, strin, i); 
    close(f1); 
    f2 = open("data", O_RDONLY); 
    if (f2 < 0) {
        perror("Failed to open file for reading");
        return 1;
    }
    read(f2, strin, i);
    strin[i] = '\0';
    printf("\n%s\n", strin); 
    close(f2); 
    return 0; 
}










#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
int main() 
{ 
    int i = 0; 
    int f1, f2; 
    char c, strin[100]; 
    f1 = open("data", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (f1 < 0) {
        perror("Failed to open file for writing");
        return 1;
    }
    while ((c = getchar()) != '\n') { 
        strin[i++] = c; 
    } 
    strin[i] = '\0'; 
    write(f1, strin, i); 
    close(f1); 
    f2 = open("data", O_RDONLY); 
    if (f2 < 0) {
        perror("Failed to open file for reading");
        return 1;
    }
    read(f2, strin, i); 
    strin[i] = '\0';
    printf("\n%s\n", strin); 
    close(f2); 
    
    return 0; 
}


