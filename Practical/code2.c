#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n, element, position;
    int i;
    
    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Check if array is full
    if (n >= MAX) {
        printf("Array is full! Cannot insert more elements.\n");
        return 0;
    }
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Input position to insert
    printf("\nEnter the position to insert (1 to %d): ", n + 1);
    scanf("%d", &position);
    
    // Validate position
    if (position < 1 || position > n + 1) {
        printf("Invalid position! Position should be between 1 and %d\n", n + 1);
        return 0;
    }
    
    // Input element to insert
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    
    // Shift elements to the right from the end to the insertion position
    for (i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert element at specified position
    arr[position - 1] = element;
    n++;
    
    // Display the array after insertion
    printf("\nArray after insertion at position %d:\n", position);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
