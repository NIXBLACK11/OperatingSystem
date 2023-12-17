#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

void fifoPageReplacement(int pages[], int n, int capacity) {
    int frame[MAX_FRAMES];
    int frameIndex = 0;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];

        // Check if the page is already in the frame
        int pageFound = 0;
        for (int j = 0; j < frameIndex; j++) {
            if (frame[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            // Page fault, replace the oldest page in the frame
            if (frameIndex < capacity) {
                // Still space in the frame, add the page
                frame[frameIndex] = currentPage;
                frameIndex++;
            } else {
                // Frame is full, replace the oldest page (first-in)
                for (int j = 0; j < capacity - 1; j++) {
                    frame[j] = frame[j + 1];
                }
                frame[capacity - 1] = currentPage;
            }

            pageFaults++;
        }

        // Display the current state of the frame after each page access
        printf("Page %d: [", currentPage);
        for (int j = 0; j < frameIndex; j++) {
            printf("%d", frame[j]);
            if (j < frameIndex - 1) {
                printf(", ");
            }
        }
        printf("] %s\n", pageFound ? "(Page Hit)" : "(Page Fault)");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter the page reference sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    printf("\nFIFO Page Replacement Algorithm:\n");
    fifoPageReplacement(pages, n, capacity);

    return 0;
}
