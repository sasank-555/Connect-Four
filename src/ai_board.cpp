#include "Board.h"
#include <limits>

class Robot : public Board {
public:
    int maxi;
    char aiPlayer;
    char humanPlayer;

    Robot(int maxi, char aiPlayer, char humanPlayer) {
        this->maxi = maxi;
        this->aiPlayer = aiPlayer;
        this->humanPlayer = humanPlayer;
    }

    int getBestMove() {
        int bestScore = std::numeric_limits<int>::min();
        int bestCol = -1;

        for (int col = 0; col < COLS; ++col) {
            if (!isValidMove(col)) continue;

            Robot temp = *this;
            temp.makeMove(col, aiPlayer);
            int score = temp.minimax(maxi - 1, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false);

            if (score > bestScore) {
                bestScore = score;
                bestCol = col;
            }
        }
        return bestCol;
    }

    bool isTerminal() const {
        return checkWin(aiPlayer) || checkWin(humanPlayer) || isFull();
    }

    int evaluateBoard() const {
        if (checkWin(aiPlayer)) return 1000000;
        if (checkWin(humanPlayer)) return -1000000;
        return 0;
    }

    int minimax(int depth, int alpha, int beta, bool maximizingPlayer) {
        if (depth == 0 || isTerminal()) {
            return evaluateBoard();
        }

        if (maximizingPlayer) {
            int maxEval = std::numeric_limits<int>::min();
            for (int col = 0; col < COLS; ++col) {
                if (!isValidMove(col)) continue;
                Robot temp = *this;
                temp.makeMove(col, aiPlayer);
                int eval = temp.minimax(depth - 1, alpha, beta, false);
                maxEval = std::max(maxEval, eval);
                alpha = std::max(alpha, eval);
                if (beta <= alpha) break; // Beta cut-off
            }
            return maxEval;
        } else {
            int minEval = std::numeric_limits<int>::max();
            for (int col = 0; col < COLS; ++col) {
                if (!isValidMove(col)) continue;
                Robot temp = *this;
                temp.makeMove(col, humanPlayer);
                int eval = temp.minimax(depth - 1, alpha, beta, true);
                minEval = std::min(minEval, eval);
                beta = std::min(beta, eval);
                if (beta <= alpha) break; // Alpha cut-off
            }
            return minEval;
        }
    }
};

