// File: array_comparison.cpp
// Author: Carl Chu
// Date: 04/18/2026
//Purpose: Treat arrays of different lengths as not equal

#include <stdio.h>

/* Compare two arrays. 
 * Returns 0 if identical.
 * Returns (arr1[i] - arr2[i]) for the first mismatch.
 * If lengths differ, returns the difference in lengths.
 */
int compareArrays(int* a1, int size1, int* a2, int size2) {
    if (size1 != size2) {
        return size1 - size2; // Return length difference if sizes don't match
    }

    for (int i = 0; i < size1; i++) {
        if (a1[i] != a2[i]) {
            return a1[i] - a2[i]; // Return difference of first mismatch
        }
    }
    return 0;
}

int main() {
    int first[] = {1, 2, 3, 4};
    int second[] = {1, 2, 5, 4};
    int third[] = {1, 2, 3, 4};

    printf("Result (1 vs 2): %d\n", compareArrays(first, 4, second, 4)); // -2
    printf("Result (1 vs 3): %d\n", compareArrays(first, 4, third, 4));  // 0
    return 0;
}