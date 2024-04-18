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

    printf("Sequence is: ");
    for (i = pos; i <= q_size; i++) {
        printf("%d ", queue[i]);
        seek += abs(queue[i] - queue[i - 1]);
    }

    seek += abs(queue[q_size] - 0);
    seek += abs(0 - queue[1]);
    printf("0 ");
    for (i = 1; i < pos; i++) {
        printf("%d ", queue[i]);
        seek += abs(queue[i] - queue[i - 1]);
    }

    printf("\nTotal seek time: %d\n", seek);
    avg_seek = (float)seek / q_size;
    printf("Average seek time: %f\n", avg_seek);

    return 0;
}

