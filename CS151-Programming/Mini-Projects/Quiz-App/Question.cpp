/*
File: Question.cpp
Author: Carl Chu
Date: 05/30/2026
Purpose: Implementation of the parsing logic. It extracts data directly from JSON keys using the library's syntax.
*/

#include "Question.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

Question::Question() {}

Question::Question(json j) {
    category = j["category"].get<std::string>();
    type = j["type"].get<std::string>();
    difficulty = j["difficulty"].get<std::string>();
    question = j["question"].get<std::string>();
    correct_answer = j["correct_answer"].get<std::string>();
    
    incorrect_answers.clear();
    for (auto& ans : j["incorrect_answers"]) {
        incorrect_answers.push_back(ans.get<std::string>());
    }
}

Question::Question(std::string filename) {
    std::ifstream in_stream(filename);
    if (in_stream.is_open()) {
        json j;
        in_stream >> j;
        if (j.contains("results") && !j["results"].empty()) {
            *this = Question(j["results"][0]);
        }
    }
}

void Question::print_question() {
    std::cout << "[" << category << " - " << difficulty << "]" << std::endl;
    std::cout << "Q: " << question << std::endl;
    std::cout << "A: " << correct_answer << std::endl;
    std::cout << "Incorrect options: ";
    for (size_t i = 0; i < incorrect_answers.size(); i++) {
        std::cout << incorrect_answers[i] << (i < incorrect_answers.size()-1 ? ", " : "");
    }
    std::cout << "\n" << std::string(30, '-') << std::endl;
}