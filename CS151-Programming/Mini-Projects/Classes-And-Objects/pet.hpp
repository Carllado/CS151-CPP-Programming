/*
File: pet.hpp
Author: Carl Chu
Date: 05/17/2026
Purpose: split into a header file for declarations, a .cpp file for definitions, a main.cpp for the client, and a Makefile.
*/


#ifndef PET_HPP
#define PET_HPP

#include <string>

class Pet {
public:
    // Class variables
    std::string name;
    std::string species;
    int age;

    // Constructors
    Pet(); // Default
    Pet(std::string n, std::string s, int a); // Parameterized

    // Method to output info
    void print();
};

#endif