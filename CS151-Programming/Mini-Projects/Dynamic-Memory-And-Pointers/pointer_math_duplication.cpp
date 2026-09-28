// File: pointer_math_duplication.cpp
// Author: Carl Chu
// Date: 04/18/2026
// Purpose: Use the new keyword to put data on the Heap
//          The same task as Q2 but replaces arr[i]

#include <stdio.h>

int* arrDupPointerMath(int* source, int length) {
    int* newArr = new int[length];
    
    for (int i = 0; i < length; i++) {
        // Access values by adding i to the starting address
        *(newArr + i) = *(source + i); 
    }
    return newArr;
}

int main() {
    int localArr[] = {5, 10, 15};
    int* heapArr = arrDupPointerMath(localArr, 3);
    
    for(int i = 0; i < 3; i++) printf("%d ", *(heapArr + i));
    
    delete[] heapArr; // Clean up
    return 0;
}