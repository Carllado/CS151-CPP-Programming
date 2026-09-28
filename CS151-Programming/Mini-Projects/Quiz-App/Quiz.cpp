/*
File: Quiz.cpp
Author: Carl Chu
Date: 05/30/2026
Purpose: Loops through the JSON results array to populate the vector.
*/

#include "Quiz.hpp"
#include <fstream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

Quiz::Quiz(std::string filename) {
    std::ifstream in_stream(filename);
    if (in_stream.is_open()) {
        json j;
        in_stream >> j;
        if (j.contains("results")) {
            for (auto& item : j["results"]) {
                questions.push_back(Question(item));
            }
        }
    }
}

void Quiz::print_all_questions() {
    for (auto& q : questions) {
        q.print_question();
    }
}