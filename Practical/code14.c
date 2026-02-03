#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert element at the last position
void insertAtLast(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty, make new node the first node
    if (head == NULL) {
        head = newNode;
        printf("%d inserted as the first element.\n", value);
        return;
    }

    // Traverse to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Link the last node to the new node
    temp->next = newNode;
    printf("%d inserted at the last position.\n", value);
}

// Display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Count nodes in the list
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Delete all nodes to free memory
void deleteList() {
    struct Node* current = head;
    struct Node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    printf("All nodes deleted.\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linked List (Insert at Last) ---\n");
        printf("1. Insert at Last\n");
        printf("2. Display\n");
        printf("3. Count Nodes\n");
        printf("4. Delete All\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtLast(value);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 4:
                deleteList();
                break;
            case 5:
                deleteList(); // Clean up before exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
