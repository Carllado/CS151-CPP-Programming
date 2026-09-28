/*
File: pet.cpp
Author: Carl Chu
Date: 05/17/2026
Purpose: split into a header file for declarations, a .cpp file for definitions, a main.cpp for the client, and a Makefile.
*/


#include "pet.hpp"
#include <iostream>

// Default constructor
Pet::Pet() {
    name = "Unnamed";
    species = "Unknown";
    age = 0;
}

// Parameterized constructor
Pet::Pet(std::string n, std::string s, int a) {
    name = n;
    species = s;
    age = a;
}

// Print method definition
void Pet::print() {
    std::cout << "Pet Name: " << name << ", Species: " << species 
              << ", Age: " << age << std::endl;
}