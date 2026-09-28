// File: custom_strlen.cpp
// Author: Carl Chu
// Date: 04/19/2026
// Purpose: Iterates through the character array until it hits the null character

#include <stdio.h>

// Counts characters until '\0' is found.
//Does not modify the original array.

int myStrlen(const char *str) {
    int count = 0;
    // Iterate until the null character 
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int main() {
    const char *test = "Hello World";
    printf("String: %s\n", test);
    printf("My Strlen: %d\n", myStrlen(test));
    return 0;
}