#include <stdio.h>
int frames[3]; 
void display(); 
int main() {
    int i, j;
    int pages[7] = {7, 0, 1, 2, 0, 3, 0}; 
    int flag1, flag2, pageFaults = 0, frameSize = 3, top = 0;
    for(i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }
    for(j = 0; j < 7; j++) {
        flag1 = 0;
        flag2 = 0;
        for(i = 0; i < frameSize; i++) {
            if(frames[i] == pages[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        if(flag1 == 0) {
            for(i = 0; i < frameSize; i++) {
                if(frames[i] == -1) {
                    frames[i] = pages[j];
                    flag2 = 1;
                    break;
                }
            }
        }
        if(flag2 == 0) {
            frames[top] = pages[j];
            top = (top + 1) % frameSize;
            pageFaults++;
        }
        display();
    }
    printf("Number of page faults: %d\n", pageFaults + frameSize);
    return 0;
}
void display() {
    int i;
    printf("\n");
    for(i = 0; i < 3; i++) {
        if(frames[i] != -1)
            printf("%d\t", frames[i]);
        else
            printf("-\t");
    }
    printf("\n");
}
