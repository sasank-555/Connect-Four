//
// Created by Lenovo on 21-05-2025.
//
#include "Board.h"
using namespace std;
Board::Board() {

    for (int i = 0;i<ROWS;i++) {
        for (int j = 0; j<COLS ;j++) {
            grid[i][j] = '.';

        }
    }
}

void Board::print() const {
    for (int i=0;i<ROWS; i++) {
        for (int j=0;j<COLS;j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << "0 1 2 3 4 5 6\n";
}

int Board::makeMove(int col, char player) {
    if (!isValidMove(col)) return -1;
    for (int row = ROWS - 1; row >= 0; --row) {
        if (grid[row][col] == '.') {
            grid[row][col] = player;
            return row;
        }
    }
    return -1; // should never reach here if isValidMove is true
}




bool Board::checkDirection(int row, int col, int dRow, int dCol, char player) const {
    for (int i = 0; i < 4; ++i) {
        int r = row + i * dRow;
        int c = col + i * dCol;
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != player)
            return false;
    }
    return true;
}

bool Board::checkWin(char const player) const {
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            if (grid[row][col] != player) continue;
            // Check in all 4 directions
            if (checkDirection(row, col, 0, 1, player)) return true; // Horizontal →
            if (checkDirection(row, col, 1, 0, player)) return true; // Vertical ↓
            if (checkDirection(row, col, 1, 1, player)) return true; // Diagonal ↘
            if (checkDirection(row, col, 1, -1, player)) return true; // Diagonal ↙
        }
    }
    return false;
}

bool Board::isValidMove(int col) const {
    return col >= 0 && col < COLS && grid[0][col] == '.';
}

void Board::undoMove(int col, int row) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        grid[row][col] = '.';
    }
}



bool Board::isFull() const {
    for (int col = 0; col < COLS; ++col) {
        if (grid[0][col] == '.') return false;
    }
    return true;
}
