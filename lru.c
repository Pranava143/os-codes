#include <stdio.h>

int frames[3]; // Array to hold the pages in memory frames

void display(); // Function prototype for displaying the current state of frames

int main() {
    int pages[12] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2}; // Array of pages to be loaded
    int i, j, k, l, flag1, flag2, pageFaults = 0, frameSize = 3, index;
    int usage[3]; // Array to keep track of page usage

    // Initialize all frames to -1 indicating they are empty
    for(i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

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

        // If the page is not in any frame and there are no empty frames, replace the least recently used page
        if(flag2 == 0) {
            for(i = 0; i < frameSize; i++)
                usage[i] = 0;

            // Check the pages in the frames to determine the least recently used one
            for(k = j - 1, l = 1; l <= frameSize - 1; l++, k--) {
                for(i = 0; i < frameSize; i++) {
                    if(frames[i] == pages[k])
                        usage[i] = 1;
                }
            }

            // Find the frame that is not recently used
            for(i = 0; i < frameSize; i++) {
                if(usage[i] == 0)
                    index = i;
            }

            frames[index] = pages[j];
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
