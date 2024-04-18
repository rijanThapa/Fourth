#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int temp , i, j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void LOOK(int request[], int head, int size) {
    int seek_count = 0;
    int distance, cur_track;
    sort(request, size);
    int direction = (request[0] - head) > 0 ? 1 : -1;
int i;
    for ( i = 0; i < size; i++) {
        cur_track = request[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
        printf("Servicing track %d\n", head);
    }
    printf("Total seek count = %d\n", seek_count);
}

int main() {
    int n, i, head;
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    int *request = (int *)malloc(n * sizeof(int));
    if (request == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the requests: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    LOOK(request, head, n);
    free(request);
    return 0;
}

