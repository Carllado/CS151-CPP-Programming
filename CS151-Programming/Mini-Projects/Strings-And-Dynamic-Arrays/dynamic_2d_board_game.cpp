// File: dynamic_2d_board_game.cpp
// Author: Carl Chu
// Date: 04/19/2026
// Purpose: true 2D array (pointer to pointers) for this program

#include <stdio.h>

// Translates ints to characters for "hidden" view
void show(int **board, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (board[r][c] == 0) printf(" - ");
            else if (board[r][c] == -1) printf(" X ");
            else if (board[r][c] < 0) printf(" @ ");
            else printf(" - "); // Positive values hidden as dash
        }
        printf("\n");
    }
}

// Translates ints to characters for "full" view
void reveal(int **board, int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int val = board[r][c];
            if (val == 0) printf(" - ");
            else if (val == -1) printf(" X ");
            else if (val >= 11 && val <= 15) printf(" %c ", 'a' + (val - 11));
            else if (val <= -11 && val >= -15) printf(" %c ", 'A' + ((-val) - 11));
            else printf(" ? "); // Fallback
        }
        printf("\n");
    }
}

int dig(int **board, int row, int col) {
    int val = board[row][col];
    if (val == 0) {
        board[row][col] = -1;
        return 1;
    } else if (val > 0) {
        board[row][col] = -val;
        return 1;
    }
    return 0; // Negative numbers: do nothing
}

int main() {
    int rows = 8, cols = 8;
    // Allocation on heap using pointers to pointers
    int **board = new int*[rows];
    for (int i = 0; i < rows; i++) board[i] = new int[cols];

    int data[8][8] = {
        {0, 0, -1, 0, 0, 0, 0, -14},
        {0, 11, 11, 11, 11, 11, -1, -14},
        {0, 0, 0, 0, 0, -1, 0, -14},
        {13, 0, -1, 0, 0, 0, 0, 0},
        {-13, -1, 0, -1, 12, 12, 12, 12},
        {13, 0, 0, 0, 0, 0, 0, 0},
        {0, -1, 0, 0, 0, 0, -1, 0},
        {0, 0, 15, 15, 0, 0, 0, 0}
    };

    for(int r=0; r<8; r++) for(int c=0; c<8; c++) board[r][c] = data[r][c];

    printf("--- Show View ---\n");
    show(board, rows, cols);
    printf("\n--- Reveal View ---\n");
    reveal(board, rows, cols);

    // Cleanup: deallocate row by row, then the pointer array
    for (int i = 0; i < rows; i++) delete[] board[i];
    delete[] board;

    return 0;
}
