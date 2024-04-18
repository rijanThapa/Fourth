#include <stdio.h>
#include <stdlib.h>

// Function to calculate total seek time
int calculateSeekTime(int requests[], int head, int n) {
    int seekTime = 0, i;
    
    // Calculate seek time for each request
    for ( i = 0; i < n; i++) {
        seekTime += abs(head - requests[i]);
        head = requests[i];
    }
    
    return seekTime;
}

int main() {
    int n; // Number of requests
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n], i; // Array to store requests

    // Input requests
    printf("Enter the disk requests: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    int head; // Starting head position
    printf("Enter the starting head position: ");
    scanf("%d", &head);

    // Calculate total seek time
    int seekTime = calculateSeekTime(requests, head, n);
    
    // Output the total seek time
    printf("Total seek time: %d\n", seekTime);

    return 0;
}

