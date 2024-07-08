#include <stdio.h>
int frames[3]; // Array to hold the pages in memory frames
void display(); // Function prototype for displaying the current state of frames
int main() {
    int pages[12] = {1,2,3,4,1,2,5,1,2,3,4,5}; // Array of pages to be loaded
    int i, j, k, flag1, flag2, pageFaults = 0, frameSize = 3, index;
    int future[3]; // Array to keep track of page usage in future
    // Initialize all frames to -1 indicating they are empty
    for(i = 0; i < frameSize; i++)
        frames[i] = -1;
    // Iterate over each page to be loaded
    for(j = 0; j < 12; j++) {
        flag1 = 0;
        flag2 = 0;
        // Check if the page is already in one of the frames
        for(i = 0; i < frameSize; i++) {
            if(frames[i] == pages[j]) {
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        // If the page is not in any frame, try to place it in an empty frame
        if(flag1 == 0) {
            for(i = 0; i < frameSize; i++) {
                if(frames[i] == -1) {
                    frames[i] = pages[j];
                    flag2 = 1;
                    break;
                }
            }
        }
        // If the page is not in any frame and there are no empty frames, replace the optimal page
        if(flag2 == 0) {
            for(i = 0; i < frameSize; i++)
                future[i] = 0;
            // Check the pages in the frames to determine the optimal page to replace
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
        // Display the current state of frames
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
