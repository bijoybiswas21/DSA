#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n;
    int i;
    
    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    // Check if array is valid
    if (n <= 0 || n > MAX) {
        printf("Invalid array size!\n");
        return 0;
    }
    
    // Input array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // Traverse and display array elements
    printf("\nTraversal of array (Forward):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Traverse and display array elements in reverse
    printf("\nTraversal of array (Backward):\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Display elements with their indices
    printf("\nTraversal with indices:\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    return 0;
}
