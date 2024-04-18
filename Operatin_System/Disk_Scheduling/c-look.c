#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
	int i,j;
    for ( i = 0; i < n - 1; i++) {
        for ( j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void clook(int arr[], int head, int size) {
    int seek_count = 0;
    int distance, cur_track;
    int visited[size] , i;

    for ( i = 0; i < size; i++) {
        visited[i] = 0;
    }

    int index = 0;
    int min_distance = 1000;
  

    for ( i = 0; i < size; i++) {
        if (abs(arr[i] - head) < min_distance) {
            index = i;
            min_distance = abs(arr[i] - head);
        }
    }

    for ( i = index; i < size; i++) {
        cur_track = arr[i];
        if (!visited[i]) {
            seek_count += abs(cur_track - head);
            head = cur_track;
            visited[i] = 1;
        }
    }

    for ( i = 0; i < index; i++) {
        cur_track = arr[i];
        if (!visited[i]) {
            seek_count += abs(cur_track - head);
            head = cur_track;
            visited[i] = 1;
        }
    }

    printf("Total number of seek operations = %d\n", seek_count);
}

int main() {
    int n, head;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    int arr[n], i;
    
    printf("Enter the queue elements:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    sort(arr, n);

    clook(arr, head, n);

    return 0;
}

