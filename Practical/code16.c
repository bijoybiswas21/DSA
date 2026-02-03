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

// Delete element from the first position
void deleteAtFirst() {
    if (head == NULL) {
        printf("List is empty! No element to delete.\n");
        return;
    }

    struct Node* nodeToDelete = head;
    int deletedValue = head->data;
    head = head->next;
    free(nodeToDelete);
    printf("%d deleted from the first position.\n", deletedValue);
}

// Delete element at any position (1-based index) - Simplified
void deleteAtPosition(int position) {
    // Validate input
    if (position < 1) {
        printf("Invalid position! Position should be >= 1.\n");
        return;
    }

    if (head == NULL) {
        printf("List is empty! No element to delete.\n");
        return;
    }

    // Delete from first position
    if (position == 1) {
        struct Node* temp = head;
        int value = head->data;
        head = head->next;
        free(temp);
        printf("%d deleted from position %d.\n", value, position);
        return;
    }

    // Delete from middle or end
    struct Node* temp = head;
    int count = 1;

    // Traverse to (position - 1)th node
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    // Check if position exists
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range! List has only %d nodes.\n", count);
        return;
    }

    struct Node* nodeToDelete = temp->next;
    int deletedValue = nodeToDelete->data;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);

    printf("%d deleted from position %d.\n", deletedValue, position);
}

// Display the linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    int position = 1;
    while (temp != NULL) {
        printf("[%d: %d] -> ", position, temp->data);
        temp = temp->next;
        position++;
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
    int choice, value, position;

    while (1) {
        printf("\n--- Linked List (Delete at Any Position) ---\n");
        printf("1. Insert\n");
        printf("2. Delete at First\n");
        printf("3. Delete at Any Position\n");
        printf("4. Display\n");
        printf("5. Count Nodes\n");
        printf("6. Delete All\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtFirst(value);
                break;
            case 2:
                deleteAtFirst();
                break;
            case 3:
                printf("Enter position to delete (1-based): ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Total nodes: %d\n", countNodes());
                break;
            case 6:
                deleteList();
                break;
            case 7:
                deleteList(); // Clean up before exit
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
