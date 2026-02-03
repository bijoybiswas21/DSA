#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int element) {
    if (rear == MAX - 1) {
        printf("Queue overflow! Cannot insert %d\n", element);
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = element;
        printf("%d enqueued to queue.\n", element);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow! No element to delete.\n");
        front = rear = -1;
    } else {
        printf("%d dequeued from queue.\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;  // Reset queue when empty
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int peek() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue[front];
}

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX - 1;
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek (Front)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Queue is full!\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue is empty!\n");
                } else {
                    dequeue();
                }
                break;
            case 3:
                display();
                break;
            case 4:
                if (!isEmpty()) {
                    printf("Front element: %d\n", peek());
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
