#include <stdio.h>
#include <stdlib.h>

#define N 5

void insert(int queue[], int *rear, int *j);
void delete(int queue[], int *front, int *rear, int *x);
void display(int queue[], int front, int rear);

int main() {
    int queue[N];
    int ch = 1, front = 0, rear = 0, i, j = 1, x = N;

    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");

    while (ch) {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert(queue, &rear, &j);
                break;
            case 2:
                delete(queue, &front, &rear, &x);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice: please see the options.");
        }
    }

    return 0;
}

void insert(int queue[], int *rear, int *j) {
    if (*rear == N) {
        printf("\nQueue is full");
    } else {
        printf("\nEnter no %d: ", (*j)++);
        scanf("%d", &queue[(*rear)++]);
    }
}

void delete(int queue[], int *front, int *rear, int *x) {
    if (*front == *rear) {
        printf("\nQueue is empty");
    } else {
        printf("\nDeleted element is %d", queue[(*front)++]);
        (*x)++;
    }
}

void display(int queue[], int front, int rear) {
    if (front == rear) {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue elements are:\n");
        for (int i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
