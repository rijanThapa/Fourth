#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findClosestRequest(int *requests, int n, int head) {
    int minDistance = INT_MAX;
    int index = -1;
    int i;
    
    for (i = 0; i < n; ++i) {
        if (!requests[i])
            continue;
        
        int distance = abs(requests[i] - head);
        if (distance < minDistance) {
            minDistance = distance;
            index = i;
        }
    }
    
    return index;
}

int sstf(int *requests, int n, int head) {
    int totalSeekTime = 0;
    int j; // Declaration moved here
    
    for (j = 0; j < n; ++j) {
        int closestRequestIndex = findClosestRequest(requests, n, head);
        if (closestRequestIndex == -1)
            break;
        
        totalSeekTime += abs(requests[closestRequestIndex] - head);
        head = requests[closestRequestIndex];
        requests[closestRequestIndex] = 0;
    }
    
    return totalSeekTime;
}

int main() {
    int n;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    
    int *requests = (int *)malloc(n * sizeof(int));
    if (requests == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter the requests: ");
    int i;
    for (i = 0; i < n; ++i)
        scanf("%d", &requests[i]);
    
    int head;
    printf("Enter the current position of the disk head: ");
    scanf("%d", &head);
    
    int totalSeekTime = sstf(requests, n, head);
    printf("Total seek time using SSTF algorithm: %d\n", totalSeekTime);
    
    free(requests);
    return 0;
}

