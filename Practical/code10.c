#include <stdio.h>
#include <stdlib.h>

int *stack = NULL;
int capacity = 0;
int top = -1;

int is_empty() {
    return top == -1;
}

int is_full() {
    return top == capacity - 1;
}

void push(int value) {
    if (is_full()) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
    printf("%d pushed to stack.\n", value);
}

void pop() {
    if (is_empty()) {
        printf("Stack underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

void display() {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top -> bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void peek() {
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

int main() {
    int choice;
    int value;

    printf("Enter stack size: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        printf("Invalid stack size.\n");
        return 1;
    }

    stack = (int *)malloc(sizeof(int) * capacity);
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek (Top)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Try again.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                free(stack);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}