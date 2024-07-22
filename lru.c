#include <stdio.h>

int frames[3]; 

void display(); 
int main() {
    int pages[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2}; 
    int i, j, k, l, flag1, flag2, pageFaults = 0, frameSize = 3, index;
    int usage[3]; 
    for(i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }
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
                usage[i] = 0;
            for(k = j - 1, l = 1; l <= frameSize - 1; l++, k--) {
                for(i = 0; i < frameSize; i++) {
                    if(frames[i] == pages[k])
                        usage[i] = 1;
                }
            }
            for(i = 0; i < frameSize; i++) {
                if(usage[i] == 0)
                    index = i;
            }
            frames[index] = pages[j];
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
