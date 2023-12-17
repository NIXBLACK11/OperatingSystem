#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10

void lruPageReplacement(int pages[], int n, int capacity) {
    int frame[MAX_FRAMES];
    int pageOrder[MAX_FRAMES];
    int pageFaults = 0;

    for (int i = 0; i < MAX_FRAMES; i++) {
        frame[i] = -1;  // Initialize frames to -1 (indicating empty)
        pageOrder[i] = 0;  // Initialize page order to 0
    }

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];

        // Check if the page is already in the frame
        int pageFound = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == currentPage) {
                pageFound = 1;
                pageOrder[j] = i + 1;  // Update the page order to the current access time
                break;
            }
        }

        if (!pageFound) {
            // Page fault, replace the least recently used page
            int minOrderIndex = 0;
            for (int j = 1; j < capacity; j++) {
                if (pageOrder[j] < pageOrder[minOrderIndex]) {
                    minOrderIndex = j;
                }
            }

            frame[minOrderIndex] = currentPage;
            pageOrder[minOrderIndex] = i + 1;  // Update the page order to the current access time

            pageFaults++;
        }

        // Display the current state of the frame after each page access
        printf("Page %d: [", currentPage);
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == -1) {
                printf("-");  // Display "-" for empty frames
            } else {
                printf("%d", frame[j]);
            }

            if (j < capacity - 1) {
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

    printf("\nLRU Page Replacement Algorithm:\n");
    lruPageReplacement(pages, n, capacity);

    return 0;
}
