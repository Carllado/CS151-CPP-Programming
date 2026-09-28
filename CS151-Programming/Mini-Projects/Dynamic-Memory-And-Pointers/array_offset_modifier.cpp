// File: array_offset_modifier.cpp
// Author: Carl Chu
// Date: 04/18/2026
// Purpose: Use a pointer to modify the original array 
//          and tracks exactly how many elements were actually changed to a different value.

#include <stdio.h>

int setByOffset(int* arr, int totalSize, int offset, int n, int val) {
    int changedCount = 0;

    // Boundary check to prevent crashing if offset + n exceeds size
    for (int i = offset; i < offset + n && i < totalSize; i++) {
        if (arr[i] != val) {
            arr[i] = val;
            changedCount++; // Only count if the value actually changed
        }
    }
    return changedCount;
}

int main() {
    int myArray[18] = {0}; // Initialize all to 0
    
    // Set 6 elements to -9 starting at index 4
    int changed = setByOffset(myArray, 18, 4, 6, -9);
    
    printf("Elements changed: %d\n", changed);
    for (int i = 0; i < 18; i++) {
        printf("[%d]", myArray[i]);
    }
    printf("\n");
    
    return 0;
}