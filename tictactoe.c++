#include <iostream>

void display_board(char board[3][3]) {
    std::cout << "---------TIC TAC TOE----------\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2) {
                std::cout << "|";
            }
        }
        if (i < 2) {
            std::cout << "\n-----------\n";
        }
    }
    std::cout << "\n\n";
}

int check_winner(char board[3][3], char player) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            display_board(board);
            if (player == 'X') {
                std::cout << "Player 1 is the winner!" << std::endl;
            } else {
                std::cout << "Player 2 is the winner!" << std::endl;
            }
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            display_board(board);
            if (player == 'X') {
                std::cout << "Player 1 is the winner!" << std::endl;
            } else {
                std::cout << "Player 2 is the winner!" << std::endl;
            }
            return 1;
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        display_board(board);
        if (player == 'X') {
            std::cout << "Player 1 is the winner!" << std::endl;
        } else {
            std::cout << "Player 2 is the winner!" << std::endl;
        }
        return 1;
    }

    return 0;
}

int main() {
    char board[3][3]; 
    std::cout << "\n\nNOTE: In the game board, the rows and columns are numbered from 1 to 3.\n";
    std::cout << "For example, row 1 and column 1 indicate the top-left cell, and row 3 and column 3 indicate the bottom-right cell.\n";
    std::cout << "GOOD LUCK\n\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }

    int currentPlayer = 1;
    int row, col;
    int moves = 0;  // Track the number of moves
    char newGameChoice;

    do {
        while (true) {
            display_board(board);

            std::cout << "Player " << currentPlayer << ", enter your move (row(1-3) and column(1-3)): ";
            std::cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }

            if (currentPlayer == 1) {
                board[row - 1][col - 1] = 'X';
            } else {
                board[row - 1][col - 1] = 'O';
            }

            moves++;

            if (check_winner(board, 'X') || check_winner(board, 'O')) {
                break;
            } else if (moves == 9) {
                display_board(board);
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            currentPlayer = (currentPlayer == 1) ? 2 : 1;  // Switch players
        }

        std::cout << "\nDo you want to start a new game? (Y/N): ";
        std::cin >> newGameChoice;

        if (newGameChoice == 'Y' || newGameChoice == 'y') {
            // Reset the game board and variables for a new game
            moves = 0;
            currentPlayer = 1;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    board[i][j] = ' ';
                }
            }
        } else {
            break;  // Exit the loop if the player chooses not to start a new game
        }
    } while (true);

    return 0;
}
