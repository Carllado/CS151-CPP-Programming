/*
File: Assignment 10: Q4.cpp
Author: Carl Chu
Date: 05/16/2026
Purpose: Uses a vector iterator to calculate the count, minimum, maximum, and average of a set of integers.
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// Utility function to print stats using iostreams and iterators
void printVectorStats(vector<int> &vec) {
    // Safety check using vector.empty()
    if (vec.empty()) {
        cout << "Vector is empty. No stats available." << endl;
        return;
    }

    // Initialize tracking variables
    int min = vec[0];
    int max = vec[0];
    double sum = 0;

    // Requirement: Use an iterator to traverse the vector
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
        int currentVal = *iter; // Dereference to get value

        if (currentVal < min) min = currentVal;
        if (currentVal > max) max = currentVal;
        sum += currentVal;
    }

    // Calculate count using v.size()
    double average = sum / vec.size();

    // Output stats using iostreams
    cout << "--- Vector Statistics ---" << endl;
    cout << "Count:   " << vec.size() << endl;
    cout << "Min:     " << min << endl;
    cout << "Max:     " << max << endl;
    cout << "Average: " << average << endl;
}

int main() {
    // Create a vector with test values
    vector<int> testNumbers;
    testNumbers.push_back(10);
    testNumbers.push_back(20);
    testNumbers.push_back(5);
    testNumbers.push_back(15);

    printVectorStats(testNumbers);

    return 0;
}