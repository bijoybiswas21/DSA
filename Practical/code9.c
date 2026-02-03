#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n;
    int i, search_element;
    int found = 0;
    
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
    
    // Input element to search
    printf("\nEnter the element to search: ");
    scanf("%d", &search_element);
    
    // Search for the element
    printf("\nSearching for element %d:\n", search_element);
    for (i = 0; i < n; i++) {
        if (arr[i] == search_element) {
            printf("Element found at position: %d (index: %d)\n", i + 1, i);
            found = 1;
        }
    }
    
    // Display result if not found
    if (!found) {
        printf("Element not found in the array!\n");
    }
    
    return 0;
}
