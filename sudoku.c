#include <stdio.h>
#include <stdbool.h>
#define size 9

void printGrid(int grid[size][size]) {
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            printf("%d", grid[row][col]);
        }
        printf("\n");
    }
}
bool isSafe(int grid[size][size], int row, int col, int num) {

    for(int x = 0; x < size; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[size][size]) {
    int row, col;
    bool isEmpty = false;
    for (row=0; row < size; row++) {
        for(col = 0; col < size; col ++) {
            if(grid[row][col]==0) {
                isEmpty = true;
                break;
            }
        }
        if(isEmpty) {
            break;
        }
    }

    if(!isEmpty) {
        return true;
    }

    for (int num = 1; num <= size; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if(solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
}

int main() {
    int grid[size][size] = { 
    {5, 3, 0, 0, 7, 0, 0, 0, 0}, 
    {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
    {0, 9, 8, 0, 0, 0, 0, 6, 0}, 
    {8, 0, 0, 0, 6, 0, 0, 0, 3}, 
    {4, 0, 0, 8, 0, 3, 0, 0, 1}, 
    {7, 0, 0, 0, 2, 0, 0, 0, 6}, 
    {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
    {0, 0, 0, 4, 1, 9, 0, 0, 5}, 
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if(solveSudoku(grid)) {
        printGrid(grid);
    } 
}
