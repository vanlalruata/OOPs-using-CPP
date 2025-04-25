// Console-based Tic-Tac-Toe game for two players
#include <iostream>
#include <vector>
using namespace std;

// Function to display the current state of the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    cout << "     1   2   3\n";
    for (int i = 0; i < 3; ++i) {
        cout << "   -------------\n";
        cout << " " << i + 1 << " |";
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " |";
        }
        cout << "\n";
    }
    cout << "   -------------\n";
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

// Function to check if the board is full (draw)
bool isDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

// Function to get a valid move from the current player
void getPlayerMove(vector<vector<char>>& board, char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> row >> col;
        // Validate input: must be in range and cell must be empty
        if (cin.fail() || row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "Invalid input! Please enter numbers between 1 and 3.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        if (board[row - 1][col - 1] != ' ') {
            cout << "Cell already taken! Choose another.\n";
            continue;
        }
        board[row - 1][col - 1] = player;
        break;
    }
}

int main() {
    // Initialize the 3x3 board with spaces
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << "=== Tic-Tac-Toe Game ===\n";
    cout << "Player 1: X\nPlayer 2: O\n";

    // Main game loop
    while (!gameOver) {
        displayBoard(board);
        getPlayerMove(board, currentPlayer);

        // Check for win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            gameOver = true;
        }
        // Check for draw
        else if (isDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        }
        // Switch player
        else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    cout << "Game over. Thanks for playing!\n";
    return 0;
}



// === Tic-Tac-Toe Game ===
// Player 1: X
// Player 2: O

//      1   2   3
//    -------------
//  1 |   |   |   |
//    -------------
//  2 |   |   |   |
//    -------------
//  3 |   |   |   |
//    -------------
// Player X, enter your move (row and column): 1 1

//      1   2   3
//    -------------
//  1 | X |   |   |
//    -------------
//  2 |   |   |   |
//    -------------
//  3 |   |   |   |
//    -------------
// Player O, enter your move (row and column): 2 2
// ...
