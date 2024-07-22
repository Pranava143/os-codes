#include <stdio.h>
int frames[3]; 
void display(); 
int main() {
    int pages[12] = {1,2,3,4,1,2,5,1,2,3,4,5}; 
    int i, j, k, flag1, flag2, pageFaults = 0, frameSize = 3, index;
    int future[3]; 
    for(i = 0; i < frameSize; i++)
        frames[i] = -1;
    for(j = 0; j < 12; j++) {
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
            for(i = 0; i < frameSize; i++)
                future[i] = 0;
            for(i = 0; i < frameSize; i++) {
                for(k = j + 1; k < 12; k++) {
                    if(frames[i] == pages[k]) {
                        future[i] = k;
                        break;
                    }
                }
            }
            int maxIndex = -1;
            int maxFuture = -1;
            for(i = 0; i < frameSize; i++) {
                if(future[i] == 0) {
                    maxIndex = i;
                    break;
                } else if(future[i] > maxFuture) {
                    maxFuture = future[i];
                    maxIndex = i;
                }
            }
            frames[maxIndex] = pages[j];
            pageFaults++;
        }
        display();
    }
    printf("Number of page faults: %d\n", pageFaults+frameSize);
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
