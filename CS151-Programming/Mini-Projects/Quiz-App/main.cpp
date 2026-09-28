/*
File: main.cpp
Author: Carl Chu
Date: 05/30/2026
Purpose: The upgraded entry point using system("curl ...") and a user loop
*/

#include <iostream>
#include <string>
#include "Quiz.hpp"
#include <cstdlib> // This is the standard C++ library for the system() command

int main() {
    char userChoice;

    do {
        std::cout << "\n--- Fetching New Questions from the Internet ---" << std::endl;

        // Obtain json data from the internet and save to quiz.data
        system("curl https://opentdb.com/api.php?amount=10 > quiz.data");

        // Create Quiz object from the downloaded data
        Quiz myQuiz("quiz.data");
        myQuiz.print_all_questions();

        std::cout << "\nWould you like to retrieve and display more questions? (y/n): ";
        std::cin >> userChoice;

    } while (userChoice == 'y' || userChoice == 'Y');

    std::cout << "Goodbye!" << std::endl;
    return 0;
}