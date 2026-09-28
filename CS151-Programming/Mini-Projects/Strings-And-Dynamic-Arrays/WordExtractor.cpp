/*
File: Assignment 10: Q3.cpp
Author: Carl Chu
Date: 05/16/2026
Purpose: This program reads a file, prints the first word of every line to the console, and stores the rest of the line into a vector.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

// Function to remove the first word and store the rest
void processFileLines(string filename, vector<string> &remainderVector) {
    ifstream in_file_stream(filename.c_str()); // Opens file using c_str()

    if (!in_file_stream) {
        cout << "Error: Could not open " << filename << endl;
        return;
    }

    string firstWord;
    string restOfLine;

    // to get the first word, then getline for the rest
    while (in_file_stream >> firstWord) {
        // Requirement: Print the first word
        cout << "Extracted first word: " << firstWord << endl;

        // Requirement: Store the remaining words in the vector
        std::getline(in_file_stream, restOfLine);
        remainderVector.push_back(restOfLine);
    }

    in_file_stream.close(); // Close file stream
}

int main() {
    vector<string> myData;
    processFileLines("input.txt", myData);

    cout << "\nRemaining content stored in vector:" << endl;
    for (vector<string>::iterator it = myData.begin(); it != myData.end(); it++) {
        cout << "Stored: " << *it << endl;
    }

    return 0;
}