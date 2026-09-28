// File: StandardDeviation.cpp
// Author: Carl Chu
// Date: 05/03/2026
// Purpose: The mathematical steps for getting Standard Deviation

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For pow, sqrt, fabs

int main(int argc, char **argv) {
    printf("main start\n");
    int count = 0;
    char *typeOfNum; 

    if (argc == 3) {
        count = atoi(argv[1]);
        typeOfNum = argv[2];
    } else {
        printf("Usage: ./stddev <count> <type: i or f>\n");
        return 1;
    }

    // Allocate memory on the heap using malloc
    void *grades;
    if (*typeOfNum == 'i') {
        grades = malloc(count * sizeof(int));
    } else {
        grades = malloc(count * sizeof(float));
    }

    // Read grades from the user
    for (int numGradesRead = 0; numGradesRead < count; numGradesRead++) {
        int userInputInt = 0;
        float userInputFloat = 0.0;
        printf("Please enter grade %d: \n", numGradesRead + 1);
        int status = -1;
        
        while (status != 1) {
            if (*typeOfNum == 'i') {
                status = scanf("%d", &userInputInt);
            } else {
                status = scanf("%f", &userInputFloat);
            }
            
            if (status != 1) {
                printf("Invalid input. Please enter a valid number: \n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {} // Clear buffer
            }
        }

        // Apply fabs() to ensure positive grades, per requirements
        if (*typeOfNum == 'i') {
            userInputInt = (int)fabs((double)userInputInt);
            (static_cast<int *>(grades))[numGradesRead] = userInputInt;
        } else {
            userInputFloat = (float)fabs((double)userInputFloat);
            (static_cast<float *>(grades))[numGradesRead] = userInputFloat;
        }
    }
    
    // Calculate the Mean
    float sum = 0.0;
    for (int x = 0; x < count; x++) {
        if (*typeOfNum == 'i') {
            sum += (static_cast<int *>(grades)[x]);
        } else {
            sum += (static_cast<float *>(grades)[x]);
        }
    }
    float mean = sum / count;

    // Calculate Squared Differences and Variance
    float sqDiffSum = 0.0;
    for (int x = 0; x < count; x++) {
        float diff = 0.0;
        if (*typeOfNum == 'i') {
            diff = (static_cast<int *>(grades)[x]) - mean;
        } else {
            diff = (static_cast<float *>(grades)[x]) - mean;
        }
        sqDiffSum += pow(diff, 2.0); // Using pow() from math.h
    }
    float variance = sqDiffSum / count;

    // Calculate Standard Deviation
    float stddev = sqrt(variance); // Using sqrt() from math.h

    printf("\nThe standard deviation of the grades is: %f\n", stddev);

    // Free up malloc'd memory
    free(grades);
    return 0;
}