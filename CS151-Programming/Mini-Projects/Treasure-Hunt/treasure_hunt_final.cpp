/*
File: treasure_hunt_final.cpp
Author: Carl Chu
Date: 05/10/2026
Purpose: A 2D game where a Human and AI player hide and hunt for treasure.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Constants (Avoids "Magic Numbers")
const int kRows = 10;
const int kCols = 10;
const int kDirt = 0;
const int kHole = -1;

// Treasure Codes: Bronze(11), Silver(12), Gold(13), Rubies(14), Vibranium(15)
const int kChestBase = 11;

//  creates a 10x10 grid on the Heap.
// Uses a pointer-to-pointer structure 

int** allocateBoard() {
    int **board = new int*[kRows];
    for (int i = 0; i < kRows; i++) {
        board[i] = new int[kCols];
        for (int j = 0; j < kCols; j++) {
            board[i][j] = kDirt; // Initialize to dirt
        }
    }
    return board;
}


// Deletes the heap memory in reverse order of allocation.

void freeBoard(int **board) {
    for (int i = 0; i < kRows; i++) {
        delete[] board[i];
    }
    delete[] board;
}

// Validates if a chest of 'length' fits at (r, c) without 
// going out of bounds or overlapping existing items.

bool checkPlacement(const int* const* board, int r, int c, int length, bool isHoriz) {
    if (isHoriz) {
        if (c < 0 || c + length > kCols || r < 0 || r >= kRows) return false;
    } else {
        if (r < 0 || r + length > kRows || c < 0 || c >= kCols) return false;
    }

    // Overlap Check
    for (int i = 0; i < length; i++) {
        int curR = isHoriz ? r : r + i;
        int curC = isHoriz ? c + i : c;
        if (board[curR][curC] != kDirt) return false;
    }
    return true;
}

// Writes the chest code into the board cells.

void placeChest(int **board, int r, int c, int length, int code, bool isHoriz) {
    for (int i = 0; i < length; i++) {
        int curR = isHoriz ? r : r + i;
        int curC = isHoriz ? c + i : c;
        board[curR][curC] = code;
    }
}

// Checks if a specific chest code (11-15) still exists anywhere.
// If not found, the chest has been completely unearthed.

bool isChestSunk(const int* const* board, int code) {
    for (int r = 0; r < kRows; r++) {
        for (int c = 0; c < kCols; c++) {
            if (board[r][c] == code) return false; 
        }
    }
    return true;
}

// Marks a cell. If a positive number is hit, it's flipped to negative.
// Returns true if a treasure was found.

bool dig(int **board, int r, int c) {
    if (r < 0 || r >= kRows || c < 0 || c >= kCols) return false;

    if (board[r][c] > 0) {
        int code = board[r][c];
        board[r][c] = -code; 
        if (isChestSunk(board, code)) {
            printf("You unearthed a full treasure chest (Type %d)!\n", code);
        }
        return true;
    } else if (board[r][c] == kDirt) {
        board[r][c] = kHole;
    }
    return false;
}


// Checks if any positive treasure values remain on the board.

bool allFound(const int* const* board) {
    for (int r = 0; r < kRows; r++) {
        for (int c = 0; c < kCols; c++) {
            if (board[r][c] >= kChestBase) return false;
        }
    }
    return true;
}

// isOpponent=true hides treasure. isOpponent=false shows all.
// Maps: 0->-, -1->X, 11->a, -11->A or @

void printBoard(const int* const* board, bool isOpponent) {
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (int r = 0; r < kRows; r++) {
        printf("%d ", r);
        for (int c = 0; c < kCols; c++) {
            int val = board[r][c];
            if (val == kDirt) printf(" -");
            else if (val == kHole) printf(" X");
            else if (val >= kChestBase) {
                // If it's the opponent, keep it hidden as dirt
                if (isOpponent) printf(" -"); 
                else printf(" %c", 'a' + (val - kChestBase)); // Map 11->'a', 12->'b', etc.
            } else if (val <= -kChestBase) {
                // If hit, human sees capital letter, opponent sees @
                if (isOpponent) printf(" @");
                else printf(" %c", 'A' + ((-val) - kChestBase));
            }
        }
        printf("\n");
    }
}


void humanPlacement(int **board) {
    int sizes[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        bool placed = false;
        while (!placed) {
            int r, c, h;
            printf("\nYour Board:\n");
            printBoard(board, false);
            printf("Place Chest #%d (Size %d). Enter Row Col Horiz(1=Yes, 0=No): ", i+1, sizes[i]);
            
            if (scanf("%d %d %d", &r, &c, &h) != 3) {
                // Clear buffer on invalid input
                int ch; while ((ch = getchar()) != '\n' && ch != EOF);
                continue;
            }
            
            if (checkPlacement(board, r, c, sizes[i], h == 1)) {
                placeChest(board, r, c, sizes[i], kChestBase + i, h == 1);
                placed = true;
            } else {
                printf("Error: Invalid location. Try again.\n");
            }
        }
    }
}

void aiPlacement(int **board) {
    int sizes[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        bool placed = false;
        while (!placed) {
            int r = rand() % kRows;
            int c = rand() % kCols;
            int h = rand() % 2;
            if (checkPlacement(board, r, c, sizes[i], h == 1)) {
                placeChest(board, r, c, sizes[i], kChestBase + i, h == 1);
                placed = true;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int **hBoard = allocateBoard();
    int **cBoard = allocateBoard();

    printf("Welcome to TREASURE HUNT Project 2\n");
    humanPlacement(hBoard);
    aiPlacement(cBoard);

    while (true) {
        // Human Turn
        printf("\nOPPONENT'S GARDEN:\n");
        printBoard(cBoard, true);
        int r, c;
        printf("Enter coordinate to dig (Row Col): ");
        if (scanf("%d %d", &r, &c) == 2) {
            if (dig(cBoard, r, c)) printf("--- HIT! ---\n");
            else printf("--- Miss. ---\n");
        }

        if (allFound(cBoard)) {
            printf("\nVICTORY! You found all the AI's treasure!\n");
            break;
        }

        // AI Turn
        int ar = rand() % kRows;
        int ac = rand() % kCols;
        if (dig(hBoard, ar, ac)) printf("AI HIT your garden at %d %d!\n", ar, ac);

        if (allFound(hBoard)) {
            printf("\nDEFEAT. The AI cleared your garden first.\n");
            break;
        }
    }

    freeBoard(hBoard);
    freeBoard(cBoard);
    return 0;
}