/*
File: Quiz.hpp
Author: Carl Chu
Date: 05/30/2026
Purpose: Manages a vector of Question objects.
*/

#ifndef QUIZ_HPP
#define QUIZ_HPP

#include "Question.hpp"
#include <vector>
#include <string>

class Quiz {
private:
    std::vector<Question> questions;

public:
    Quiz(std::string filename);
    void print_all_questions();
};

#endif
