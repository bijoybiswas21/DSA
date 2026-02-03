#include <stdio.h>
#include <stdlib.h>
#define MAX 5  
int stack[MAX];
int top = -1;

void push(int element) {
    if (top == MAX - 1) {
        printf("Stack overflow! Cannot insert %d\n", element);
    } else {
        stack[++top] = element;
        printf("%d pushed to stack.\n", element);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow! No element to delete.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return -1; 
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek (Top)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Stack is full!\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(value);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Stack is empty!\n");
                } else {
                    pop();
                }
                break;
            case 3:
                display();
                break;
            case 4:
                if (!isEmpty()) {
                    printf("Top element: %d\n", peek());
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