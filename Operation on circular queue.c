#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    int value;

    if ((rear + 1) % MAX == front) {
        printf("Queue overflow\n");
    }
    else {
        printf("Enter value to be inserted: ");
        scanf("%d", &value);

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue underflow\n");
    }
    else {
        printf("Element deleted: %d\n", queue[front]);

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Elements are:\n");

        i = front;

        while (1) {
            printf("%d\n", queue[i]);

            if (i == rear) {
                break;
            }

            i = (i + 1) % MAX;
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}
