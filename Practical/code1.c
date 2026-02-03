#include <stdio.h>

#define MAX 100

int main() {
    int arr[MAX];
    int n, element;
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
    
    // Input element to insert at first position
    printf("\nEnter the element to insert at first position: ");
    scanf("%d", &element);
    
    // Shift elements to the right
    for (i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert element at first position
    arr[0] = element;
    n++;
    
    // Display the array after insertion
    printf("\nArray after insertion at first position:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
