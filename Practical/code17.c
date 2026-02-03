#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert element at the beginning (for testing deletion)
void insertAtFirst(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d inserted.\n", value);
}

// Delete element from the last position
void deleteAtLast() {
    if (head == NULL) {
        printf("List is empty! No element to delete.\n");
        return;
    }

    // If only one node exists
    if (head->next == NULL) {
        int value = head->data;
        free(head);
        head = NULL;
        printf("%d deleted from the last position.\n", value);
        return;
    }

    // Traverse to the second last node
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete the last node
    int deletedValue = temp->next->data;
    free(temp->next);
    temp->next = NULL;

    printf("%d deleted from the last position.\n", deletedValue);
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
        printf("\n--- Linked List (Delete at Last) ---\n");
        printf("1. Insert\n");
        printf("2. Delete at Last\n");
        printf("3. Display\n");
        printf("4. Count Nodes\n");
        printf("5. Delete All\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtFirst(value);
                break;
            case 2:
                deleteAtLast();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 5:
                deleteList();
                break;
            case 6:
                deleteList(); // Clean up before exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
