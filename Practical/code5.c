#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n, position;
    int i;
    
    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Check if array is empty
    if (n <= 0) {
        printf("Array is empty! Cannot delete.\n");
        return 0;
    }
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Display array before deletion
    printf("\nArray before deletion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Input position to delete
    printf("\nEnter the position to delete (1 to %d): ", n);
    scanf("%d", &position);
    
    // Validate position
    if (position < 1 || position > n) {
        printf("Invalid position! Position should be between 1 and %d\n", n);
        return 0;
    }
    
    // Delete element from specified position
    printf("Deleting element at position %d: %d\n", position, arr[position - 1]);
    
    // Shift elements to the left from the deletion position
    for (i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    
    // Display the array after deletion
    printf("\nArray after deletion from position %d:\n", position);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
