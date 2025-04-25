// Console-based Snake and Ladder game for two players
#include <iostream>
#include <map>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()
using namespace std;

// Function to print the current positions of both players
void printPositions(int p1, int p2) {
    cout << "----------------------------------\n";
    cout << "Player 1 is at position: " << p1 << endl;
    cout << "Player 2 is at position: " << p2 << endl;
    cout << "----------------------------------\n";
}

// Function to initialize the snakes and ladders on the board
void initializeBoard(map<int, int>& snakes, map<int, int>& ladders) {
    // Snakes: key = head, value = tail
    snakes[99] = 7;
    snakes[95] = 75;
    snakes[92] = 35;
    snakes[89] = 53;
    snakes[74] = 41;
    snakes[64] = 60;
    snakes[62] = 19;
    snakes[49] = 11;
    snakes[46] = 25;
    snakes[16] = 6;

    // Ladders: key = bottom, value = top
    ladders[2] = 38;
    ladders[7] = 14;
    ladders[8] = 31;
    ladders[15] = 26;
    ladders[21] = 42;
    ladders[28] = 84;
    ladders[36] = 44;
    ladders[51] = 67;
    ladders[71] = 91;
    ladders[78] = 98;
    ladders[87] = 94;
}

// Function to simulate dice roll (returns a number between 1 and 6)
int rollDice() {
    return (rand() % 6) + 1;
}

// Function to move a player and handle snakes and ladders
int movePlayer(int currentPos, int dice, const map<int, int>& snakes, const map<int, int>& ladders) {
    int nextPos = currentPos + dice;
    if (nextPos > 100) {
        cout << "Roll exceeds 100. Stay at position " << currentPos << ".\n";
        return currentPos;
    }
    cout << "Moved to position " << nextPos << ".\n";
    // Check for ladder
    if (ladders.count(nextPos)) {
        cout << "Yay! Landed on a ladder! Climb up to " << ladders.at(nextPos) << ".\n";
        nextPos = ladders.at(nextPos);
    }
    // Check for snake
    else if (snakes.count(nextPos)) {
        cout << "Oops! Bitten by a snake! Slide down to " << snakes.at(nextPos) << ".\n";
        nextPos = snakes.at(nextPos);
    }
    return nextPos;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    map<int, int> snakes, ladders;
    initializeBoard(snakes, ladders);

    int player1 = 0, player2 = 0; // Start positions
    bool gameOver = false;
    int turn = 1; // 1 for player1, 2 for player2

    cout << "=== Welcome to Snake and Ladder! ===\n";
    cout << "First to reach exactly 100 wins.\n";
    cout << "Press Enter to roll the dice on your turn.\n";

    while (!gameOver) {
        printPositions(player1, player2);

        if (turn == 1) {
            cout << "Player 1's turn. Press Enter to roll the dice...";
            cin.ignore();
            int dice = rollDice();
            cout << "Player 1 rolled a " << dice << ".\n";
            player1 = movePlayer(player1, dice, snakes, ladders);
            if (player1 == 100) {
                cout << "Player 1 wins! Congratulations!\n";
                gameOver = true;
            }
            turn = 2; // Switch turn
        } else {
            cout << "Player 2's turn. Press Enter to roll the dice...";
            cin.ignore();
            int dice = rollDice();
            cout << "Player 2 rolled a " << dice << ".\n";
            player2 = movePlayer(player2, dice, snakes, ladders);
            if (player2 == 100) {
                cout << "Player 2 wins! Congratulations!\n";
                gameOver = true;
            }
            turn = 1; // Switch turn
        }
    }

    cout << "Game over. Thanks for playing!\n";
    return 0;
}



// === Welcome to Snake and Ladder ===
// First to reach exactly 100 wins.
// Press Enter to roll the dice on your turn.
// ----------------------------------
// Player 1 is at position: 0
// Player 2 is at position: 0
// ----------------------------------
// Player 1's turn. Press Enter to roll the dice...
// Player 1 rolled a 4.
// Moved to position 4.
// ----------------------------------
// Player 1 is at position: 4
// Player 2 is at position: 0
// ----------------------------------
// Player 2's turn. Press Enter to roll the dice...
// Player 2 rolled a 6.
// Moved to position 6.
// Yay! Landed on a ladder! Climb up to 14.
// ...
