#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n;
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
    
    // Delete element from last position
    printf("\nDeleting element from last position: %d\n", arr[n - 1]);
    n--;
    
    // Display the array after deletion
    printf("\nArray after deletion from last position:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
