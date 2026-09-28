/*
File: main.cpp
Author: Carl Chu
Date: 05/17/2026
Purpose: split into a header file for declarations, a .cpp file for definitions, a main.cpp for the client, and a Makefile.
*/


#include "pet.hpp"

int main() {
    // Instantiate a Pet object
    Pet myPet("Sparky", "Dog", 3);

    // Call the print method
    myPet.print();

    return 0;
}