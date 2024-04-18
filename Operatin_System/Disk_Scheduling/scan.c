#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[100], head, q_size, i, j, seek = 0, temp;
    float avg_seek;

    printf("Enter the size of disk queue: ");
    scanf("%d", &q_size);

    printf("Enter the disk queue: ");
    for (i = 1; i <= q_size; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter initial position of disk head: ");
    scanf("%d", &head);

    queue[0] = head;

    // Sorting the array
    for (i = 0; i <= q_size; i++) {
        for (j = i + 1; j <= q_size; j++) {
            if (queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    int pos;
    for (i = 0; i <= q_size; i++) {
        if (queue[i] == head) {
            pos = i;
            break;
        }
    }

    int prev = 0;

    printf("Sequence is: ");
    for (i = pos; i >= 0; i--) {
        printf("%d ", queue[i]);
        seek += abs(queue[i] - prev);
        prev = queue[i];
    }

    seek += abs(prev);

    

    for (i = pos + 1; i <= q_size; i++) {
        printf("%d ", queue[i]);
        seek += abs(queue[i] - prev);
        prev = queue[i];
    }

    printf("\nTotal seek time: %d\n", seek);
    avg_seek = (float)seek / q_size;
    printf("Average seek time: %f\n", avg_seek);

    return 0;
}

