// File: string_concat_comparison.cpp
// Author: Carl Chu
// Date: 04/19/2026
// Purpose: Manual memory allocation on the heap to ensure the new string survives after the function ends.

#include <stdio.h>
#include <string>

// Manual Heap
char* concatCStyle(const char* s1, const char* s2) {
    int len1 = 0;
    while(s1[len1] != '\0') len1++;
    int len2 = 0;
    while(s2[len2] != '\0') len2++;

    // Allocate on heap: len1 + len2 + 1 for null terminator
    char* result = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; i++) result[i] = s1[i];
    for (int j = 0; j < len2; j++) result[len1 + j] = s2[j];
    
    result[len1 + len2] = '\0'; 
    return result;
}

// C++ style concatenation (Using string class)
std::string concatCppStyle(std::string s1, std::string s2) {
    return s1 + s2;
}

int main() {
    char* cRes = concatCStyle("Hello ", "C-Style");
    printf("C-Style: %s\n", cRes);
    delete[] cRes; // Prevent memory leak

    std::string cppRes = concatCppStyle("Hello ", "C++ Style");
    printf("C++ Style: %s\n", cppRes.c_str());
    return 0;
}
