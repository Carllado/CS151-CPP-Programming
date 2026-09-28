/*
File: Question.hpp
Author: Carl Chu
Date: 05/30/2026
Purpose: Defines the structure of a single trivia question. 
*/

#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string>
#include <vector>
#include "nlohmann/json.hpp"

class Question {
public:
    std::string category;
    std::string type;
    std::string difficulty;
    std::string question;
    std::string correct_answer;
    std::vector<std::string> incorrect_answers;

    Question();
    explicit Question(nlohmann::json j_fragment);
    explicit Question(std::string filename);

    void print_question();
};

#endif