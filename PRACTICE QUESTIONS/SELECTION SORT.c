	#include <stdio.h>

int main() {
    int i, j, min;
    int arr[] = {5, 1, 3, 8, 9};
    int n = 5;

    // Selection Sort
    for(i = 0; i < n - 1; i++) {
        min = i; 
        
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap after finding the minimum element
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    // Print sorted array
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}