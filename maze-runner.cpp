#include <iostream>
using namespace std;

 int COLS = 7;
 int ROWS = 7;

int main() {
    char maze[ROWS][COLS] = {
        {'.', '.', 'X', '.', '.', '.', '.'},
        {'.', '.', '.', '.', 'X', '.', 'X'},
        {'.', '.', 'X', 'X', 'X', '.', '.'},
        {'X', '.', '.', 'X', '.', '.', '.'},
        {'.', 'X', '.', 'X', '.', 'X', '.'},
        {'.', '.', '.', '.', 'X', '.', '.'},
        {'S', 'X', 'X', 'X', 'X', 'X', 'E'}
    };

    int playerRow = 6;
    int playerCol = 0;
    char move;

    while (true) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (i == playerRow && j == playerCol) {
                    cout << 'P' << " ";
                } else {
                    cout << maze[i][j] << " ";
                }
            }
            cout << endl;
        }

        cout << "\n Enter a move (W/A/S/D to move, Q to quit): ";
        cin >> move;

        switch (move) {
            case 'W':
            case 'w':
                if (playerRow > 0) {
                    if (maze[playerRow - 1][playerCol] != 'X') {
                        playerRow--;
                    } else {
                        cout << "\n Ouch! You hit a wall. Try a different direction." << endl;
                    }
                }
                break;
            case 'S':
            case 's':
                if (playerRow < ROWS - 1) {
                    if (maze[playerRow + 1][playerCol] != 'X') {
                        playerRow++;
                    } else {
                        cout << "\n Ouch! You hit a wall. Try a different direction." << endl;
                    }
                }
                break;
            case 'A':
            case 'a':
                if (playerCol > 0) {
                    if (maze[playerRow][playerCol - 1] != 'X') {
                        playerCol--;
                    } else {
                        cout << "\n Ouch! You hit a wall. Try a different direction." << endl;
                    }
                }
                break;
            case 'D':
            case 'd':
                if (playerCol < COLS - 1) {
                    if (maze[playerRow][playerCol + 1] != 'X') {
                        playerCol++;
                    } else {
                        cout << "\n Ouch! You hit a wall. Try a different direction." << endl;
                    }
                }
                break;
            case 'Q':
            case 'q':
                cout << "\nQuitting the game. Goodbye!" << endl;
                return 0;
            default:
                cout << "\n Invalid move. Please enter W/A/S/D to move or Q to quit." << endl;
        }

        if (maze[playerRow][playerCol] == 'E') {
            cout << "\n\n Congratulations! You reached the end. Game Over!" << endl;
            cout << "Wanna Start Again?";
            return 0;
        }
    }

    return 0;
}
