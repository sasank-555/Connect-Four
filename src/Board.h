//
// Created by Lenovo on 21-05-2025.
//
#ifndef BOARD_H
#define BOARD_H

#include <bits/stdc++.h>
using namespace  std;
class Board {
public:
    static const int ROWS = 6;
    static const int COLS = 7;

    Board();
    void print() const;
    int makeMove(int col, char player);  // player: 'R' or 'B'
    void undoMove(int row, int col);
    bool isValidMove(int col) const;
    bool checkWin(char player) const;
    bool isFull() const;

private:
    char grid[ROWS][COLS];
    bool checkDirection(int row, int col, int dRow, int dCol, char player) const;
};

#endif // BOARD_H
