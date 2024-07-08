#include <stdio.h>

int frames[3]; // Array to hold the pages in memory frames

void display(); // Function prototype for displaying the current state of frames

int main() {
    int i, j;
    int pages[7] = {7, 0, 1, 2, 0, 3, 0}; // Correct size of array for pages
    int flag1, flag2, pageFaults = 0, frameSize = 3, top = 0;

    // Initialize all frames to -1 indicating they are empty
    for(i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    // Iterate over each page to be loaded
    for(j = 0; j < 7; j++) {
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

        // If the page is not in any frame and there are no empty frames, replace the oldest page
        if(flag2 == 0) {
            frames[top] = pages[j];
            top = (top + 1) % frameSize;
            pageFaults++;
        }

        // Display the current state of frames
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
