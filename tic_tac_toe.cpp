#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

int main() {
    char player = 'X';
    int choice;
    int moves = 0;

    cout << "===== TIC TAC TOE GAME =====\n";

    while (moves < 9) {
        displayBoard();

        cout << "Player " << player;
        cout << ", enter position (1-9): ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice < 1 || choice > 9) {
            cout << "Please enter a number from 1 to 9.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {
            cout << "Position already occupied! Try again.\n";
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    displayBoard();
    cout << "Match Draw!\n";

    return 0;
}
