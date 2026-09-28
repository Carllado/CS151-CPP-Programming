// File: heap_array_duplication.cpp
// Author: Carl Chu
// Date: 04/18/2026
//Purpose: Use the new keyword to put data on the Heap

#include <stdio.h>

int* arrDup(int* source, int length) {
    // Create new array on the heap
    int* newArr = new int[length]; 
    
    for (int i = 0; i < length; i++) {
        newArr[i] = source[i]; 
    }
    return newArr;
}

int main() {
    int localArr[] = {10, 20, 30};
    int* heapArr = arrDup(localArr, 3);

    for(int i = 0; i < 3; i++) printf("%d ", heapArr[i]);
    
    delete[] heapArr; // Free heap memory
    return 0;
}