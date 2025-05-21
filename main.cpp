#include <iostream>
#include "./src/Board.h"
#include "./src/ai_board.cpp"

using namespace std;

int main() {
    char humanPlayer, robotPlayer;
    int temp;

    cout << "Welcome to Connect Four!\n";
    cout << "Which color would you like to play? (1 for Red 'R', 2 for Blue 'B'): ";
    cin >> temp;

    if (temp == 1) {
        humanPlayer = 'R';
        robotPlayer = 'B';
    } else {
        humanPlayer = 'B';
        robotPlayer = 'R';
    }

    Robot game(10, robotPlayer, humanPlayer);

    cout << "You are '" << humanPlayer << "'. AI is '" << robotPlayer << "'.\n";
    game.print();

    while (true) {
        int humanMove;
        cout << "Your move (0-6): ";
        cin >> humanMove;

        if (!game.isValidMove(humanMove)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        game.makeMove(humanMove, humanPlayer);
        game.print();

        if (game.checkWin(humanPlayer)) {
            cout << "Congratulations! You won!\n";
            break;
        }
        if (game.isFull()) {
            cout << "It's a draw!\n";
            break;
        }

        cout << "AI is thinking...\n";
        int aiMove = game.getBestMove();
        game.makeMove(aiMove, robotPlayer);
        cout << "AI plays column " << aiMove << "\n";
        game.print();

        if (game.checkWin(robotPlayer)) {
            cout << "AI wins! Better luck next time.\n";
            break;
        }
        if (game.isFull()) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
