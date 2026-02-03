#include <stdio.h>
#include <stdlib.h>

/*
 * LINKED LIST - INSERT AT FIRST POSITION
 * 
 * This program demonstrates insertion at the beginning of a singly linked list.
 * Time Complexity: O(1) - Constant time for insertion
 * Space Complexity: O(1) - Only one new node created
 */

// Node structure definition
struct Node {
    int data;           // Data part of the node
    struct Node* next;  // Pointer to the next node
};

// Global head pointer - points to the first node
struct Node* head = NULL;

/**
 * INSERT AT FIRST POSITION
 * 
 * Algorithm:
 * 1. Create a new node
 * 2. Set new node's data
 * 3. Point new node's next to current head
 * 4. Update head to point to new node
 * 
 * Example: Insert 10 in empty list
 *   Before: head -> NULL
 *   After:  head -> [10|next] -> NULL
 * 
 * Example: Insert 20 in list [10]
 *   Before: head -> [10|next] -> NULL
 *   After:  head -> [20|next] -> [10|next] -> NULL
 */
void insertAtFirst(int value) {
    // Step 1: Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("❌ Memory allocation failed!\n");
        return;
    }
    
    // Step 2: Set the data for new node
    newNode->data = value;
    
    // Step 3: Point new node to current head (even if head is NULL)
    newNode->next = head;
    
    // Step 4: Update head to point to new node
    head = newNode;
    
    printf("✅ %d inserted at the beginning.\n", value);
}

// Delete element from the first position
void deleteAtFirst() {
    if (head == NULL) {
        printf("List is empty! No element to delete.\n");
        return;
    }

    struct Node* nodeToDelete = head;
    int deletedValue = head->data;
    
    // Move head to the next node
    head = head->next;
    
    // Free the memory of the deleted node
    free(nodeToDelete);
    
    printf("%d deleted from the first position.\n", deletedValue);
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

// Demonstrate insertion with examples
void demonstrateInsertion() {
    printf("\n🔍 DEMONSTRATION: Insert at First Position\n");
    printf("==========================================\n");
    
    printf("\n1. Starting with empty list:\n");
    display();
    
    printf("\n2. Insert 10 at first position:\n");
    insertAtFirst(10);
    display();
    
    printf("\n3. Insert 20 at first position:\n");
    insertAtFirst(20);
    display();
    
    printf("\n4. Insert 30 at first position:\n");
    insertAtFirst(30);
    display();
    
    printf("\n📝 Notice: New elements are added at the beginning,\n");
    printf("   making the list: 30 -> 20 -> 10 -> NULL\n");
    printf("   (reverse order of insertion)\n");
}

int main() {
    int choice, value;

    // Show program header
    printf("\n🔗 LINKED LIST - INSERT AT FIRST POSITION\n");
    printf("=========================================\n");
    printf("Time Complexity: O(1) for insertion\n");
    printf("Space Complexity: O(1) per node\n");

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at First Position\n");
        printf("2. Delete at First Position\n");
        printf("3. Display List\n");
        printf("4. Count Nodes\n");
        printf("5. Run Demonstration\n");
        printf("6. Delete All Nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("\n📥 Inserting %d at first position...\n", value);
                insertAtFirst(value);
                printf("Current list: ");
                display();
                break;
            case 2:
                deleteAtFirst();
                printf("Current list: ");
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("📊 Total nodes: %d\n", countNodes());
                break;
            case 5:
                deleteList(); // Clear existing list first
                demonstrateInsertion();
                break;
            case 6:
                deleteList();
                break;
            case 7:
                deleteList(); // Clean up before exit
                printf("👋 Exiting... Memory cleaned up.\n");
                exit(0);
            default:
                printf("❌ Invalid choice! Try again.\n");
        }
    }

    return 0;
}
