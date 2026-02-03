#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n;
    int i, j, count;
    int visited[MAX] = {0};  // To mark visited elements
    
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
    
    // Display the array
    printf("\nArray elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Find and display duplicates
    printf("\n--- Duplicate Elements ---\n");
    int duplicateFound = 0;
    
    for (i = 0; i < n; i++) {
        // Skip if already visited
        if (visited[i] == 1) {
            continue;
        }
        
        // Count occurrences of current element
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;  // Mark as visited
            }
        }
        
        // If count > 1, it's a duplicate
        if (count > 1) {
            printf("Element %d appears %d times\n", arr[i], count);
            duplicateFound = 1;
        }
    }
    
    if (!duplicateFound) {
        printf("No duplicate elements found!\n");
    }
    
    return 0;
}